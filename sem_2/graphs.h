#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <unordered_map>
#include <unordered_set>
#include "ui_graphs.h"

using namespace std;

struct Connection;

struct Vertex
{
    int id;
    vector<Connection*> connections;
    QPoint position;
    Vertex() { position = QPoint(350, 250); }
};

struct Connection
{
    int weight;
    Vertex* to;
    Vertex* from;
};

class Network
{
public:
    vector<Vertex*> vertices;
    unordered_map<int, Vertex*> vertex_map;

    void addVertex(int id);
    void addConnection(int fromId, int toId, int weight);
    void clear();
    void updateConnectionWeight(int fromId, int toId, int newWeight);

    void removeVertex(int id);
    void removeConnection(int fromId, int toId);

    int** createAdjacencyMatrix();
    void depthFirstSearch(int startId, vector<int>& result);
    void breadthFirstSearch(int startId, vector<int>& result);
    vector<int> dijkstraShortestPath(int startId, int endId);
};

class GraphVisualizer : public QMainWindow
{
    Q_OBJECT

public:
    GraphVisualizer(QWidget *parent = nullptr);
    ~GraphVisualizer();
    Network network;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::GraphVisualizer *ui;
    Vertex* selectedVertex;
    bool vertexSelected;

    bool showSelected = false;
    Vertex* specialVertex;

    void handleAddVertexButton();
    void handleAddConnectionButton();
    void handleRemoveVertexButton();
    void handleRemoveConnectionButton();
    void handleSampleGraphButton();

    void handleChangeConnectionWeightButton();
    void handleClearGraphButton();
    void handleDepthAndBreadthSearchButton();
    void handleShortestPathButton();
};
