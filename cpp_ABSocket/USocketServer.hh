#pragma once

#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>
#include <list>
#include <sstream>
#include "ISocketServer.hh"
#include "USocket.hh"

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define UNKNOWN_HOST 1
#define CONNECT_FAIL 2
#define ERR_RECV 3;
#define ERR_SEND 4;
#define ERR_BIND 5;
#define ERR_ACPT 6;

typedef int					SOCKET;
typedef struct	sockaddr_in SOCKADDR_IN;
typedef struct	sockaddr	SOCKADDR;
typedef struct	in_addr		IN_ADDR;

class USocketServer : public ISocketServer
{
public:
  USocketServer();
  ~USocketServer();

  bool		init(std::string const &host, std::string const &port);
  ISocket*	my_accept();
  int			my_select(int number, bool write);
  void		clear(ISocket const & socket, STATE_FIELD state);
  int 		isset(ISocket const & socket, STATE_FIELD state);
  void		set(ISocket const & socket, STATE_FIELD state);
  void		clearAll(STATE_FIELD state);
  void		setTime(long sec, long usec);
  int 		getFD() const;

  void		setIn();
  int		issetIn();
  std::string	readIn();
  
private:
  void		setHost(std::string const &host);
  void		setPort(std::string const &port);
  
  SOCKET			_fd;
  SOCKADDR		*_sockAddr;
  SOCKADDR_IN		_sockAddrIn;
  IN_ADDR			*_sockIn;
  struct hostent	*_hostInfo;
  short			_port;
  std::string		_host;
  int				_error;
  int		_maxFd;
  fd_set			_fds[2];
  struct timeval	_timeout;
};
