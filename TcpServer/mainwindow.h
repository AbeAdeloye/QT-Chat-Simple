#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "connection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:
    void changeEvent(QEvent *e);

private slots:
    void greetingMessageRecieved(const QString &nickName,const QString &ipPort);
//    void newMessage(const QString &from, const QString &message);
    void newConnection(Connection *connection);
    void disconnectedHandler(QString nickName, QString ipPort);
    void startServer();
    void stopServer();
    void errorRepeatUser(const QString nickName, const QString ipPort);
//    void connectionError(QAbstractSocket::SocketError socketError);
    
private:
    QString currentTime() const;
    
private:
    Ui::MainWindow *ui;    
};

#endif // MAINWINDOW_H
