#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "demo1.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<Demo1>("pl.gwizdz", 1, 0, "Demo");
    qmlRegisterType<Displacement>("displacement", 1, 0, "Displacement");
    qmlRegisterType<Acceleration>("acceleration", 1, 0, "Acceleration");
    qmlRegisterType<Speed>("speed", 1, 0, "Speed");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
