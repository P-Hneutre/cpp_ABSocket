#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <string>
#include <iostream>
#include <QList>
#include "contact.h"

class ContactManager
{
    QList<Contact *> _contactList;
public:
    ContactManager();
    ~ContactManager(){}
    void                addContactInList(Contact *contact);
    void                updContactInList(Contact *contact);
    void                delContactInList(Contact *);
    QList<Contact *>    getContactList()const;
    void                call(Contact *);
    void                hangUp(Contact *);
};

#endif // CONTACTMANAGER_H
