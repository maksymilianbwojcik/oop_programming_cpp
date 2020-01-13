#include "displacement.h"

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

void Displacement::set(double v)
{
    emit changed(v);
}

double Displacement::get()
{

}
