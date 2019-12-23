#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



//    auto greenState = new QState(stateMachine);
//    auto yellowState = new QState(stateMachine);
//    auto redState = new QState(stateMachine);
//    auto logState = new QState(stateMachine);

//    greenState->assignProperty(ui->pbToggle, "text", "GREEN");
//    yellowState->assignProperty(ui->pbToggle, "text", "YELLOW");
//    redState->assignProperty(ui->pbToggle, "text", "RED");
//    logState->assignProperty(ui->pbToggle, "text", "RED");

//    greenState->addTransition(ui->pbToggle, SIGNAL(clicked()), redState);
//    redState->addTransition(ui->pbToggle, SIGNAL(clicked()), yellowState);
//    yellowState->addTransition(ui->pbToggle, SIGNAL(clicked()), logState);
//    logState->addTransition(this, SIGNAL(done()), greenState);

//    connect(logState, SIGNAL(entered()), this, SLOT(log()));

//    stateMachine->setInitialState(greenState);
//    stateMachine->start();

    // TODO: Create state machine
    // TODO: Create states

    auto stateMachine = new QStateMachine(this);

    auto Unlocked = new QState(stateMachine);
    auto UnlockedHist = new QHistoryState(Unlocked);
    auto Locked = new QState(stateMachine);

    auto Startup = new QState(Unlocked);
    auto Open = new QState(Unlocked);
    auto Error = new QState(Unlocked);
    auto View = new QState(Unlocked);
    auto Edit = new QState(Unlocked);
    auto Save = new QState(Unlocked);

    // TODO: Set appropriate 'assignProperty'

    Unlocked->assignProperty(ui->pbToggle, "text", "Lock");
    Unlocked->assignProperty(ui->pbOpen, "enabled", true);
    Unlocked->assignProperty(ui->pbSave, "enabled", true);
    Unlocked->assignProperty(ui->teText, "enabled", true);

    Locked->assignProperty(ui->pbToggle, "text", "Unlock");
    Locked->assignProperty(ui->pbOpen, "enabled", false);
    Locked->assignProperty(ui->pbSave, "enabled", false);
    Locked->assignProperty(ui->teText, "enabled", false);

    Startup->assignProperty(ui->pbOpen, "enabled", true);
    Startup->assignProperty(ui->pbSave, "enabled", false);
    Startup->assignProperty(ui->teText, "enabled", false);
    Startup->assignProperty(ui->teText, "placeholderText", "Open file to start editing...");

    connect(Open, SIGNAL(entered()), this, SLOT(open()));

    Error->assignProperty(ui->pbOpen, "enabled", true);
    Error->assignProperty(ui->pbSave, "enabled", false);
    Error->assignProperty(ui->teText, "enabled", false);
    Error->assignProperty(ui->teText, "placeholderText", "Error occured. Open file to start editing...");

    View->assignProperty(ui->pbOpen, "enabled", true);
    View->assignProperty(ui->pbSave, "enabled", false);
    View->assignProperty(ui->teText, "enabled", true);

    Edit->assignProperty(ui->pbOpen, "enabled", false);
    Edit->assignProperty(ui->pbSave, "enabled", true);
    Edit->assignProperty(ui->teText, "enabled", true);

    connect(Save, SIGNAL(entered()), this, SLOT(save()));

    // TODO: Set state transitions including this class events and slots

    Startup->addTransition(ui->pbOpen, SIGNAL(clicked()), Open);
    Open->addTransition(this, SIGNAL(error()), Error);
    Error->addTransition(ui->pbOpen, SIGNAL(clicked()), Open);
    Open->addTransition(this, SIGNAL(opened()), View);
    View->addTransition(ui->pbOpen, SIGNAL(clicked()), Open);
    View->addTransition(ui->teText, SIGNAL(textChanged()), Edit);
    Edit->addTransition(ui->pbSave, SIGNAL(clicked()), Save);
    Save->addTransition(this, SIGNAL(saved()), View);
    Save->addTransition(this, SIGNAL(error()), Error);

    Unlocked->addTransition(ui->pbToggle, SIGNAL(clicked()), Locked);
    Locked->addTransition(ui->pbToggle, SIGNAL(clicked()), UnlockedHist);


    // TODO: Set initial state OK
    // TODO: Start state machine OK

    stateMachine->setInitialState(Unlocked);

    Unlocked->setInitialState(Startup);

    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    // TODO: Show file dialog
    this->fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open file"), "",
                                                  tr("All files (*)"));
    // TODO: Open selected file
    // TODO: Emit 'error' if opening failed
    // TODO: Set text and emit 'opened' if suceeded
    // TODO: Save file name in 'fileName'

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(this, tr("error"),
                file.errorString());
                emit error();
                return;
            }
    else {
        QMessageBox::information(this, tr("opened"),
        QString("file chosen"));
        emit opened();
        ui->teText->setText(file.readAll());

    }
}

void MainWindow::save()
{
    // TODO: Open 'fileName' for writing
    // TODO: Emit 'error' if opening failed
    // TODO: Save file and emit 'saved' if succeeded

    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite)) {
                QMessageBox::information(this, tr("error"),
                file.errorString());
                emit error();
                return;
            }
    else {
        emit opened();
        ui->teText->setText(file.readAll());
        //file.write(ui->teText->placeholderText().toUtf8()); // czy tak też może być?
        QDataStream out(&file);
        out << ui->teText->placeholderText();
        emit saved();
    }
    file.close();
}

void MainWindow::log()
{
    qDebug() << "Inside log() function...";
    emit done();
}
