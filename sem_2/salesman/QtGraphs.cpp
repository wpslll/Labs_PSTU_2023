#include "QtGraphs.h"
#include <QPainter>
#include <QPushButton>
#include <cmath>
#include <QTimer>
#include <queue>
#include <limits>
#include<QInputDialog>
#include <QMessageBox>

void Graph::addNode(int data)
{
    if (nodes_map.find(data) == nodes_map.end())
    {
        Node* newNode = new Node;
        newNode->data = data;
        nodes_map[data] = newNode;
    }
}

void Graph::addEdge(int fromData, int toData, int weight)
{
    Node* fromNode = nodes_map[fromData];
    Node* toNode = nodes_map[toData];

    if (!fromNode || !toNode)
        return;

    for (Edge* edge : fromNode->edges_to_node)
    {
        if (edge->to == toNode)
        {
            return;
        }
    }

    Edge* newEdge = new Edge();
    newEdge->to = toNode;
    newEdge->weight = weight;
    fromNode->edges_to_node.push_back(newEdge);
}

void Graph::clearGraph()
{
    for (auto& pair : nodes_map)
    {
        delete pair.second;
    }
    nodes_map.clear();
}

void Graph::updateEdgeWeight(int startData, int endData, int newWeight)
{
    Node* startNode = nodes_map[startData];
    Node* endNode = nodes_map[endData];

    if (!startNode || !endNode)
        return;

    for (Edge* edge : startNode->edges_to_node)
    {
        if (edge->to == endNode)
        {
            edge->weight = newWeight;
            return;
        }
    }
}

void Graph::removeNode(int data)
{
    for (auto& pair : nodes_map)
    {
        Node* node = pair.second;
        std::vector<Edge*> edges_to_remove;

        for (Edge* edge : node->edges_to_node)
        {
            if (edge->to->data == data)
            {
                edges_to_remove.push_back(edge);
            }
        }

        for (Edge* edge : edges_to_remove)
        {
            node->edges_to_node.erase(std::remove(node->edges_to_node.begin(), node->edges_to_node.end(), edge), node->edges_to_node.end());
            delete edge;
        }
    }

    auto it = nodes_map.find(data);
    if (it != nodes_map.end())
    {
        delete it->second;
        nodes_map.erase(it);
    }
}

void Graph::removeEdge(int startData, int endData)
{
    Node* startNode = nodes_map[startData];
    Node* endNode = nodes_map[endData];

    if (!startNode || !endNode)
        return;

    Edge* edgeToRemove = nullptr;
    for (Edge* edge : startNode->edges_to_node)
    {
        if (edge->to->data == endData)
        {
            edgeToRemove = edge;
            break;
        }
    }

    if (edgeToRemove)
    {
        startNode->edges_to_node.erase(std::remove(startNode->edges_to_node.begin(), startNode->edges_to_node.end(), edgeToRemove), startNode->edges_to_node.end());
        delete edgeToRemove;
    }
}

std::vector<int> Graph::solveTSP(int startNodeData)
{
    if (nodes_map.find(startNodeData) == nodes_map.end() || nodes_map.size() < 2)
    {
        return {};
    }

    int bestCost = std::numeric_limits<int>::max();
    std::vector<int> bestPath;
    std::unordered_set<int> visited;
    std::vector<int> currentPath;

    visited.insert(startNodeData);
    currentPath.push_back(startNodeData);

    tspHelper(startNodeData, visited, currentPath, 0, bestCost, bestPath, startNodeData);

    if (!bestPath.empty()) {
        bestPath.push_back(startNodeData);
    }

    return bestPath;
}

void Graph::tspHelper(int currentNodeData, std::unordered_set<int>& visited, std::vector<int>& currentPath, int currentCost, int& bestCost, std::vector<int>& bestPath, int startNodeData)
{
    if (visited.size() == nodes_map.size())
    {
        for (Edge* edge : nodes_map[currentNodeData]->edges_to_node)
        {
            if (edge->to->data == startNodeData)
            {
                int totalCost = currentCost + edge->weight;
                if (totalCost < bestCost)
                {
                    bestCost = totalCost;
                    bestPath = currentPath;
                }
                break;
            }
        }
        return;
    }

    Node* currentNode = nodes_map[currentNodeData];
    for (Edge* edge : currentNode->edges_to_node)
    {
        if (visited.find(edge->to->data) == visited.end())
        {
            visited.insert(edge->to->data);
            currentPath.push_back(edge->to->data);
            tspHelper(edge->to->data, visited, currentPath, currentCost + edge->weight, bestCost, bestPath, startNodeData);
            visited.erase(edge->to->data);
            currentPath.pop_back();
        }
    }
}

