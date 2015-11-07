#pragma once

#include "ISocket.hh"

typedef int	      		SOCKET;
typedef struct	sockaddr_in	SOCKADDR_IN;
typedef struct	sockaddr	SOCKADDR;
typedef struct	in_addr		IN_ADDR;

class USocket : public ISocket
{
public:
  USocket();
  ~USocket();
public:
  void			init();
  void			connectToServer(std::string const & host, std::string const & port);
  bool			connectFromAcceptedFd(void *fd);
  int			recvData(char *data, int size);
  int			sendData(const char *data, int size);
  int			getError() const;
  void			end();

public:
  void	       		setHost(std::string const &host);
  std::string const &	getHost() const;
  SOCKET       		getFD() const;


private:
  SOCKET	       	_fd;
  std::string		_port;
  std::string		_host;
  int		       	_error;
};
