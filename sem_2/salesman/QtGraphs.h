#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <ui_QtGraphs.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <iostream>

class Edge;
class Node;
class Graph;

class Node
{
public:
    int data;
    std::vector<Edge*> edges_to_node;
    QPoint pos;
    bool highlighted;

    Node() : pos(600 + (rand() % 600 - 300), 300 + (rand() % 600 - 300)) {}
};

class Edge
{
public:
    int weight;
    Node* to;
};

class Graph
{
public:
    std::unordered_map<int, Node*> nodes_map;

    void addNode(int data);
    void addEdge(int fromData, int toData, int weight);
    void clearGraph();
    void updateEdgeWeight(int startData, int endData, int newWeight);
    void removeNode(int data);
    void removeEdge(int startData, int endData);
    std::vector<int> solveTSP(int startNodeData);
    void tspHelper(int currentNodeData, std::unordered_set<int>& visited, std::vector<int>& currentPath, int currentCost, int& bestCost, std::vector<int>& bestPath, int startNodeData);
};

class QtGraphs : public QMainWindow
{
    Q_OBJECT

public:
    QtGraphs(QWidget* parent = nullptr);
    ~QtGraphs();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private slots:
    void on_pushButton_KomiVoyager_clicked();
    void on_pushButton_AddNode_clicked();
    void on_pushButton_AddEdge_clicked();
    void on_pushButton_DeleteNode_clicked();
    void on_pushButton_DeleteEdge_clicked();
    void on_pushButton_ZagotovlenGraph_clicked();
    void on_pushButton_randGraph_clicked();
    void on_pushButton_UpdateEdge_clicked();
    void on_pushButton_CLEAR_clicked();

private:
    Ui::QtGraphs ui;
    Graph graph;
    Node* m_selectedNode;
    bool m_nodeSelected;
    bool sel = false;
    Node* sNode;
    void backtrackTSP(Graph& graph, int start, std::vector<int>& tour, std::vector<int>& nodes, double distance, std::vector<int>& shortestPath, double& shortestDistance);
};
