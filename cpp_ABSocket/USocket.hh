#ifndef USOCKET_HH_
#define USOCKET_HH_

#include "ISocket.hh"

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#include	<sys/select.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<sys/time.h>
#include	<netdb.h>
#include	<arpa/inet.h>
#include	<netdb.h>

class USocket : public ISocket
{
public:
	USocket();
	virtual ~USocket();
	virtual bool	AbconnectToServer(std::string const &host, short port);
	virtual int		AbBind(SOCKET, const struct sockaddr *, size_t);
	virtual int		AbListen(SOCKET, int);
	virtual int		AbConnect(SOCKET, const struct sockaddr *, size_t);
	virtual int		AbAccept(SOCKET, struct sockaddr *, size_t *);
	virtual int		AbSend(SOCKET, const void *, size_t, int);
	virtual int		AbSendTo(SOCKET, const void *, size_t, int, const struct sockaddr *, size_t);
	virtual int		AbRecv(SOCKET, void *, size_t, int);
	virtual int		AbRecvFrom(SOCKET, void *, size_t, int, struct sockaddr *, size_t *);

};

#endif /*USOCKET_hh_*/