#ifndef INETWORKMANAGER
#define INETWORKMANAGER

#include <QtNetwork/QAbstractSocket>

//#include "Protocole.h"

class                       INetworkManager
{
public:
    virtual ~INetworkManager() {}
    virtual void                setHost(QString const&) = 0;
    virtual QString             getHost() const = 0;
    virtual void                setPort(quint16) = 0;
    virtual quint16             getPort() const = 0;
    virtual void                setTcpSocket(QAbstractSocket *) = 0;
    virtual QAbstractSocket *   getSocket() const = 0;
    //virtual void              sendDataTcp(type_CS, std::string const&, std::string const&) = 0;
    //virtual void              sendDataUdp(type_CC _action, std::string const&, std::string const&, QHostAddress const&) = 0;
    virtual void                connectServer() const = 0;
};

#endif // INETWORKMANAGER

