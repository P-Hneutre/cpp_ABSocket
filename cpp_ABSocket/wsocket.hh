#pragma once

#pragma comment(lib,"Ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include "ISocket.hh"

typedef struct	sockaddr_in	SOCKADDR_IN;
typedef struct	sockaddr	SOCKADDR;
typedef struct	in_addr		IN_ADDR;

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
	WSADATA			*_wsaData;
	SOCKET			_sock;
	DWORD			_error;
	SOCKET	       	_fd;
	std::string		_port;
	std::string		_host;
};
