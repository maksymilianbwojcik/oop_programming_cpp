#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float value
               READ get
               WRITE set
               NOTIFY changed)
public:
    explicit Displacement(QObject *parent = nullptr);
    double get();


signals:
    void changed(double v);

public slots:
    void set(double v);

};

#endif // DISPLACEMENT_H
