#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    d=new Displacement(this);
    s=new Speed(this);
    a=new Acceleration(this);

    QObject::connect(d,SIGNAL(changed(double)),s,SLOT(onDisplacementChanged(double)));
    QObject::connect(s,SIGNAL(changed(double)),a,SLOT(onSpeedChanged(double)));

    ui->setupUi(this);

    connect(s, SIGNAL(changed(double)), ui->SpeedLCD, SLOT(display(double)));
    connect(a, SIGNAL(changed(double)), ui->AccLCD, SLOT(display(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{

}

void MainWindow::on_pushButton_clicked()
{
    auto value = ui->numberEntered->text().toDouble();
    d -> set(value);
}
