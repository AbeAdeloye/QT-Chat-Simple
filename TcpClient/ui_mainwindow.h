/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdtMessage;
    QPushButton *pushBtnSendMessage;
    QTextEdit *textEdtChat;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblServer;
    QLabel *lblServerName;
    QLabel *lblNick;
    QLabel *lblNickName;
    QListView *listViewUsers;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(622, 476);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(false);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdtMessage = new QLineEdit(centralWidget);
        lineEdtMessage->setObjectName(QStringLiteral("lineEdtMessage"));
        QFont font;
        font.setPointSize(12);
        lineEdtMessage->setFont(font);

        horizontalLayout->addWidget(lineEdtMessage);

        pushBtnSendMessage = new QPushButton(centralWidget);
        pushBtnSendMessage->setObjectName(QStringLiteral("pushBtnSendMessage"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushBtnSendMessage->sizePolicy().hasHeightForWidth());
        pushBtnSendMessage->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushBtnSendMessage);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        textEdtChat = new QTextEdit(centralWidget);
        textEdtChat->setObjectName(QStringLiteral("textEdtChat"));
        textEdtChat->setFont(font);

        gridLayout->addWidget(textEdtChat, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblServer = new QLabel(centralWidget);
        lblServer->setObjectName(QStringLiteral("lblServer"));
        lblServer->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(10);
        lblServer->setFont(font1);

        horizontalLayout_2->addWidget(lblServer);

        lblServerName = new QLabel(centralWidget);
        lblServerName->setObjectName(QStringLiteral("lblServerName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblServerName->sizePolicy().hasHeightForWidth());
        lblServerName->setSizePolicy(sizePolicy1);
        lblServerName->setFont(font1);

        horizontalLayout_2->addWidget(lblServerName);

        lblNick = new QLabel(centralWidget);
        lblNick->setObjectName(QStringLiteral("lblNick"));
        lblNick->setFont(font1);

        horizontalLayout_2->addWidget(lblNick);

        lblNickName = new QLabel(centralWidget);
        lblNickName->setObjectName(QStringLiteral("lblNickName"));
        sizePolicy1.setHeightForWidth(lblNickName->sizePolicy().hasHeightForWidth());
        lblNickName->setSizePolicy(sizePolicy1);
        lblNickName->setFont(font1);

        horizontalLayout_2->addWidget(lblNickName);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        listViewUsers = new QListView(centralWidget);
        listViewUsers->setObjectName(QStringLiteral("listViewUsers"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listViewUsers->sizePolicy().hasHeightForWidth());
        listViewUsers->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        listViewUsers->setFont(font2);

        gridLayout->addWidget(listViewUsers, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushBtnSendMessage->setText(QApplication::translate("MainWindow", "Send", nullptr));
        lblServer->setText(QApplication::translate("MainWindow", "Server:", nullptr));
        lblServerName->setText(QApplication::translate("MainWindow", "Unknown", nullptr));
        lblNick->setText(QApplication::translate("MainWindow", "NickName:", nullptr));
        lblNickName->setText(QApplication::translate("MainWindow", "Unknown", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
