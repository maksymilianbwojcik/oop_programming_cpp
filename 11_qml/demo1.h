#ifndef DEMO1_H
#define DEMO1_H

#include <QObject>
#include <QQuickItem>
#include "displacement.h"
#include "speed.h"
#include "acceleration.h"
class Demo1 : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float value
               READ getValue
               WRITE setValue
               NOTIFY valueChanged)
public:
    explicit Demo1(QObject *parent = nullptr);

    Q_INVOKABLE void doSomething();
    void setValue(float v);
    float getValue() const;
signals:
    void test();
    void valueChanged();
public slots:
    void on_pushButton_clicked(double);

private:
    float value;
    Displacement *displacement;
    Speed *speed;
    Acceleration *acceleration;
};

#endif // DEMO1_H
