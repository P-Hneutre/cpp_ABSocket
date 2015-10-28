#include <QMessageBox>
#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #3498db;");
    this->setFixedSize(365, 262);
    this->ui->logo->setStyleSheet("background-image: url(:/img/babelmini.png)");
    this->ui->_pseudo->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9_]+"), this));
    this->ui->_pseudo->setMaxLength(256);
    this->ui->_password->setEchoMode(QLineEdit::Password);
    this->ui->_password->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9_]+"), this));
    this->ui->_password->setMaxLength(42);
    this->ui->_confPwd->setEchoMode(QLineEdit::Password);
    this->ui->_confPwd->setMaxLength(42);
}

Register::~Register()
{
    delete ui;
}

void Register::on_cancel_clicked()
{
    this->close();
}

void Register::on_register_2_clicked()
{
    const char    *_pseudo;
    const char    *_pwd;

    _pseudo = this->ui->_pseudo->text().toStdString().c_str() ;
    _pwd = this->ui->_password->text().toStdString().c_str() ;

    if (this->ui->_pseudo->text().isEmpty() || this->ui->_password->text().isEmpty())
        this->incompleteForm();
    else if (this->ui->_password->text() != this->ui->_confPwd->text())
        this->failPwdConfirmation();
    else
        createAccount(_pseudo, _pwd);
}

void Register::failPwdConfirmation()
{
    QMessageBox::warning(this, "Password", "Fail to confirm password.", QMessageBox::Close);
}

void Register::incompleteForm()
{
    QMessageBox::warning(this, "Account", "Incomplete entries.", QMessageBox::Close);
}

void Register::createAccount(const char *_pseudo, const char *_pass)
{

}
