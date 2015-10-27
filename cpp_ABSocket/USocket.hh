#ifndef USOCKET_HH_
#define USOCKET_HH_

#include "ISocket.hh"

#include	<sys/select.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<sys/time.h>
#include	<netdb.h>
#include	<arpa/inet.h>
#include	<netdb.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

typedef int					SOCKET;
typedef struct	sockaddr_in SOCKADDR_IN;
typedef struct	sockaddr	SOCKADDR;
typedef struct	in_addr		IN_ADDR;

class USocket : public ISocket
{
	SOCKET			_fd;
	SOCKADDR		*_sockAddr;
	SOCKADDR_IN		*_sockAddrIn;
	IN_ADDR			*_sockIn;
	struct hostent	*_hostInfo;
	short			_port;
	std::string		_host;

public:
	USocket();
	virtual				~USocket();
	virtual bool		connectToServer(std::string host, std::string port);
	virtual bool		connectFromAcceptedFd(int fd);
	virtual int			recv(std::string buffer, int size);
	virtual int 		send(std::string  data);
	virtual void		setHostName(std::string host);
	virtual void		setPort(std::string port);
	virtual std::string getHostName();
	virtual short		getPort();

};

#endif /*USOCKET_hh_*/