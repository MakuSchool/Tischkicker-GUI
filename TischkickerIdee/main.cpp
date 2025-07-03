#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.setWindowTitle("StackedWidget Navigation");
    w.resize(800, 600);
    w.show();

    return app.exec();
}
