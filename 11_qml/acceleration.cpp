#include "acceleration.h"

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

double Acceleration::get()
{
    return second - first;
}

void Acceleration::onChange(double v)
{
    first = second;
    second = v;

    emit changed(get());
}
