#include "tcpsocket.h"

TcpSocket::TcpSocket()
{

}

TcpSocket::~TcpSocket()
{
}

void            TcpSocket::setHost(QString const& host)
{
    this->_host = host;
}

QString         TcpSocket::getHost()
{
    return (this->_host);
}

void            TcpSocket::setPort(quint16 port)
{
    this->_port = port;
}

quint16         TcpSocket::getPort()
{
    return (this->_port);
}

void            TcpSocket::setSocket(QAbstractSocket *tcpSocket)
{
    if (tcpSocket->socketType() == 0)
        this->_tcpSocket =   qobject_cast<QTcpSocket *> tcpSocket;
}

QAbstractSocket *    TcpSocket::getSocket()
{
    return (this->_tcpSocket);
}

void            TcpSocket::connectServer()
{

}
