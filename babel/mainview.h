#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <QListWidgetItem>
#include "about.h"
namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
    Ui::MainView    *ui;
    About           *_about;
//    Login           *_login;
private slots:
    void            showAbout();
    void            deconnect();
    void            viewProfile();

public:
    void            createContact(std::string contact);
};

#endif // MAINVIEW_H
