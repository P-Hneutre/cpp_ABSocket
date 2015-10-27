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
#define UNKNOWN_HOST 1
#define CONNECT_FAIL 2
#define ERR_RECV 3;
#define ERR_SEND 4;
#define closesocket(s) close(s)

typedef int					SOCKET;
typedef struct	sockaddr_in SOCKADDR_IN;
typedef struct	sockaddr	SOCKADDR;
typedef struct	in_addr		IN_ADDR;

class USocket : public ISocket
{
	SOCKET			_fd;
	SOCKADDR		*_sockAddr;
	SOCKADDR_IN		_sockAddrIn;
	IN_ADDR			*_sockIn;
	struct hostent	*_hostInfo;
	short			_port;
	std::string		_host;
	int				_error;

public:
	USocket();
	virtual				~USocket();
	virtual bool		connectToServer(std::string host, std::string port);
	virtual bool		connectFromAcceptedFd(int fd);
	virtual int			recvData(char * buffer, int size);
	virtual int 		sendData(std::string buffer);
	virtual void		setHost(std::string host);
	virtual void		setPort(std::string port);
	virtual std::string getHostName();
	virtual short		getPort();
	virtual void		end();
	virtual int			getError();

};

#endif /*USOCKET_hh_*/