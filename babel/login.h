#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "mainview.h"
#include "contactmanager.h"

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
    void on_login_clicked();
    void on_goRegister_clicked();
    void on_applyRegister_clicked();
    void on_cancelRegister_clicked();

private:
    Ui::Login   *ui;
    MainView    *_mainView;
    TcpSocket   *_tcpSocks;
    const char  *_pseudo;
    const char  *_pwd;
    Contact     *_user;
private:
    void createAccount(const char *_pseudo, const char *_pass);
    void failPwdConfirmation();
    void incompleteForm();
    void setLogin(bool state);
    void setRegister(bool state);
    void setParameters();
    Contact *verifyUser();


};

#endif // LOGIN_H
