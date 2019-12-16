#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "acceleration.h"
#include "speed.h"
#include "displacement.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_pressed();

private:
    Acceleration* a = new Acceleration(this);
    Displacement* d = new Displacement(this);
    Speed* s = new Speed(this);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
