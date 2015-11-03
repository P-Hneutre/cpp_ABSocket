#include "mainview.h"

MainView::MainView(QWidget *parent, QTcpSocket *socket) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    //this.logon = false;
    this->_about = new About();
    ui->setupUi(this);

    this->setParameters();
    connect(this->ui->actionAbout, SIGNAL(triggered()),this, SLOT(showAbout()));
    connect(this->ui->actionView_profile, SIGNAL(triggered()),this, SLOT(viewProfile()));
    connect(this->ui->actionDeconnection, SIGNAL(triggered()),this, SLOT(deconnect()));
    this->_mapUiStatus[ONLINE]  = &MainView::uiOnline;
    this->_mapUiStatus[OFFLINE] = &MainView::uiOffline;
    this->_mapUiStatus[INVITE]  = &MainView::uiInvite;
    this->_mapUiStatus[INVITED] = &MainView::uiOther;
    this->_mapUiStatus[DELETED] = &MainView::uiOther;
    this->_mapUiStatus[BUSY]    = &MainView::uiOnline;
    this->ui->contactList->setItemDelegate(new ListDelegate(this->ui->contactList));
    this->_contact = new ContactManager();
    this->_contact->addContactInList(new Contact("d", INVITED, 1));
    this->_contact->addContactInList(new Contact("d", INVITE, 2));
    this->_contact->addContactInList(new Contact("d", INVITE, 3));
    this->_contact->addContactInList(new Contact("d", DELETED, 4));
    this->_contact->addContactInList(new Contact("d", ONLINE, 5));
    this->_contact->addContactInList(new Contact("d", OFFLINE, 6));
    this->_contact->addContactInList(new Contact("d", BUSY, 7));
    this->_contactList = this->_contact->getContactList();
    this->fillContact();
}

MainView::~MainView()
{
    delete ui;
}


void MainView::setParameters()
{
    this->ui->statusbar->hide();
    this->ui->pushButton->hide();
    this->ui->pushButton_2->hide();
    this->ui->pseudo_2->hide();
    this->ui->pseudo_3->hide();
    this->ui->contactPseudo->hide();
    this->ui->contactStatus->hide();
    this->ui->acceptButt->hide();
    this->ui->desabledDelete->hide();
    this->ui->desabledCall->hide();
    this->setFixedSize(565, 462);
}

void    MainView::fillContact()
{
    QList<Contact *>::iterator it;

    this->ui->contactList->clear();
    for (it = this->_contactList.begin(); it != this->_contactList.end(); it++)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setData(Qt::DisplayRole, (*it)->getContactName().c_str());
        item->setData(Qt::UserRole + 1,  (*it)->getStringStatus((*it)->getContactStatus()).c_str());
        item->setData(Qt::UserRole + 2,  (*it)->getContactId());
        item->setData(Qt::DecorationRole , (*it)->getIconStatus((*it)->getContactStatus()).c_str());

        this->ui->contactList->addItem(item);
    }
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

void    MainView::onContactSelected()
{
    this->ui->label_5->hide();
    this->ui->label_6->hide();
    this->ui->label_7->hide();
    this->ui->pseudo_2->show();
    this->ui->pseudo_3->show();
    this->ui->contactPseudo->show();
    this->ui->contactStatus->show();
    this->checkStatus();

}

void MainView::checkStatus()
{
    QList<Contact *>::iterator it;
    if (this->_currentItem != NULL)
    {
        for (it = this->_contactList.begin(); it != this->_contactList.end(); it++)
        if (this->_currentItem->data(Qt::UserRole + 2) == (*it)->getContactId())
           (this->*_mapUiStatus[(*it)->getContactStatus()])();
    }
    if (this->_currentItem->data(Qt::UserRole + 1) != "invite")
        {
            this->ui->acceptButt->hide();
            this->ui->pushButton->show();
            this->ui->pushButton_2->show();
        }
}

void MainView::uiOther()
{
    this->ui->pushButton->setEnabled(false);
    this->ui->desabledCall->show();
    this->ui->pushButton_2->setEnabled(false);
    this->ui->desabledDelete->show();
}

void MainView::uiInvite()
{
    this->ui->pushButton->hide();
    this->ui->pushButton_2->hide();
    this->ui->desabledDelete->hide();
    this->ui->desabledCall->hide();
    this->ui->acceptButt->show();
}

void MainView::uiOffline()
{
    this->ui->pushButton->setEnabled(false);
    this->ui->pushButton_2->setEnabled(true);
    this->ui->desabledCall->show();
}

void MainView::uiOnline()
{
    this->ui->pushButton->setEnabled(true);
    this->ui->pushButton_2->setEnabled(true);
    this->ui->desabledDelete->hide();
    this->ui->desabledCall->hide();
}

void MainView::on_contactList_itemClicked(QListWidgetItem *item)
{
    this->_currentItem = item;
    this->onContactSelected();
    this->ui->contactPseudo->setText(item->data(Qt::DisplayRole).toString());
    this->ui->contactStatus->setText( item->data(Qt::UserRole + 1).toString());
    this->ui->contactIsStatus->setPixmap(QPixmap(item->data(Qt::DecorationRole).toString()));
}

void MainView::on_pushButton_clicked()
{
    QList<Contact *>::iterator  it;
    if (this->_currentItem != NULL)
    {
        for (it = this->_contactList.begin(); it != this->_contactList.end(); it++)
        if (this->_currentItem->data(Qt::UserRole + 2) == (*it)->getContactId())
            this->_contact->call((*it));
        this->_currentItem = NULL;
    }
}
void MainView::on_pushButton_2_clicked()
{
    QList<Contact *>::iterator it;
    if (this->_currentItem != NULL)
    {
        for (it = this->_contactList.begin(); it != this->_contactList.end(); it++)
        if (this->_currentItem->data(Qt::UserRole + 2) == (*it)->getContactId())
           this->_contact->delContactInList((*it));
        this->_contactList = this->_contact->getContactList();
        this->fillContact();
        this->_currentItem = NULL;
    }
}

void MainView::on_acceptButt_clicked()
{
    QList<Contact *>::iterator it;
    if (this->_currentItem != NULL)
    {
        for (it = this->_contactList.begin(); it != this->_contactList.end(); it++)
        if (this->_currentItem->data(Qt::UserRole + 2) == (*it)->getContactId())
            (*it)->setContactStatus(OFFLINE);
        this->_contactList = this->_contact->getContactList();
        this->fillContact();
        this->_currentItem = NULL;
    }
}
