#include "udpsocket.h"

UdpSocket::UdpSocket()
{

}

UdpSocket::~UdpSocket()
{

}

void            UdpSocket::setHost(QString const& host)
{
    this->_host = host;
}

QString         UdpSocket::getHost() const
{
    return (this->_host);
}

void            UdpSocket::setPort(quint16 port)
{
    this->_port = port;
}

quint16         UdpSocket::getPort() const
{
    return (this->_port);
}

void            UdpSocket::setUdpSocket(QUdpSocket * udpsocket)
{
    this->_udpSocket = udpsocket;
}

QAbstractSocket *    UdpSocket::getSocket()const
{
    return this->_udpSocket;
}

void            UdpSocket::connectServer()const
{

}


