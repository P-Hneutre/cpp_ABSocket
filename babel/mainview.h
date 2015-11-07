#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <QListWidgetItem>
#include "about.h"
#include "listdelegate.h"
#include "ui_mainview.h"
#include "tcpsocket.h"
#include "contactmanager.h"

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0,/* Contact *me = 0, */QTcpSocket *socket = 0);
    ~MainView();

private:
    typedef                         void (MainView::*uiStatus)();
    Contact                         *_me;
    Ui::MainView                    *ui;
    About                           *_about;
    QListWidgetItem                 *_currentItem;
    QList<Contact *>                _contactList;
    ContactManager                  *_contact;
    QTcpSocket                      *_tcpSocket;
    std::map<e_status, uiStatus>    _mapUiStatus;

private slots:
    void                            showAbout();
    void                            deconnect();
    void                            viewProfile();

    void on_contactList_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_acceptButt_clicked();

private:
    void            fillContact();
    void            onContactSelected();
    void            setParameters();
    void            checkStatus();
    void            uiOnline();
    void            uiOffline();
    void            uiInvite();
    void            uiOther();
};

#endif // MAINVIEW_H
