/********************************************************************************
** Form generated from reading UI file 'contactactions.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTACTIONS_H
#define UI_CONTACTACTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactActions
{
public:

    void setupUi(QWidget *ContactActions)
    {
        if (ContactActions->objectName().isEmpty())
            ContactActions->setObjectName(QStringLiteral("ContactActions"));
        ContactActions->resize(400, 300);

        retranslateUi(ContactActions);

        QMetaObject::connectSlotsByName(ContactActions);
    } // setupUi

    void retranslateUi(QWidget *ContactActions)
    {
        ContactActions->setWindowTitle(QApplication::translate("ContactActions", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ContactActions: public Ui_ContactActions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTACTIONS_H
