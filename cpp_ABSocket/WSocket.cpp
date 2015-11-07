#include "WSocket.hh"

WSocket::WSocket()
{
  this->_sock = 0;
  this->_error = 0;
}

WSocket::~WSocket() {}

void	WSocket::init()
{
	this->_wsaData = new WSADATA();
 	if (WSAStartup(MAKEWORD(2, 2), this->_wsaData) != 0)
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
  if ((_sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0)) == INVALID_SOCKET)
    throw std::runtime_error("Invalid Socket");
  if ((server = gethostbyname(host.c_str())) == NULL)
    throw std::runtime_error("ERROR, no such host");
  serv_addr.sin_family = AF_INET;
	(char *)&serv_addr.sin_addr.s_addr, server->h_length;
  serv_addr.sin_port = htons(nbPort);
  if (WSAConnect(_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
    throw std::runtime_error("Connect failed");
}

bool	WSocket::connectFromAcceptedFd(void *fd)
{
  int *p = static_cast<int*>(fd);
  this->_sock = *p;
  return true;
}

int		WSocket::recvData(char *data, int size)
{
  int n = 0;

  if ((n = recv(this->_sock, data, size, 0)) <= 0)
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

  if ((n = send(this->_sock, data, size, 0)) < 0)
    this->_error = ERR_SEND;
  return n;
}

int		WSocket::getError() const
{
  return (this->_error);
}

void	WSocket::end()
{
	closesocket(_sock);

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
  return _sock;
}