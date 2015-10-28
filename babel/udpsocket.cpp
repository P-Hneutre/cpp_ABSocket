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

QString         UdpSocket::getHost()
{
    return (this->_host);
}

void            UdpSocket::setPort(quint16 port)
{
    this->_port = port;
}

quint16         UdpSocket::getPort()
{
    return (this->_port);
}

void            UdpSocket::setSocket(QAbstractSocket * udpsocket)
{
    //this->_udpSocket = udpsocket;
}

QAbstractSocket *    UdpSocket::getSocket()
{
    return this->_udpSocket;
}

void            UdpSocket::connectServer()
{

}


