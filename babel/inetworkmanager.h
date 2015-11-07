#ifndef INETWORKMANAGER
#define INETWORKMANAGER

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/qtcpsocket>
#include <QtNetwork/QUdpSocket>

#include "protocol.h"
class                       INetworkManager
{
public:
    virtual ~INetworkManager() {}
    virtual void                setHost(QString const&) = 0;
    virtual QString             getHost() const = 0;
    virtual void                setPort(quint16) = 0;
    virtual quint16             getPort() const = 0;
    //virtual void                setUdpSocket(QUdpSocket *) = 0;
    virtual void                setTcpSocket(QTcpSocket *) = 0;
    virtual QAbstractSocket *   getSocket() const = 0;
    //virtual void                sendTcp(e_cmd, std::string const&, std::string const&) = 0;
    //virtual void                sendUdp(e_cmd, std::string const&, std::string const&, QHostAddress const&) = 0;
    virtual void                connectServer() const = 0;
};

#endif // INETWORKMANAGER

