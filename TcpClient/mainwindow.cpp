#include <QListWidgetItem>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configs.h"
#include "connection.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _modelUsers(new QStringListModel(this)),
    _listModelUsers(new QStringList())
{
    ui->setupUi(this);
    
    ui->textEdtChat->setReadOnly(true);
    ui->listViewUsers->setModel(_modelUsers);
    ui->listViewUsers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    ui->lblNickName->setText(Configs::i()->nickName().toUtf8());
    ui->lblServerName->setText(QString("%1:%2").
                               arg(Configs::i()->serverIp().toString()).
                               arg(Configs::i()->serverPort()));
    
    createConnections();  
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _listModelUsers;
}

void MainWindow::createConnections()
{
    connect(ui->pushBtnSendMessage, SIGNAL(clicked(bool)),
            this, SLOT(sendMessage()));
    connect(Connection::i(), SIGNAL(newMessage(QString,QString)),
            this, SLOT(newMssg(QString,QString)));
    connect(Connection::i(), SIGNAL(newUser(QString)), 
            this, SLOT(newUser(QString)));
    connect(Connection::i(), SIGNAL(serverIsConnected(bool)),
            this, SLOT(lblServerNameChangeColor(bool)));
    connect(ui->listViewUsers, SIGNAL(clicked(QModelIndex)),
            this, SLOT(listWgtCurrentRowChanged(QModelIndex)));
    connect(Connection::i(), SIGNAL(disconnectedUser(QString)), 
            this, SLOT(deleteDisconectedUser(QString)));
    connect(Connection::i(), SIGNAL(repeatNickName()),
            this, SLOT(errorNickName()));
}

void MainWindow::addUserToListView(const QString &nickName)
{
    _listModelUsers->append(nickName);
    _modelUsers->setStringList(*_listModelUsers);
}

void MainWindow::deleteUserAtListView(const QString &nickName)
{
    _listModelUsers->removeOne(nickName);
    _modelUsers->setStringList(*_listModelUsers);
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

void MainWindow::sendMessage()
{
    if (ui->lineEdtMessage->text() == "" || 
            ui->listViewUsers->currentIndex().row() == -1)
        return;
    
    QString nickNameFromSend = ui->listViewUsers->currentIndex()
                               .data().toString();
    if (Connection::i()->
            sendMessage(nickNameFromSend, ui->lineEdtMessage->text())) {
        
        QString msgToClient = QString("%1: %2").
                              arg(Configs::i()->nickName()).
                              arg(ui->lineEdtMessage->text());
        _userChatWindow[nickNameFromSend].append(msgToClient);
        
        ui->textEdtChat->append(msgToClient);
        ui->lineEdtMessage->clear();
    }    
}

void MainWindow::newMssg(const QString &from, const QString &message)
{
    if (_userChatWindow.contains(from))
        _userChatWindow[from].append(QString("%1: %2").arg(from).arg(message));
    
    if (ui->listViewUsers->currentIndex().isValid())
        if (from == ui->listViewUsers->currentIndex().data().toString())
            ui->textEdtChat->append(QString("%1: %2").arg(from).arg(message));
}

void MainWindow::newUser(const QString &nickName)
{
    if (_listModelUsers->contains(nickName) != true) {
        addUserToListView(nickName);
        _userChatWindow.insert(nickName, QList<QString>());
    }        
}

void MainWindow::lblServerNameChangeColor(bool isChange)
{
    if (isChange) {
        ui->lblServerName->setStyleSheet("color: rgb(0, 180, 0)");
    } else {
        ui->lblServerName->setStyleSheet("color: rgb(180, 0, 0)");
    }
}

void MainWindow::listWgtCurrentRowChanged(const QModelIndex &current)
{    
    ui->textEdtChat->clear();
    QList<QString> listMessage = _userChatWindow[current.data().toString()];
    
    for (int i = 0; i < listMessage.size(); ++i)
        ui->textEdtChat->append(listMessage.at(i));
}

void MainWindow::deleteDisconectedUser(const QString &nickName)
{
    if (_userChatWindow.contains(nickName)) {            
        _userChatWindow.remove(nickName);
        ui->textEdtChat->clear();
        
        deleteUserAtListView(nickName);        
    }    
}

void MainWindow::errorNickName()
{
    QMessageBox error;
    error.setFixedSize(166, 100);
    error.critical(this, "Connection error", "This nickname is already used. "
                                             "Application will exit.");
    
    error.show();
    
    
    qApp->quit();
}
