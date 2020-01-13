#include "displacement.h"

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::set(double v)
{
    value =v;
    emit changed(value);
}

double Displacement::get()
{
    return value;
}
