#pragma once

#include <list>
#include <sstream>
#include "ISocketServer.hh"
#include "WSocket.hh"

typedef struct	sockaddr_in SOCKADDR_IN;
typedef struct	sockaddr	SOCKADDR;
typedef struct	in_addr		IN_ADDR;

class WSocketServer : public ISocketServer
{
public:
	WSocketServer();
	~WSocketServer();

	bool		init(std::string const &host, std::string const &port);
	ISocket*	my_accept();
	int			my_select(int number, bool write);
	void		clear(ISocket const & socket, STATE_FIELD state);
	int 		isset(ISocket const & socket, STATE_FIELD state);
	void		set(ISocket const & socket, STATE_FIELD state);
	void		clearAll(STATE_FIELD state);
	void		setTime(long sec, long usec);
	int 		getFD() const;

	void		setIn();
	int		issetIn();
	std::string	readIn();

private:
	void		setHost(std::string const &host);
	void		setPort(std::string const &port);

	SOCKET			_fd;
	SOCKADDR		*_sockAddr;
	SOCKADDR_IN		_sockAddrIn;
	IN_ADDR			*_sockIn;
	struct hostent	*_hostInfo;
	short			_port;
	std::string		_host;
	int				_error;
	int		_maxFd;
	fd_set			_fds[2];
	struct timeval	_timeout;
};
