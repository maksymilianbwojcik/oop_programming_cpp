#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QDebug>
#include <QObject>

class Displacement : public QObject
{
    Q_OBJECT
public:
    explicit Displacement(QObject *parent = nullptr);

    void set(double v);

signals:
    void changed(double v);

public slots:

private:
       double value;
};

#endif // DISPLACEMENT_H
