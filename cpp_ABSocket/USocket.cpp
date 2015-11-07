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
#include <iostream>

#include "USocket.hh"

USocket::USocket()
{
  this->_fd = 0;
  this->_error = 0;
}

USocket::~USocket() {}

void	USocket::init() {}

void	USocket::connectToServer(std::string const & host, std::string const & port)
{
  struct sockaddr_in serv_addr;
  struct hostent *server;
  std::stringstream buff(port);
  int	nbPort;

  this->_port = port;
  this->_host = host;
  buff >> nbPort;
  if ((_fd = socket(AF_INET, SOCK_STREAM, 0)) <= INVALID_SOCK)
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

bool	USocket::connectFromAcceptedFd(void *fd)
{
  int *p = static_cast<int*>(fd);
  this->_fd = *p;
  return true;
}

int		USocket::recvData(char *data, int size)
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

int 	USocket::sendData(char const *data, int size)
{
  int n = 0;

  if ((n = write(this->_fd, data, size)) < 0)
    this->_error = ERR_SEND;
  return n;
}

int		USocket::getError() const
{
  return (this->_error);
}

void	USocket::end()
{
  close(this->_fd);
}

void	USocket::setHost(std::string const &host)
{
  this->_host = host;
}

std::string const &	USocket::getHost() const
{
  return this->_host;
}

SOCKET 	USocket::getFD() const
{
  return _fd;
}
