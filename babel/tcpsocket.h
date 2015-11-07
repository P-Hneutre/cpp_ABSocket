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
    TcpSocket(QString _host = "127.0.0.1", quint16 _port = 35000 );
    ~TcpSocket();
    void                setHost(QString const&);
    QString             getHost()const;
    void                setPort(quint16);
    quint16             getPort()const;
    void                setTcpSocket(QTcpSocket *);
    QAbstractSocket *   getSocket()const;
    //void                sendTcp(e_cmd, std::string const&, std::string const&);
    void                connectServer()const;
};

#endif // TCPSOCKET_H
