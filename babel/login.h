#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainview.h"
#include "register.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_connect_clicked();

    void on_register_2_clicked();

private:
    Ui::Login   *ui;
    Register    *_registerForm;
    MainView    *_mainView;
};

#endif // LOGIN_H
