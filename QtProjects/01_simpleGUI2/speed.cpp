#include "speed.h"

Speed::Speed(QObject *parent) : QObject(parent)
{

}

void Speed::onDisplacementChanged(double v)
{
    if(!go)
    {
       value2=v;
       go=1;
    }
    else
    {
       value1=value2;
       value2=v;
    }

    v=value2-value1;
    emit changed(v);
}
