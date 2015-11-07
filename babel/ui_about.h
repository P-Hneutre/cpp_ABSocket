/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QWidget *logo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(383, 276);
        About->setAutoFillBackground(false);
        About->setStyleSheet(QStringLiteral("background-color:rga(0,5,55);"));
        logo = new QWidget(About);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(80, 30, 211, 81));
        label = new QLabel(About);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 130, 61, 21));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("font-size:20px;color:white;"));
        label_2 = new QLabel(About);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 165, 281, 21));
        label_2->setStyleSheet(QStringLiteral("color:rgb(255,255,255);"));
        label_3 = new QLabel(About);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 190, 341, 20));
        label_3->setStyleSheet(QStringLiteral("color:rgb(255,255,255);"));
        label_4 = new QLabel(About);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 210, 291, 20));
        label_4->setStyleSheet(QStringLiteral("color:rgb(255,255,255);"));
        pushButton = new QPushButton(About);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 240, 101, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"        border: 1px solid;\n"
"		border-color:rgb(255,255,255);\n"
"		color:rgb(255,255,255);\n"
"        border-radius: 6px;\n"
"    	background-color: rga(0,5,5);\n"
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

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About Babel", 0));
        label->setText(QApplication::translate("About", "Babel", 0));
        label_2->setText(QApplication::translate("About", "Copyright 2015 The Babel compagny. All rights reserved.", 0));
        label_3->setText(QApplication::translate("About", "This project was made by carens_p, dallar_h,", 0));
        label_4->setText(QApplication::translate("About", " gousse_p, penava_b and parvea_m. ", 0));
        pushButton->setText(QApplication::translate("About", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
