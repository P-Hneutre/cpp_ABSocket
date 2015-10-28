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
    QString             getHost();
    void                setPort(quint16);
    quint16             getPort();
    void                setSocket(QAbstractSocket *);
    QAbstractSocket *   getSocket();
    void                connectServer();
};

#endif // UDPSOCKET_H
