#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include <QtNetwork/qudpsocket>
#include "inetworkmanager.h"

class UdpSocket : public INetworkManager
{
    QString             _host;
    quint16             _port;
    QUdpSocket          *_udpSocket;
public:
    UdpSocket();
    ~UdpSocket();
    void                setHost(QString const&);
    QString             getHost()const;
    void                setPort(quint16);
    quint16             getPort()const ;
    void                setUdpSocket(QUdpSocket *);
    QAbstractSocket *   getSocket()const;
    //void                sendUdp(e_cmd, std::string const&, std::string const&, QHostAddress const&);
    void                connectServer()const;
};

#endif // UDPSOCKET_H
