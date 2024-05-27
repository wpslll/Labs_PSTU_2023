#include "graphs.h"
#include "ui_graphs.h"
#include <cmath>
#include <QPainter>
#include <queue>
#include <stack>

void Network::addVertex(int id)
{
    if (vertex_map.find(id) == vertex_map.end())
    {
        Vertex* newVertex = new Vertex;
        newVertex->id = id;
        vertex_map[id] = newVertex;
        vertices.push_back(newVertex);
    }
}

void Network::addConnection(int fromId, int toId, int weight)
{
    for (Connection* connection : vertex_map[fromId]->connections)
    {
        if (connection->to == vertex_map[toId])
        {
            return;
        }
    }

    Connection* newConnection = new Connection();
    newConnection->to = vertex_map[toId];
    newConnection->from = vertex_map[fromId];
    newConnection->weight = weight;
    vertex_map[fromId]->connections.push_back(newConnection);
}

void Network::clear()
{
    for (auto& pair : vertex_map)
    {
        Vertex* vertex = pair.second;
        delete vertex;
    }
    vertex_map.clear();
    vertices.clear();
}

void Network::updateConnectionWeight(int fromId, int toId, int newWeight)
{
    if (vertex_map.find(fromId) == vertex_map.end() || vertex_map.find(toId) == vertex_map.end())
    {
        return;
    }

    Vertex* fromVertex = vertex_map[fromId];
    Vertex* toVertex = vertex_map[toId];

    for (Connection* connection : fromVertex->connections)
    {
        if (connection->to == toVertex)
        {
            connection->weight = newWeight;
            return;
        }
    }
}

void Network::removeVertex(int id)
{
    for (auto& pair : vertex_map)
    {
        Vertex* vertex = pair.second;
        vector<Connection*> connections_to_remove;

        for (Connection* connection : vertex->connections)
        {
            if (connection->to->id == id)
            {
                connections_to_remove.push_back(connection);
            }
        }

        for (Connection* connection : connections_to_remove)
        {
            auto it = find(vertex->connections.begin(), vertex->connections.end(), connection);
            if (it != vertex->connections.end())
            {
                vertex->connections.erase(it);
                delete connection;
            }
        }
    }

    auto it = vertex_map.find(id);
    if (it != vertex_map.end())
    {
        delete it->second;
        vertex_map.erase(it);
    }

    Vertex* vertexToRemove = nullptr;
    for (Vertex* vertex : vertices)
    {
        if (vertex->id == id)
        {
            vertexToRemove = vertex;
            break;
        }
    }

    if (vertexToRemove)
    {
        auto it = find(vertices.begin(), vertices.end(), vertexToRemove);
        if (it != vertices.end())
        {
            vertices.erase(it);
        }
    }
}

void Network::removeConnection(int fromId, int toId)
{
    auto fromVertexIt = vertex_map.find(fromId);
    auto toVertexIt = vertex_map.find(toId);

    if (fromVertexIt == vertex_map.end() || toVertexIt == vertex_map.end())
    {
        return;
    }

    Vertex* fromVertex = fromVertexIt->second;
    Vertex* toVertex = toVertexIt->second;

    Connection* connectionToRemove = nullptr;

    for (Connection* connection : fromVertex->connections)
    {
        if (connection->to->id == toId)
        {
            connectionToRemove = connection;
            break;
        }
    }

    if (connectionToRemove)
    {
        auto it = find(fromVertex->connections.begin(), fromVertex->connections.end(), connectionToRemove);
        if (it != fromVertex->connections.end())
        {
            fromVertex->connections.erase(it);
            delete connectionToRemove;
        }
    }
}

