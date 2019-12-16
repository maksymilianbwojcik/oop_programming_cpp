#ifndef SPEED_H
#define SPEED_H

#include <QObject>
#include <QDebug>

class Speed : public QObject
{
    Q_OBJECT
public:
    explicit Speed(QObject *parent = nullptr);
signals:
    void changed(double v);
public slots:
    void onDisplacementChanged(double v);

private:
    bool go;
    double value1;
    double value2;
};

#endif // SPEED_H
