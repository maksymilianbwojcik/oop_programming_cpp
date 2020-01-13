#include "demo1.h"
#include <QDebug>

Demo1::Demo1(QObject *parent) : QObject(parent)
{
    displacement = new Displacement(this);
    speed = new Speed(this);
    acceleration = new Acceleration(this);
}

void Demo1::doSomething()
{
   // qDebug() << "Doing something";
    //setValue(getValue()+1.0f);
   // emit test();
}

void Demo1::setValue(float v)
{
    if(v==value)
        return;
    value = v;
    emit valueChanged();
    displacement->set(value);

}

float Demo1::getValue() const
{
    return value;

}

void Demo1::on_pushButton_clicked(double value)
{
    displacement->set(value);
}
