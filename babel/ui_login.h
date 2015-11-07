/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *_pwd;
    QLineEdit *_login;
    QLabel *label;
    QLabel *label_2;
    QWidget *logo;
    QPushButton *login;
    QPushButton *goRegister;
    QLabel *labelReg_1;
    QLineEdit *_confPwd;
    QPushButton *applyRegister;
    QPushButton *cancelRegister;
    QLineEdit *_pseudoReg;
    QLineEdit *_pwdReg;
    QLabel *labelReg_3;
    QLabel *labelReg_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(368, 283);
        _pwd = new QLineEdit(Login);
        _pwd->setObjectName(QStringLiteral("_pwd"));
        _pwd->setGeometry(QRect(180, 160, 113, 20));
        _pwd->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        _login = new QLineEdit(Login);
        _login->setObjectName(QStringLiteral("_login"));
        _login->setGeometry(QRect(180, 120, 113, 20));
        _login->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 160, 101, 20));
        label->setStyleSheet(QLatin1String("font-size: 13px;\n"
"color :rgb(255, 255, 255)"));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 120, 101, 21));
        label_2->setStyleSheet(QLatin1String("font-size: 13px;\n"
"color :rgb(255, 255, 255)"));
        logo = new QWidget(Login);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(69, 10, 221, 80));
        login = new QPushButton(Login);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(60, 220, 111, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        login->setFont(font);
        login->setStyleSheet(QLatin1String("QPushButton {\n"
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
        goRegister = new QPushButton(Login);
        goRegister->setObjectName(QStringLiteral("goRegister"));
        goRegister->setGeometry(QRect(200, 220, 111, 31));
        goRegister->setFont(font);
        goRegister->setStyleSheet(QLatin1String("QPushButton {\n"
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
        labelReg_1 = new QLabel(Login);
        labelReg_1->setObjectName(QStringLiteral("labelReg_1"));
        labelReg_1->setEnabled(true);
        labelReg_1->setGeometry(QRect(50, 100, 121, 20));
        labelReg_1->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255);font-size:13px;"));
        _confPwd = new QLineEdit(Login);
        _confPwd->setObjectName(QStringLiteral("_confPwd"));
        _confPwd->setEnabled(true);
        _confPwd->setGeometry(QRect(210, 180, 113, 21));
        _confPwd->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        applyRegister = new QPushButton(Login);
        applyRegister->setObjectName(QStringLiteral("applyRegister"));
        applyRegister->setEnabled(true);
        applyRegister->setGeometry(QRect(200, 220, 111, 31));
        applyRegister->setFont(font);
        applyRegister->setStyleSheet(QLatin1String("QPushButton {\n"
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
        cancelRegister = new QPushButton(Login);
        cancelRegister->setObjectName(QStringLiteral("cancelRegister"));
        cancelRegister->setEnabled(true);
        cancelRegister->setGeometry(QRect(60, 220, 111, 31));
        cancelRegister->setFont(font);
        cancelRegister->setStyleSheet(QLatin1String("QPushButton {\n"
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
        _pseudoReg = new QLineEdit(Login);
        _pseudoReg->setObjectName(QStringLiteral("_pseudoReg"));
        _pseudoReg->setEnabled(true);
        _pseudoReg->setGeometry(QRect(210, 100, 113, 21));
        _pseudoReg->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        _pwdReg = new QLineEdit(Login);
        _pwdReg->setObjectName(QStringLiteral("_pwdReg"));
        _pwdReg->setEnabled(true);
        _pwdReg->setGeometry(QRect(210, 140, 113, 21));
        _pwdReg->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255);"));
        labelReg_3 = new QLabel(Login);
        labelReg_3->setObjectName(QStringLiteral("labelReg_3"));
        labelReg_3->setEnabled(false);
        labelReg_3->setGeometry(QRect(50, 180, 161, 20));
        labelReg_3->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255);font-size:13px;"));
        labelReg_2 = new QLabel(Login);
        labelReg_2->setObjectName(QStringLiteral("labelReg_2"));
        labelReg_2->setEnabled(false);
        labelReg_2->setGeometry(QRect(50, 140, 131, 20));
        labelReg_2->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255);font-size:13px;"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        label->setText(QApplication::translate("Login", "Password ", 0));
        label_2->setText(QApplication::translate("Login", "Login ", 0));
        login->setText(QApplication::translate("Login", "Login", 0));
        goRegister->setText(QApplication::translate("Login", "Sign up", 0));
        labelReg_1->setText(QApplication::translate("Login", "Pseudo", 0));
        applyRegister->setText(QApplication::translate("Login", "Register", 0));
        cancelRegister->setText(QApplication::translate("Login", "Cancel", 0));
        labelReg_3->setText(QApplication::translate("Login", "Confirm password", 0));
        labelReg_2->setText(QApplication::translate("Login", "Password", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
