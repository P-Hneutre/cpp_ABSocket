#include "contact.h"

Contact::Contact(std::string const & name, e_status status, int id)
{
    this->_pseudo = name;
    this->_id = id;
    this->_status = status;
    this->_mapStringStatus[OFFLINE] = "offline";
    this->_mapStringStatus[ONLINE] = "online";
    this->_mapStringStatus[DELETED] = "deleted";
    this->_mapStringStatus[BUSY] = "busy";
    this->_mapStringStatus[INVITE] = "invite";
    this->_mapStringStatus[INVITED] = "invited";
    this->_mapIconStatus[OFFLINE] = ":/img/offline.png";
    this->_mapIconStatus[ONLINE] = ":/img/online.png";
    this->_mapIconStatus[DELETED] = ":/img/delete.png";
    this->_mapIconStatus[BUSY] = ":/img/busy.png";
    this->_mapIconStatus[INVITE] = ":/img/babelicon.png";
    this->_mapIconStatus[INVITED] = ":/img/invited.png";
}

Contact::~Contact()
{
}

std::string Contact::getContactName()const
{
    return (this->_pseudo);
}

int         Contact::getContactId()const
{
    return (this->_id);
}

e_status    Contact::getContactStatus()const
{
    return (this->_status);
}

std::string Contact::getStringStatus(e_status status)
{
    return (this->_mapStringStatus[status]);
}

std::string Contact::getIconStatus(e_status status)
{
    return (this->_mapIconStatus[status]);
}

void        Contact::setContactStatus(e_status status)
{
    this->_status = status;
}

void        Contact::setContactName(std::string name)
{
    this->_pseudo = name;
}
