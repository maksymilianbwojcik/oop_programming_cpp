#include "acceleration.h"

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}

void Acceleration::onSpeedChanged(double v)
{
    emit changed(v-value);
    value = v;
}
