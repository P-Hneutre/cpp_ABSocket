#pragma once
#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include "ISocket.hh"

class WSocket : public ISocket
{
public:
	WSocket();
	~WSocket();
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
	WSADATA			*_wsaSocket;
	DWORD			_error;
	SOCKET	       	_fd;
 	std::string		_port;
  	std::string		_host;
  	int		       	_error;
};