#pragma once

#include <string>
#include <iostream>

class ISocket
{
	public:

		virtual void	init() const = 0;
		virtual void	end() const = 0;
		virtual bool	connectToServer(std::string host, std::string port) const = 0;
		virtual bool	connectFromAcceptedFd(int fd) const = 0;
		virtual int		recv(std::string buffer, int size) const = 0;
		virtual int 	send(std::string  data) const = 0;
};

