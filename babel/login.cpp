#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    this->_tcpSocks = new TcpSocket();
    ui->setupUi(this);
    this->setParameters();
    this->setRegister(false);
}

Login::~Login()
{
    delete ui;
}

void Login::setRegister(bool state)
{
    this->ui->_confPwd->setVisible(state);
    this->ui->_pseudoReg->setVisible(state);
    this->ui->_pwdReg->setVisible(state);
    this->ui->applyRegister->setVisible(state);
    this->ui->cancelRegister->setVisible(state);
    this->ui->labelReg_1->setVisible(state);
    this->ui->labelReg_2->setVisible(state);
    this->ui->labelReg_3->setVisible(state);
}

void Login::setLogin(bool state)
{
    this->ui->label->setVisible(state);
    this->ui->label_2->setVisible(state);
    this->ui->_login->setVisible(state);
    this->ui->_pwd->setVisible(state);
}

void Login::setParameters()
{
    this->setFixedSize(365, 262);
    this->setStyleSheet("background-color: #3498db");
    this->ui->logo->setStyleSheet("background-image: url(:/img/babelmini.png)");
    this->ui->_pseudoReg->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9_]+"), this));
    this->ui->_pseudoReg->setMaxLength(256);
    this->ui->_pwdReg->setEchoMode(QLineEdit::Password);
    this->ui->_pwdReg->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9_]+"), this));
    this->ui->_pwdReg->setMaxLength(42);
    this->ui->_confPwd->setEchoMode(QLineEdit::Password);
    this->ui->_confPwd->setMaxLength(42);
}

void Login::on_login_clicked()
{
    //this->_user = this->verifyUser();
    this->close();
    this->_mainView = new MainView();//new QWidget (), this->_user, this->_tcpSocks);
    this->_mainView->show();
}

void Login::on_goRegister_clicked()
{
    this->setWindowTitle("Register");
    this->setLogin(false);
    this->setRegister(true);
}

void Login::on_cancelRegister_clicked()
{
    this->setWindowTitle("Login");
    this->setRegister(false);
    this->setLogin(true);
}

void Login::on_applyRegister_clicked()
{
    this->_pseudo = this->ui->_pseudoReg->text().toStdString().c_str() ;
    this->_pwd = this->ui->_pwdReg->text().toStdString().c_str() ;

    if (this->ui->_pseudoReg->text().isEmpty() || this->ui->_pwdReg->text().isEmpty())
        this->incompleteForm();
    else if (this->ui->_pwdReg->text() != this->ui->_confPwd->text())
        this->failPwdConfirmation();
    else
        this->createAccount(_pseudo, _pwd);
}

void Login::failPwdConfirmation()
{
    QMessageBox::warning(this, "Password", "Fail to confirm password.", QMessageBox::Close);
}

void Login::incompleteForm()
{
    QMessageBox::warning(this, "Account", "Incomplete entries.", QMessageBox::Close);
}

void Login::createAccount(const char *_pseudo, const char *_pass)
{

}

Contact *Login::verifyUser()
{
    return (new Contact(this->_pseudo, ONLINE, 9));
}

