#include "tcpsocket.h"

TcpSocket::TcpSocket(QString _host, quint16 _port)
{

}

TcpSocket::~TcpSocket()
{
}

void            TcpSocket::setHost(QString const& host)
{
    this->_host = host;
}

QString         TcpSocket::getHost() const
{
    return (this->_host);
}

void            TcpSocket::setPort(quint16 port)
{
    this->_port = port;
}

quint16         TcpSocket::getPort() const
{
    return (this->_port);
}

void            TcpSocket::setTcpSocket(QTcpSocket *tcpSocket)
{
    this->_tcpSocket = tcpSocket;
}

QAbstractSocket *    TcpSocket::getSocket() const
{
    return (this->_tcpSocket);
}

void            TcpSocket::connectServer() const
{

}
