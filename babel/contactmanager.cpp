#include "contactmanager.h"

ContactManager::ContactManager()
{

}

void    ContactManager::addContactInList(Contact *contact)
{

    this->_contactList.push_back(contact);
}

void    ContactManager::updContactInList(Contact *contact)
{
    QList<Contact *>::iterator it;
    for (it = this->_contactList.begin(); it != this->_contactList.end(); it++)
        if (contact->getContactId() == (*it)->getContactId())
            (*it)->setContactStatus(ONLINE);
}

void    ContactManager::delContactInList(Contact *contact)
{
    QList<Contact *>::iterator it;
    for (it = this->_contactList.begin(); it != this->_contactList.end(); it++)
        if (contact->getContactId() == (*it)->getContactId())
            this->_contactList.erase(it);
}

QList<Contact *>    ContactManager::getContactList()const
{
    return (this->_contactList);
}

void    ContactManager::call(Contact *)
{

}

void    ContactManager::hangUp(Contact *)
{

}
