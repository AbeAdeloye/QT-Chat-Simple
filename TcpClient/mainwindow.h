#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QStringListModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createConnections();
    //QModelIndex findItemInModelUsers(const QString &itemName);
    void addUserToListView(const QString &nickName);
    void deleteUserAtListView(const QString &nickName);
    
protected:
    void changeEvent(QEvent *e);
    
private slots:
    void sendMessage();
    void newMssg(const QString &from, const QString &message);
    void newUser(const QString &nickName);
    //void loadMessageForCurrentUser();
    void lblServerNameChangeColor(bool isChange);
    void listWgtCurrentRowChanged(const QModelIndex &current);
    void deleteDisconectedUser(const QString &nickName);
    void errorNickName();
    
private:
    Ui::MainWindow *ui;
    
    QHash<QString, QList<QString>> _userChatWindow;
    QStringListModel *_modelUsers;
    QStringList *_listModelUsers;
};

#endif // MAINWINDOW_H
