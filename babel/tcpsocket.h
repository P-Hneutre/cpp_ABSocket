#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QtNetwork/qtcpsocket>
#include "inetworkmanager.h"

class TcpSocket : public INetworkManager
{
    QString             _host;
    quint16             _port;
    QTcpSocket          *_tcpSocket;
public:
    TcpSocket();
    ~TcpSocket();
    void                setHost(QString const&);
    QString             getHost();
    void                setPort(quint16);
    quint16             getPort();
    void                setSocket(QAbstractSocket *);
    QAbstractSocket *   getSocket();
    void                connectServer();
};

#endif // TCPSOCKET_H
