#pragma once

#include <string>

class ISocket
{
	public:
		virtual			~ISocket() = 0;
		virtual void	init() = 0;
		virtual bool	connectToServer(std::string const &host, short port) = 0;
		virtual int		recv(std::string &buffer, int size) = 0;
		virtual int		send(std::string const &data) = 0;
		virtual void	end() = 0;
};

