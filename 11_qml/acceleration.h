#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float value
               READ get
               WRITE onChange
               NOTIFY changed)
public:
    explicit Acceleration(QObject *parent = nullptr);

    double get();

signals:
    void changed(double v);

public slots:
    void onChange(double v);

private:
    double first{};
    double second{};
};

#endif // ACCELERATION_H