GraphVisualizer::GraphVisualizer(QWidget *parent): QMainWindow(parent), ui(new Ui::GraphVisualizer)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &GraphVisualizer::handleAddVertexButton);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &GraphVisualizer::handleAddConnectionButton);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &GraphVisualizer::handleRemoveVertexButton);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &GraphVisualizer::handleRemoveConnectionButton);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &GraphVisualizer::handleSampleGraphButton);

    connect(ui->pushButton_6, &QPushButton::clicked, this, &GraphVisualizer::handleChangeConnectionWeightButton);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &GraphVisualizer::handleClearGraphButton);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &GraphVisualizer::handleDepthAndBreadthSearchButton);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &GraphVisualizer::handleShortestPathButton);
}

GraphVisualizer::~GraphVisualizer()
{
    delete ui;
}

void GraphVisualizer::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QFont font = painter.font();
    font.setPointSize(16);
    painter.setFont(font);
    for (const auto& pair : network.vertex_map)
    {
        Vertex* vertex = pair.second;
        for (Connection* connection : vertex->connections)
        {
            QPoint fromPos;
            QPoint toPos;
            int offset = 20 * sin(atan(1));
            double angle = atan2(-(connection->to->position.y() - vertex->position.y()), (connection->to->position.x() - vertex->position.x()));
            fromPos = QPoint(vertex->position.x() + 20 * cos(angle), vertex->position.y() - 20 * sin(angle));
            toPos = QPoint(connection->to->position.x() - 20 * cos(angle), connection->to->position.y() + 20 * sin(angle));
            painter.drawLine(fromPos, toPos);
            int midX = fromPos.x() + 4 * (toPos.x() - fromPos.x()) / 5;
            int midY = fromPos.y() - 4 * (fromPos.y() - toPos.y()) / 5;
            painter.drawText(midX - 10, midY + 10, QString::number(connection->weight));

            QLine line(fromPos, toPos);
            double arrowAngle = atan2(-line.dy(), line.dx()) - M_PI / 2;
            double arrowSize = 15;
            QPointF arrowP1 = toPos + QPointF(sin(arrowAngle - M_PI / 10) * arrowSize, cos(arrowAngle - M_PI / 10) * arrowSize);
            QPointF arrowP2 = toPos + QPointF(sin(arrowAngle + M_PI / 10) * arrowSize, cos(arrowAngle + M_PI / 10) * arrowSize);
            QPolygonF arrowHead;
            arrowHead << toPos << arrowP1 << arrowP2;
            painter.drawPolygon(arrowHead);
        }
    }

    for (const auto& pair : network.vertex_map)
    {
        Vertex* vertex = pair.second;
        painter.setBrush(Qt::white);
        if (vertex == specialVertex)
        {
            painter.setBrush(Qt::green);
        }
        painter.drawEllipse(vertex->position, 20, 20);
        painter.drawText(vertex->position.x() - 15, vertex->position.y() + 8, QString::number(vertex->id));
    }
}

void GraphVisualizer::mousePressEvent(QMouseEvent* event)
{
    for (const auto& pair : network.vertex_map)
    {
        Vertex* vertex = pair.second;
        if (QRect(vertex->position.x() - 20, vertex->position.y() - 20, 40, 40).contains(event->pos()))
        {
            selectedVertex = vertex;
            vertexSelected = true;
            break;
        }
    }
}

void GraphVisualizer::mouseMoveEvent(QMouseEvent* event)
{
    if (vertexSelected && selectedVertex)
    {
        selectedVertex->position = event->pos();
        update();
    }
}

void GraphVisualizer::mouseReleaseEvent(QMouseEvent* event)
{
    vertexSelected = false;
    selectedVertex = nullptr;
}

void GraphVisualizer::handleAddVertexButton()
{
    static int vertexId = 0;
    network.addVertex(vertexId++);
    update();
}

void GraphVisualizer::handleAddConnectionButton()
{
    int fromId = ui->spinBox->value();
    int toId = ui->spinBox_2->value();
    int weight = ui->spinBox_3->value();
    network.addConnection(fromId, toId, weight);
    update();
}

void GraphVisualizer::handleRemoveVertexButton()
{
    int vertexId = ui->spinBox_4->value();
    network.removeVertex(vertexId);
    update();
}

