#include "graphs.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphVisualizer w;
    w.show();
    return a.exec();
}
