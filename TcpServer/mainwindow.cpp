#include <QThread>
#include <QDateTime>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "peermanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textLog->setReadOnly(true);
    ui->pushBtnStop->setEnabled(false);
        
//    connect(PeerManager::i(), SIGNAL(newMessage(QString,QString)), 
//            this, SLOT(newMessage(QString,QString)));
    connect(PeerManager::i(), SIGNAL(newConnection(Connection*)),
            this, SLOT(newConnection(Connection*)));
    connect(PeerManager::i(), SIGNAL(disconnected(QString, QString)), 
            this, SLOT(disconnectedHandler(QString,QString)));
//    connect(PeerManager::i().server(), SIGNAL(error(QAbstractSocket::SocketError)),
//            this, SLOT(connectionError(QAbstractSocket::SocketError)));
    connect(ui->pushBtnStart, SIGNAL(clicked(bool)), 
            PeerManager::i(), SLOT(startServer()));
    connect(ui->pushBtnStop, SIGNAL(clicked(bool)), 
            PeerManager::i(), SLOT(stopServer()));
    connect(ui->pushBtnStart, SIGNAL(clicked(bool)),
            this, SLOT(startServer()));
    connect(ui->pushBtnStop, SIGNAL(clicked(bool)),
            this, SLOT(stopServer()));
    connect(PeerManager::i(), SIGNAL(greetingMessageRecieved(QString,QString)),
            this, SLOT(greetingMessageRecieved(QString,QString)));
    connect(PeerManager::i(), SIGNAL(errorRepeatUser(QString, QString)),
            this, SLOT(errorRepeatUser(QString, QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::greetingMessageRecieved(const QString &nickName,
                                         const QString &ipPort)
{
    ui->textLog->append(currentTime() + QString("%1 identified with %2").
                        arg(nickName).
                        arg(ipPort));
}

void MainWindow::newConnection(Connection *connection)
{
    ui->textLog->append(currentTime() + QString("New connection with %1").
                        arg(connection->addresPort()));
}

void MainWindow::disconnectedHandler(QString nickName, QString ipPort)
{    
    ui->textLog->append(currentTime() + 
                        QString("Disconected %1 (%2)").
                        arg(nickName).
                        arg(ipPort));
}

void MainWindow::startServer()
{
    ui->textLog->append(currentTime() + "Server is started");
    ui->pushBtnStart->setEnabled(false);
    ui->pushBtnStop->setEnabled(true);
}

void MainWindow::stopServer()
{
    ui->textLog->append(currentTime() + "Server is stopped");
    ui->pushBtnStart->setEnabled(true);
    ui->pushBtnStop->setEnabled(false);
}

void MainWindow::errorRepeatUser(const QString nickName, const QString ipPort)
{
    ui->textLog->append(currentTime() + QString("Repeated nick name %1 (%2)").
                        arg(nickName).
                        arg(ipPort));
}

QString MainWindow::currentTime() const
{
    return '[' + QDateTime::currentDateTime().
            toString("yyyy.MM.dd HH:mm:ss") + "] ";
}

//void MainWindow::connectionError(QAbstractSocket::SocketError socketError)
//{
//    ui->textLog->append(socketError.errorString());
//}