// --- QtGraphs Class Implementation ---

QtGraphs::QtGraphs(QWidget* parent)
    : QMainWindow(parent), m_selectedNode(nullptr), m_nodeSelected(false), sel(false), sNode(nullptr)
{
    ui.setupUi(this);


}

QtGraphs::~QtGraphs()
{
}

void QtGraphs::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QFont font = painter.font();
    font.setPointSize(16);
    painter.setFont(font);
    painter.setPen(QPen(Qt::black, 2));

    for (const auto& pair : graph.nodes_map) {
        Node* node = pair.second;

        for (Edge* edge : node->edges_to_node) {
            QPoint pos_f;
            QPoint pos_t;
            double angle = atan2(-(edge->to->pos.y() - node->pos.y()), (edge->to->pos.x() - node->pos.x()));
            pos_f = QPoint(node->pos.x() + 20 * cos(angle), node->pos.y() - 20 * sin(angle));
            pos_t = QPoint(edge->to->pos.x() - 20 * cos(angle), edge->to->pos.y() + 20 * sin(angle));
            painter.drawLine(pos_f, pos_t);
            int x_t = pos_f.x() + 4 * (pos_t.x() - pos_f.x()) / 5;
            int y_t = pos_f.y() - 4 * (pos_f.y() - pos_t.y()) / 5;

            // Избегаем наложения весов рёбер на одном и том же ребре
            bool drawTextAbove = node->pos.y() > edge->to->pos.y();
            if (drawTextAbove) {
                painter.drawText(x_t - 10, y_t + 10, QString::number(edge->weight));
            } else {
                painter.drawText(x_t - 10, y_t - 10, QString::number(edge->weight));
            }
        }
    }

    // Отрисовка узлов
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::black, 2));
    for (const auto& pair : graph.nodes_map) {
        Node* node = pair.second;
        painter.drawEllipse(node->pos, 20, 20);
        painter.drawText(node->pos.x() - 9, node->pos.y() + 8, QString::number(node->data));
    }
}



void QtGraphs::mousePressEvent(QMouseEvent* event)
{
    for (auto& pair : graph.nodes_map)
    {
        Node* node = pair.second;
        QRect nodeRect(node->pos.x() - 30, node->pos.y() - 30, 60, 60);
        if (nodeRect.contains(event->pos()))
        {
            m_selectedNode = node;
            m_nodeSelected = true;
            if (event->button() == Qt::RightButton) {
                if (!sel) {
                    sNode = node;
                    sel = true;
                    sNode->highlighted = true;
                } else {
                    if (node != sNode) {
                        bool edgeExists = std::any_of(sNode->edges_to_node.begin(), sNode->edges_to_node.end(),
                                                     [node](Edge* edge) { return edge->to == node; });

                        if (!edgeExists) {
                            bool reverseEdgeExists = std::any_of(node->edges_to_node.begin(), node->edges_to_node.end(),
                                                                 [this](Edge* edge) { return edge->to == sNode; });
                            if (!reverseEdgeExists) {
                                int weight = QInputDialog::getInt(this, "Add Edge", "Enter edge weight:", 1);
                                graph.addEdge(sNode->data, node->data, weight);
                            }
                        }
                        sNode->highlighted = false;
                        sel = false;
                    }
                }
                update();
                break;
            }
        }
    }
}

void QtGraphs::mouseMoveEvent(QMouseEvent* event)
{
    if (m_nodeSelected)
    {
        m_selectedNode->pos = event->pos();
        update();
    }
}

void QtGraphs::mouseReleaseEvent(QMouseEvent* event)
{
    m_nodeSelected = false;
}

void QtGraphs::on_pushButton_AddNode_clicked()
{
    bool ok;
    int nodeData = QInputDialog::getInt(this, "Add Node", "Enter node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        graph.addNode(nodeData);
        update();
    }
}

