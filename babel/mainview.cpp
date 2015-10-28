#include "mainview.h"
#include "listdelegate.h"
#include "ui_mainview.h"
#include "tcpsocket.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    //this.logon = false;
    this->_about = new About();
    ui->setupUi(this);
    this->ui->statusbar->hide();
    this->setFixedSize(565, 462);
    connect(this->ui->actionAbout, SIGNAL(triggered()),this, SLOT(showAbout()));
    connect(this->ui->actionView_profile, SIGNAL(triggered()),this, SLOT(viewProfile()));
    connect(this->ui->actionDeconnection, SIGNAL(triggered()),this, SLOT(deconnect()));
    this->ui->contactList->setItemDelegate(new ListDelegate(this->ui->contactList));
    this->createContact("taMère");



}

MainView::~MainView()
{
    delete ui;
}


void    MainView::createContact(std::string contact)
{
    QListWidgetItem *item = new QListWidgetItem();
    item->setData(Qt::DisplayRole, contact.c_str());
    item->setData(Qt::UserRole + 1, "Online"); //contact->gestStatus();
    item->setData(Qt::DecorationRole , ":/img/babel.png");
    this->ui->contactList->addItem(item);
}

void    MainView::showAbout()
{
    this->_about->exec();
}

void    MainView::deconnect()
{
    //this->close();
    //this->_login->show();
}

void    MainView::viewProfile()
{

}
