#include <QApplication>
#include "displacement.h"
#include "speed.h"
#include "acceleration.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
