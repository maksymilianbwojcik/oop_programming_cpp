#include "speed.h"

Speed::Speed(QObject *parent) : QObject(parent)
{

}

double Speed::get()
{
    return second - first;
}

void Speed::onChange(double v)
{
    first = second;
    second = v;

    emit changed(get());
}

