#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <map>

enum e_status
{
    OFFLINE	= 0,
    ONLINE	= 1,
    DELETED	= 2,
    BUSY	= 3,
    INVITE	= 4,
    INVITED	= 5,
};
class Contact
{
    std::string _pseudo;
    int         _id;
    e_status    _status;
    std::map<e_status, std::string> _mapStringStatus;
    std::map<e_status, std::string> _mapIconStatus;
public:
    Contact(std::string const &, e_status, int id);
    ~Contact();
    std::string getContactName()const;
    int         getContactId()const;
    e_status    getContactStatus()const;
    std::string getStringStatus(e_status);
    std::string getIconStatus(e_status);
    void        setContactStatus(e_status);
    void        setContactName(std::string);
};

#endif // CONTACT_H
