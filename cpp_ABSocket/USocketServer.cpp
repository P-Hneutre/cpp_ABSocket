#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "USocketServer.hh"

USocketServer::USocketServer()
{
  this->_fd = 0;
  this->_sockAddr = NULL;
  this->_sockIn = NULL;
  this->_hostInfo = NULL;
  _timeout.tv_sec = 0;
  _timeout.tv_usec = 0;
}

USocketServer::~USocketServer()
{
}

void	USocketServer::setHost(std::string const &host)
{
  this->_hostInfo = gethostbyname(host.c_str());
}

void	USocketServer::setPort(std::string const &port)
{
  int n = 0;
  std::istringstream buffer(port);
  buffer >> n;
  this->_port = htons(n);
}

bool	USocketServer::init(std::string const &host, std::string const &port)
{
  this->setHost(host);
  this->setPort(port);
  this->_fd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);
  if (this->_fd == INVALID_SOCKET)
    {
      perror("socket");
      this->_error = INVALID_SOCKET;
      return false;
    }
  if (this->_hostInfo == NULL)
    {
      this->_error = UNKNOWN_HOST;
      std::cerr << "unknown host\n";
      return false;
    }
  this->_sockAddrIn.sin_addr.s_addr = INADDR_ANY;
  this->_sockAddrIn.sin_port = this->_port;
  this->_sockAddrIn.sin_family = AF_INET;
  if (bind(this->_fd, (SOCKADDR *) &this->_sockAddrIn, sizeof(SOCKADDR)) < 0)
    {
      this->_error = ERR_BIND;
      perror("bind");
      return false;
    }
  if (listen(_fd, 51) == -1)
    return (perror("Listen"), false);
  struct sockaddr_in sin;
  unsigned int addrlen = sizeof(sin);
  if(getsockname(this->_fd, (struct sockaddr *)&sin, &addrlen) == 0 &&
     sin.sin_family == AF_INET &&
     addrlen == sizeof(sin))
    {
      int local_port = ntohs(sin.sin_port);
      std::cout << "Server listening on port " << local_port << std::endl;
    }
  return true;
}

ISocket*	USocketServer::my_accept()
{
  SOCKADDR_IN cli_addr;
  socklen_t clilen;
  int newsockfd;
  void* fd;

  clilen = sizeof(cli_addr);
  if (FD_ISSET(_fd, &_fds[READ]))
  {
    newsockfd = accept(this->_fd, (SOCKADDR *) &cli_addr, &clilen);
    if (newsockfd <= 0)
      {
        perror("accept");
        this->_error = ERR_ACPT;
        return NULL;
      }
    ISocket *s = new USocket();
    fd = &newsockfd;
    s->connectFromAcceptedFd(fd);
    s->setHost(inet_ntoa(cli_addr.sin_addr));
    return s;
  }
  return NULL;
}

int	 USocketServer::my_select(int number, bool write = false)
{
  FD_SET(_fd, &_fds[READ]);
  if (write)
    return select(_maxFd + 1, &_fds[READ], &_fds[WRITE], NULL,
		  (_timeout.tv_sec == 0 && _timeout.tv_usec == 0) ? NULL : &_timeout);
  else
    return select(_maxFd + 1, &_fds[READ], NULL, NULL,
		  (_timeout.tv_sec == 0 && _timeout.tv_usec == 0) ? NULL : &_timeout);
}

void	USocketServer::clear(ISocket const & socket, STATE_FIELD state)
{
  FD_CLR(dynamic_cast<const USocket*>(&socket)->getFD(), &_fds[state]);
}

int 	USocketServer::isset(ISocket const & socket, STATE_FIELD state)
{
  return FD_ISSET(dynamic_cast<const USocket*>(&socket)->getFD(), &_fds[state]);
}

void	USocketServer::set(ISocket const & socket, STATE_FIELD state)
{
  int	fd = dynamic_cast<const USocket*>(&socket)->getFD();

  if (fd > _maxFd)
    {
      _maxFd = fd;
    }
  FD_SET(fd, &_fds[state]);
}

void	USocketServer::clearAll(STATE_FIELD state)
{
  FD_ZERO(&_fds[state]);
  _maxFd = _fd;
}

void	USocketServer::setTime(long sec, long usec)
{
  _timeout.tv_sec = sec;
  _timeout.tv_usec = usec;
}

void	USocketServer::setIn()
{
  FD_SET(0, &_fds[READ]);
}

int	USocketServer::issetIn()
{
  return (FD_ISSET(0, &_fds[READ]));
}

std::string	USocketServer::readIn()
{
  std::string	command;

  getline(std::cin, command);
  return command;
}
