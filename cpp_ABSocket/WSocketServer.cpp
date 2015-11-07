#include <Winsock2.h>
#include <stdio.h>
#include <windows.h>

#include "WSocketServer.hh"

WSocketServer::WSocketServer()
{
	this->_fd = 0;
	this->_sockAddr = NULL;
	this->_sockIn = NULL;
	this->_hostInfo = NULL;
	_timeout.tv_sec = 0;
	_timeout.tv_usec = 0;
}

WSocketServer::~WSocketServer()
{
}

void	WSocketServer::setHost(std::string const &host)
{
	this->_hostInfo = gethostbyname(host.c_str());
}

void	WSocketServer::setPort(std::string const &port)
{
	int n = 0;
	std::istringstream buffer(port);
	buffer >> n;
	this->_port = htons(n);
}

bool	WSocketServer::init(std::string const &host, std::string const &port)
{
	this->setHost(host);
	this->setPort(port);
	this->_fd = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
	if (this->_fd == INVALID_SOCKET)
	{
		perror("socket");
		this->_error = INVALID_SOCKET;
		return false;
	}
	if (this->_hostInfo == NULL)
	{
		this->_error = UNKNOWN_HOST;
		std::cerr << "unknown host\n";
		return false;
	}
	this->_sockAddrIn.sin_addr.s_addr = INADDR_ANY;
	this->_sockAddrIn.sin_port = this->_port;
	this->_sockAddrIn.sin_family = AF_INET;
	if (bind(this->_fd, (SOCKADDR *)&this->_sockAddrIn, sizeof(SOCKADDR)) < 0)
	{
		this->_error = ERR_BIND;
		perror("bind");
		return false;
	}
	if (listen(_fd, 51) == -1)
		return (perror("Listen"), false);
	return true;
}

ISocket*	WSocketServer::my_accept()
{
	SOCKADDR_IN cli_addr;
	socklen_t clilen;
	int newsockfd;
	void* fd;

	clilen = sizeof(cli_addr);
	if (FD_ISSET(_fd, &_fds[READ]))
	{
		newsockfd = accept(this->_fd, (SOCKADDR *)&cli_addr, &clilen);
		if (newsockfd <= 0)
		{
			perror("accept");
			this->_error = ERR_ACPT;
			return NULL;
		}
		ISocket *s = new WSocket();
		fd = &newsockfd;
		s->connectFromAcceptedFd(fd);
		s->setHost(inet_ntoa(cli_addr.sin_addr));
		return s;
	}
	return NULL;
}

int	 WSocketServer::my_select(int number, bool write = false)
{
	FD_SET(_fd, &_fds[READ]);
	if (write)
		return select(_maxFd + 1, &_fds[READ], &_fds[WRITE], NULL,
			(_timeout.tv_sec == 0 && _timeout.tv_usec == 0) ? NULL : &_timeout);
	else
		return select(_maxFd + 1, &_fds[READ], NULL, NULL,
			(_timeout.tv_sec == 0 && _timeout.tv_usec == 0) ? NULL : &_timeout);
}

void	WSocketServer::clear(ISocket const & socket, STATE_FIELD state)
{
	FD_CLR(dynamic_cast<const WSocket*>(&socket)->getFD(), &_fds[state]);
}

int 	WSocketServer::isset(ISocket const & socket, STATE_FIELD state)
{
	return FD_ISSET(dynamic_cast<const WSocket*>(&socket)->getFD(), &_fds[state]);
}

void	WSocketServer::set(ISocket const & socket, STATE_FIELD state)
{
	int	fd = dynamic_cast<const WSocket*>(&socket)->getFD();

	if (fd > _maxFd)
	{
		_maxFd = fd;
	}
	FD_SET(fd, &_fds[state]);
}

void	WSocketServer::clearAll(STATE_FIELD state)
{
	FD_ZERO(&_fds[state]);
	_maxFd = _fd;
}

void	WSocketServer::setTime(long sec, long usec)
{
	_timeout.tv_sec = sec;
	_timeout.tv_usec = usec;
}

void	WSocketServer::setIn()
{
	FD_SET(0, &_fds[READ]);
}

int	WSocketServer::issetIn()
{
	return (FD_ISSET(0, &_fds[READ]));
}

std::string	WSocketServer::readIn()
{
	std::string	command;

	getline(std::cin, command);
	return command;
}