void GraphVisualizer::handleRemoveConnectionButton()
{
    int fromId = ui->spinBox_5->value();
    int toId = ui->spinBox_6->value();
    network.removeConnection(fromId, toId);
    update();
}

void GraphVisualizer::handleSampleGraphButton()
{
    network.clear();
    network.addVertex(0);
    network.addVertex(1);
    network.addVertex(2);
    network.addVertex(3);
    network.addConnection(0, 1, 1);
    network.addConnection(1, 2, 2);
    network.addConnection(2, 3, 3);
    network.addConnection(3, 0, 4);
    update();
}

void GraphVisualizer::handleChangeConnectionWeightButton()
{
    int fromId = ui->spinBox_7->value();
    int toId = ui->spinBox_8->value();
    int newWeight = ui->spinBox_9->value();
    network.updateConnectionWeight(fromId, toId, newWeight);
    update();
}

void GraphVisualizer::handleClearGraphButton()
{
    network.clear();
    update();
}

void GraphVisualizer::handleDepthAndBreadthSearchButton()
{
    vector<int> result;
    int startId = ui->spinBox_10->value();
    network.depthFirstSearch(startId, result);
    for (int id : result)
    {
        // Process result (e.g., display it in a message box or text edit)
    }
}

void GraphVisualizer::handleShortestPathButton()
{
    int startId = ui->spinBox_11->value();
    int endId = ui->spinBox_12->value();
    vector<int> shortestPath = network.dijkstraShortestPath(startId, endId);
    for (int id : shortestPath)
    {
        // Process result (e.g., display it in a message box or text edit)
    }
}

void Network::depthFirstSearch(int startId, vector<int>& result)
{
    unordered_set<int> visited;
    stack<Vertex*> stack;

    Vertex* startVertex = vertex_map[startId];
    stack.push(startVertex);

    while (!stack.empty())
    {
        Vertex* current = stack.top();
        stack.pop();

        if (visited.find(current->id) == visited.end())
        {
            visited.insert(current->id);
            result.push_back(current->id);

            for (Connection* connection : current->connections)
            {
                stack.push(connection->to);
            }
        }
    }
}

void Network::breadthFirstSearch(int startId, vector<int>& result)
{
    unordered_set<int> visited;
    queue<Vertex*> queue;

    Vertex* startVertex = vertex_map[startId];
    queue.push(startVertex);
    visited.insert(startId);

    while (!queue.empty())
    {
        Vertex* current = queue.front();
        queue.pop();
        result.push_back(current->id);

        for (Connection* connection : current->connections)
        {
            if (visited.find(connection->to->id) == visited.end())
            {
                queue.push(connection->to);
                visited.insert(connection->to->id);
            }
        }
    }
}

vector<int> Network::dijkstraShortestPath(int startId, int endId)
{
    unordered_map<int, int> distances;
    unordered_map<int, int> previous;
    unordered_set<int> visited;

    for (const auto& pair : vertex_map)
    {
        distances[pair.first] = INT_MAX;
    }
    distances[startId] = 0;

    auto compare = [&distances](int lhs, int rhs) { return distances[lhs] > distances[rhs]; };
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);
    pq.push(startId);

    while (!pq.empty())
    {
        int currentId = pq.top();
        pq.pop();

        if (visited.find(currentId) != visited.end())
        {
            continue;
        }
        visited.insert(currentId);

        Vertex* currentVertex = vertex_map[currentId];

        for (Connection* connection : currentVertex->connections)
        {
            int neighborId = connection->to->id;
            int newDist = distances[currentId] + connection->weight;

            if (newDist < distances[neighborId])
            {
                distances[neighborId] = newDist;
                previous[neighborId] = currentId;
                pq.push(neighborId);
            }
        }
    }

    vector<int> path;
    for (int at = endId; at != startId; at = previous[at])
    {
        path.push_back(at);
    }
    path.push_back(startId);
    reverse(path.begin(), path.end());
    return path;
}
