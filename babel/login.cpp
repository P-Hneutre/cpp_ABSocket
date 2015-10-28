#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    this->_registerForm = new Register();
    this->_mainView= new MainView();
    ui->setupUi(this);
    this->setFixedSize(365, 262);
    this->setStyleSheet("background-color: #3498db");
    this->ui->connect->setStyleSheet("border-style: outset;border-width: 2px;border-radius:10px;border-color: black;");
    this->ui->logo->setStyleSheet("background-image: url(:/img/babelmini.png)");
}

Login::~Login()
{
    delete ui;
}

void Login::on_connect_clicked()
{
    this->close();
    this->_mainView->show();
}

void Login::on_register_2_clicked()
{
    this->hide();
    this->_registerForm->exec();
    this->show();
}