void QtGraphs::on_pushButton_AddEdge_clicked()
{
    bool ok;
    int fromData = QInputDialog::getInt(this, "Add Edge", "Enter starting node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (!ok) return;
    int toData = QInputDialog::getInt(this, "Add Edge", "Enter ending node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (!ok) return;
    int weight = QInputDialog::getInt(this, "Add Edge", "Enter edge weight:", 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        graph.addEdge(fromData, toData, weight);
        update();
    }
}

void QtGraphs::on_pushButton_DeleteNode_clicked()
{
    bool ok;
    int nodeData = QInputDialog::getInt(this, "Delete Node", "Enter node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        graph.removeNode(nodeData);
        update();
    }
}

void QtGraphs::on_pushButton_DeleteEdge_clicked()
{
    bool ok;
    int startData = QInputDialog::getInt(this, "Delete Edge", "Enter starting node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (!ok) return;
    int endData = QInputDialog::getInt(this, "Delete Edge", "Enter ending node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        graph.removeEdge(startData, endData);
        update();
    }
}

void QtGraphs::on_pushButton_UpdateEdge_clicked()
{
    bool ok;
    int startData = QInputDialog::getInt(this, "Update Edge", "Enter starting node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (!ok) return;
    int endData = QInputDialog::getInt(this, "Update Edge", "Enter ending node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (!ok) return;
    int newWeight = QInputDialog::getInt(this, "Update Edge", "Enter new edge weight:", 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        graph.updateEdgeWeight(startData, endData, newWeight);
        update();
    }
}

void QtGraphs::on_pushButton_CLEAR_clicked()
{
    graph.clearGraph();
    update();
}

void QtGraphs::on_pushButton_KomiVoyager_clicked()
{
    bool ok;
    int startData = QInputDialog::getInt(this, "Solve TSP", "Enter starting node data:", 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        std::vector<int> path = graph.solveTSP(startData);
        if (path.empty()) {
            QMessageBox::information(this, "TSP Result", "No valid TSP path found.");
        } else {
            QString result;
            for (int node : path) {
                result += QString::number(node) + " -> ";
            }
            result.chop(4); // Remove the last " -> "
            QMessageBox::information(this, "TSP Result", "Optimal path: " + result);
        }
    }
}

void QtGraphs::on_pushButton_ZagotovlenGraph_clicked()
{
    graph.clearGraph();
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);
    graph.addEdge(1, 2, 6);
    graph.addEdge(1, 3, 29);
    graph.addEdge(1, 4, 10);
    graph.addEdge(1, 5, 59);
    graph.addEdge(1, 6, 34);
    graph.addEdge(1, 7, 13);
    graph.addEdge(2, 3, 23);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 53);
    graph.addEdge(2, 6, 28);
    graph.addEdge(2, 7, 7);
    graph.addEdge(3, 1, 23);
    graph.addEdge(3, 2, 21);
    graph.addEdge(3, 4, 20);
    graph.addEdge(3, 5, 31);
    graph.addEdge(3, 6, 6);
    graph.addEdge(3, 7, 17);
    graph.addEdge(4, 1, 8);
    graph.addEdge(4, 2, 3);
    graph.addEdge(4, 3, 20);
    graph.addEdge(4, 5, 50);
    graph.addEdge(4, 6, 25);
    graph.addEdge(4, 7, 4);
    graph.addEdge(5, 1, 43);
    graph.addEdge(5, 2, 40);
    graph.addEdge(5, 3, 22);
    graph.addEdge(5, 4, 38);
    graph.addEdge(5, 6, 26);
    graph.addEdge(5, 7, 47);
    graph.addEdge(6, 1, 26);
    graph.addEdge(6, 2, 24);
    graph.addEdge(6, 3, 4);
    graph.addEdge(6, 4, 22);
    graph.addEdge(6, 5, 18);
    graph.addEdge(6, 7, 22);
    graph.addEdge(7, 1, 10);
    graph.addEdge(7, 2, 5);
    graph.addEdge(7, 3, 17);
    graph.addEdge(7, 4, 4);
    graph.addEdge(7, 5, 35);
    graph.addEdge(7, 6, 19);
    update();
}

void QtGraphs::on_pushButton_randGraph_clicked()
{
    graph.clearGraph();
    srand(static_cast<unsigned>(time(0)));

    int nodeCount = QInputDialog::getInt(this, "Random Graph", "Enter number of nodes:", 5, 1, 100, 1);
    int edgeCount = QInputDialog::getInt(this, "Random Graph", "Enter number of edges:", 10, 1, 200, 1);

    for (int i = 0; i < nodeCount; ++i)
    {
        graph.addNode(i + 1);
    }

    for (int i = 0; i < edgeCount; ++i)
    {
        int from = rand() % nodeCount + 1;
        int to = rand() % nodeCount + 1;
        int weight = rand() % 100 + 1;

        if (from != to)
        {
            graph.addEdge(from, to, weight);
        }
    }
    update();
}
