#pragma once

#include <string>
#include <iostream>

class ISocket
{
	public:
		virtual			~ISocket(){};
		virtual bool	AbconnectToServer(std::string const &host, short port) const = 0;
		virtual int		AbBind(int, const struct sockaddr *, size_t) const = 0;
		virtual int		AbListen(int, int) const = 0;
		virtual int		AbAccept(int, struct sockaddr *, size_t *) const = 0;
		virtual int		AbSend(int, const void *, size_t, int) const = 0;
		virtual int		AbSendTo(int, const void *, size_t, int, const struct sockaddr *, size_t) const = 0;
		virtual int		AbRecv(int, void *, size_t, int) const = 0;
		virtual int		AbRecvFrom(int, void *, size_t, int, struct sockaddr *, size_t *) const = 0;

};

