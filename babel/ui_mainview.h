/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QAction *actionAdd_contact;
    QAction *actionSearch_contact;
    QAction *actionAbout;
    QAction *actionDeconnection;
    QAction *actionDonate;
    QAction *actionView_profile;
    QWidget *centralwidget;
    QListWidget *contactList;
    QFrame *line;
    QLabel *label;
    QFrame *line_3;
    QFrame *line_4;
    QListWidget *contactList_2;
    QFrame *line_5;
    QLabel *label_2;
    QFrame *line_6;
    QLabel *pseudo_2;
    QLabel *pseudo_3;
    QLabel *contactPseudo;
    QLabel *contactStatus;
    QPushButton *pushButton;
    QLabel *pseudo_5;
    QLabel *ownPseudo;
    QLabel *ownStatus;
    QLabel *pseudo_7;
    QLabel *label_3;
    QFrame *line_2;
    QFrame *line_8;
    QFrame *line_7;
    QLabel *label_4;
    QFrame *line_9;
    QFrame *line_10;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *ownIcStatus;
    QLabel *contactIsStatus;
    QPushButton *desabledCall;
    QPushButton *desabledDelete;
    QPushButton *acceptButt;
    QMenuBar *menubar;
    QMenu *menuFil;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(572, 462);
        MainView->setStyleSheet(QStringLiteral(""));
        actionAdd_contact = new QAction(MainView);
        actionAdd_contact->setObjectName(QStringLiteral("actionAdd_contact"));
        QFont font;
        font.setPointSize(10);
        actionAdd_contact->setFont(font);
        actionSearch_contact = new QAction(MainView);
        actionSearch_contact->setObjectName(QStringLiteral("actionSearch_contact"));
        actionSearch_contact->setFont(font);
        actionAbout = new QAction(MainView);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout->setFont(font);
        actionDeconnection = new QAction(MainView);
        actionDeconnection->setObjectName(QStringLiteral("actionDeconnection"));
        actionDeconnection->setFont(font);
        actionDonate = new QAction(MainView);
        actionDonate->setObjectName(QStringLiteral("actionDonate"));
        actionDonate->setFont(font);
        actionView_profile = new QAction(MainView);
        actionView_profile->setObjectName(QStringLiteral("actionView_profile"));
        centralwidget = new QWidget(MainView);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        contactList = new QListWidget(centralwidget);
        contactList->setObjectName(QStringLiteral("contactList"));
        contactList->setGeometry(QRect(0, 180, 291, 261));
        contactList->setStyleSheet(QStringLiteral(""));
        contactList->setLineWidth(0);
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 150, 81, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 140, 141, 20));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(200, 150, 91, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(990, 280, 20, 511));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        contactList_2 = new QListWidget(centralwidget);
        contactList_2->setObjectName(QStringLiteral("contactList_2"));
        contactList_2->setGeometry(QRect(730, 470, 261, 311));
        contactList_2->setLineWidth(0);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(720, 450, 81, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(810, 440, 141, 20));
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(900, 450, 101, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        pseudo_2 = new QLabel(centralwidget);
        pseudo_2->setObjectName(QStringLiteral("pseudo_2"));
        pseudo_2->setGeometry(QRect(310, 220, 141, 20));
        pseudo_3 = new QLabel(centralwidget);
        pseudo_3->setObjectName(QStringLiteral("pseudo_3"));
        pseudo_3->setGeometry(QRect(310, 270, 141, 20));
        contactPseudo = new QLabel(centralwidget);
        contactPseudo->setObjectName(QStringLiteral("contactPseudo"));
        contactPseudo->setGeometry(QRect(390, 220, 141, 20));
        contactStatus = new QLabel(centralwidget);
        contactStatus->setObjectName(QStringLiteral("contactStatus"));
        contactStatus->setGeometry(QRect(390, 270, 141, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 330, 111, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"        border: 1px solid #ffffff;\n"
"		color:rgb(255,255,255);\n"
"        border-radius: 6px;\n"
"    	background-color: #27ae60;\n"
"    }\n"
"    QPushButton:hover {\n"
"        border: 1px solid #333333;\n"
"        background-color: #27ae60;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        border: 1px solid #333333;\n"
"        background-color: #ffffff;\n"
"		color:rgb(0,0,0);\n"
"    }QPushButton {\n"
"        border: 1px solid #fffff;\n"
"		color:rgb(255,255,255);\n"
"        border-radius: 6px;\n"
"    	background-color: #27ae60;\n"
"    }\n"
"    QPushButton:hover {\n"
"        border: 1px solid #333333;\n"
"        background-color: #27ae60;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        border: 1px solid #333333;\n"
"        background-color: #ffffff;\n"
"		color:rgb(0,0,0);\n"
"    }"));
        pseudo_5 = new QLabel(centralwidget);
        pseudo_5->setObjectName(QStringLiteral("pseudo_5"));
        pseudo_5->setGeometry(QRect(210, 50, 141, 20));
        ownPseudo = new QLabel(centralwidget);
        ownPseudo->setObjectName(QStringLiteral("ownPseudo"));
        ownPseudo->setGeometry(QRect(290, 50, 141, 20));
        ownStatus = new QLabel(centralwidget);
        ownStatus->setObjectName(QStringLiteral("ownStatus"));
        ownStatus->setGeometry(QRect(290, 80, 141, 20));
        pseudo_7 = new QLabel(centralwidget);
        pseudo_7->setObjectName(QStringLiteral("pseudo_7"));
        pseudo_7->setGeometry(QRect(210, 80, 141, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 10, 191, 20));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 20, 211, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setGeometry(QRect(360, 20, 211, 21));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(0, 120, 571, 21));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(350, 140, 191, 20));
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setGeometry(QRect(270, 150, 71, 21));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setGeometry(QRect(510, 150, 71, 21));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 380, 111, 31));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"        border: 1px solid #ffffff;\n"
"		color:rgb(255,255,255);\n"
"        border-radius: 6px;\n"
"    	background-color: red;\n"
"    }\n"
"    QPushButton:hover {\n"
"        border: 1px solid #333333;\n"
"        background-color: red;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        border: 1px solid #333333;\n"
"        background-color: black;\n"
"		color:rgb(255,255,255);\n"
"    }"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 250, 171, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(340, 310, 211, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(400, 280, 211, 21));
        ownIcStatus = new QLabel(centralwidget);
        ownIcStatus->setObjectName(QStringLiteral("ownIcStatus"));
        ownIcStatus->setGeometry(QRect(90, 60, 47, 41));
        contactIsStatus = new QLabel(centralwidget);
        contactIsStatus->setObjectName(QStringLiteral("contactIsStatus"));
        contactIsStatus->setGeometry(QRect(470, 260, 47, 41));
        desabledCall = new QPushButton(centralwidget);
        desabledCall->setObjectName(QStringLiteral("desabledCall"));
        desabledCall->setGeometry(QRect(360, 330, 111, 31));
        desabledCall->setFont(font1);
        desabledCall->setStyleSheet(QLatin1String("QPushButton {\n"
"        border: 1px solid #ffffff;\n"
"		color:rgb(255,255,255);\n"
"        border-radius: 6px;\n"
"    	background-color: rgba(189, 195, 199,80%);\n"
"    }"));
        desabledDelete = new QPushButton(centralwidget);
        desabledDelete->setObjectName(QStringLiteral("desabledDelete"));
        desabledDelete->setGeometry(QRect(360, 380, 111, 31));
        desabledDelete->setFont(font1);
        desabledDelete->setStyleSheet(QLatin1String("QPushButton {\n"
"        border: 1px solid #ffffff;\n"
"		color:rgb(255,255,255);\n"
"        border-radius: 6px;\n"
"    	background-color: rgba(189, 195, 199,50%);\n"
"    }"));
        acceptButt = new QPushButton(centralwidget);
        acceptButt->setObjectName(QStringLiteral("acceptButt"));
        acceptButt->setGeometry(QRect(340, 350, 161, 31));
        acceptButt->setFont(font1);
        acceptButt->setStyleSheet(QLatin1String("QPushButton {\n"
"        border: 1px solid;\n"
"		border-color:rgb(0,0,0);\n"
"		color:rgb(255,255,255);\n"
"        border-radius: 6px;\n"
"    	background-color: #2980b9;\n"
"    }\n"
"    QPushButton:hover {\n"
"        border: 1px solid #333333;\n"
"        background-color:#2c3e50;\n"
"		color:rgb(255,255,255);\n"
"    }\n"
"    QPushButton:pressed {\n"
"        border: 1px solid #333333;\n"
"        background-color: #ffffff;\n"
"		color:rgb(0,0,0)\n"
"    }"));
        MainView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainView);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 572, 20));
        menuFil = new QMenu(menubar);
        menuFil->setObjectName(QStringLiteral("menuFil"));
        menuFil->setFont(font);
        MainView->setMenuBar(menubar);
        statusbar = new QStatusBar(MainView);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainView->setStatusBar(statusbar);

        menubar->addAction(menuFil->menuAction());
        menuFil->addAction(actionSearch_contact);
        menuFil->addAction(actionDeconnection);
        menuFil->addSeparator();
        menuFil->addAction(actionDonate);
        menuFil->addAction(actionAbout);

        retranslateUi(MainView);

        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "Babel", 0));
        actionAdd_contact->setText(QApplication::translate("MainView", "Add contact", 0));
        actionSearch_contact->setText(QApplication::translate("MainView", "Search contact", 0));
        actionAbout->setText(QApplication::translate("MainView", "About", 0));
        actionDeconnection->setText(QApplication::translate("MainView", "Deconnection", 0));
        actionDonate->setText(QApplication::translate("MainView", "Donate", 0));
        actionView_profile->setText(QApplication::translate("MainView", "View profile", 0));
        label->setText(QApplication::translate("MainView", "Contact List", 0));
        label_2->setText(QApplication::translate("MainView", "Contact List", 0));
        pseudo_2->setText(QApplication::translate("MainView", "Pseudo :", 0));
        pseudo_3->setText(QApplication::translate("MainView", "Status :", 0));
        contactPseudo->setText(QApplication::translate("MainView", "Baboulinet", 0));
        contactStatus->setText(QApplication::translate("MainView", "Online", 0));
        pushButton->setText(QApplication::translate("MainView", "Call", 0));
        pseudo_5->setText(QApplication::translate("MainView", "Pseudo :", 0));
        ownPseudo->setText(QApplication::translate("MainView", "Baboulinet", 0));
        ownStatus->setText(QApplication::translate("MainView", "Online", 0));
        pseudo_7->setText(QApplication::translate("MainView", "Status :", 0));
        label_3->setText(QApplication::translate("MainView", "Your informations", 0));
        label_4->setText(QApplication::translate("MainView", "Contact  informations", 0));
        pushButton_2->setText(QApplication::translate("MainView", "Delete", 0));
        label_5->setText(QApplication::translate("MainView", "Select a contact", 0));
        label_6->setText(QApplication::translate("MainView", "display his information", 0));
        label_7->setText(QApplication::translate("MainView", "for", 0));
        ownIcStatus->setText(QString());
        contactIsStatus->setText(QString());
        desabledCall->setText(QApplication::translate("MainView", "Call", 0));
        desabledDelete->setText(QApplication::translate("MainView", "Delete", 0));
        acceptButt->setText(QApplication::translate("MainView", "Accept Contact", 0));
        menuFil->setTitle(QApplication::translate("MainView", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
