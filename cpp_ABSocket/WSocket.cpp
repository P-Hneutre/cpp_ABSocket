#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<sys/time.h>
#include	<netdb.h>
#include	<arpa/inet.h>
#include	<netdb.h>
#include	<sstream>
#include	<stdio.h>
#include	<string.h>
#include 	<iostream>

#include "WSocket.hh"

WSocket::WSocket()
{
  this->_fd = 0;
  this->_error = 0;
}

WSocket::~WSocket() {}

void	WSocket::init()
{
	this->_wsaSocket = new WSADATA();
 	if (WSAStartup(MAKEWORD(2, 2), _wsaSocket) != 0)
 	{
 	}
}

void	WSocket::connectToServer(std::string const & host, std::string const & port)
{
  struct sockaddr_in serv_addr;
  struct hostent *server;
  std::stringstream buff(port);
  int	nbPort;

  this->_port = port;
  this->_host = host;
  buff >> nbPort;
  if ((_fd = socket(AF_INET, SOCK_STREAM, 0)) <= INVALID_SOCKET)
    throw std::runtime_error("Invalid Socket");
  if ((server = gethostbyname(host.c_str())) == NULL)
    throw std::runtime_error("ERROR, no such host");
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
	(char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(nbPort);
  if (connect(_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    throw std::runtime_error("Connect failed");
}

bool	WSocket::connectFromAcceptedFd(void *fd)
{
  int *p = static_cast<int*>(fd);
  this->_fd = *p;
  return true;
}

int		WSocket::recvData(char *data, int size)
{
  int n = 0;

  if ((n = read(this->_fd, data, size)) <= 0)
    {
      this->_error = ERR_RECV;
      return (0);
    }
  data[n] = 0;
  return n;
}

int 	WSocket::sendData(char const *data, int size)
{
  int n = 0;

  if ((n = write(this->_fd, data, size)) < 0)
    this->_error = ERR_SEND;
  return n;
}

int		WSocket::getError() const
{
  return (this->_error);
}

void	WSocket::end()
{
  close(this->_fd);
}

void	WSocket::setHost(std::string const &host)
{
  this->_host = host;
}

std::string const &	WSocket::getHost() const
{
  return this->_host;
}

SOCKET 	WSocket::getFD() const
{
  return _fd;
}



// #include "WSocket.hh"

// WSocket::WSocket(void) {
// 	this->_wsaSocket = new WSADATA();
// 	if (WSAStartup(MAKEWORD(2, 2), _wsaSocket) != 0)
// 	{
// 	}
// }


// WSocket::~WSocket(void) {
// 	WSACleanup();
// 	delete (this->_wsaSocket);
// }

// int	WSocket::AbSocket(int domain, int type, int protocol) {
// 	return (WSASocket(domain, type, protocol, NULL, 0, NULL));
// }

// int	WSocket::AbBind(int socket, const struct sockaddr *addr, size_t addrlen) {
// 	return (bind(socket, addr, addrlen));
// }

// int	WSocket::AbListen(int socket, int backlog) {
// 	return (listen(socket, backlog));
// }

// int	WSocket::AbConnect(int socket, const struct sockaddr *addr, size_t addrlen) {
// 	return (WSAConnect(socket, addr, addrlen, NULL, NULL, NULL, NULL));
// }

// int	WSocket::AbAccept(int socket, struct sockaddr *addr, size_t *addrlen) {
// 	return (WSAAccept(socket, addr, (socklen_t *)addrlen, NULL, NULL));
// }

// int	WSocket::AbSend(int socket, const void *buffer, size_t size, int flags) {
// 	LPWSABUF	send_buf = new WSABUF();

// 	send_buf->buf = (char *)buffer;
// 	send_buf->len = size;
// 	if (WSASend(socket, send_buf, 1, &this->_error, flags, NULL, NULL) == SOCKET_ERROR)
// 		this->_error = SOCKET_ERROR;
// 	delete (send_buf);
// 	return (this->_error);
// }

// int	WSocket::AbSendTo(int socket, const void *buffer, size_t size, int flags, const struct sockaddr *sockaddr, size_t sockaddrlen) {
// 	LPWSABUF	send_buf = new WSABUF();

// 	send_buf->buf = (char *)buffer;
// 	send_buf->len = size;
// 	if (WSASendTo(socket, send_buf, 1, &this->_error, flags, (SOCKADDR *)sockaddr, sockaddrlen, NULL, NULL) == SOCKET_ERROR)
// 		this->_error = SOCKET_ERROR;
// 	delete (send_buf);
// 	return (this->_error);
// }

// int	WSocket::AbRecvFrom(int socket, void *buffer, size_t size, int flags, struct sockaddr *sockaddr, size_t *sockaddrlen) {
// 	LPWSABUF	recv_buf = new WSABUF();
	
// 	recv_buf->buf = (char *)buffer;
// 	recv_buf->len = size;
// 	if (WSARecvFrom(socket, recv_buf, 1, &this->_error, (LPDWORD)(&flags), (SOCKADDR *)sockaddr, (LPINT)sockaddrlen, NULL, NULL) == SOCKET_ERROR)
// 		this->_error = SOCKET_ERROR;
// 	delete (recv_buf);
// 	return (this->_error);
// }
