#pragma once
#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include "ISocket.hh"

class WSocket : public ISocket
{
	WSADATA			*_wsaSocket;
	DWORD			_error;
public:
	WSocket();
	virtual ~WSocket();
	virtual bool	AbconnectToServer(std::string const &host, short port);
	virtual int		AbSocket(int, int, int);
	virtual int		AbBind(int, const struct sockaddr *, size_t);
	virtual int		AbListen(int, int);
	virtual int		AbConnect(int, const struct sockaddr *, size_t);
	virtual int		AbAccept(int, struct sockaddr *, size_t *);
	virtual int		AbSend(int, const void *, size_t, int);
	virtual int		AbSendTo(int, const void *, size_t, int, const struct sockaddr *, size_t);
	virtual int		AbRecv(int, void *, size_t, int);
	virtual int		AbRecvFrom(int, void *, size_t, int, struct sockaddr *, size_t *);
};

