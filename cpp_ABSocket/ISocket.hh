#pragma once

#include <string>
#include <stdexcept>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define UNKNOWN_HOST 1
#define CONNECT_FAIL 2
#define ERR_RECV 3;
#define ERR_SEND 4;
#define ERR_BIND 5;
#define ERR_ACPT 6;

class ISocket
{
public:
  virtual ~ISocket() {};

public:
  virtual void	init() = 0;
  virtual void	connectToServer(std::string const & host, std::string const & port) = 0;
  virtual bool	connectFromAcceptedFd(void *fd) = 0;
  virtual int  	recvData(char * data, int size) = 0;
  virtual int 	sendData(const char *data, int size) = 0;
  virtual int  	getError() const  = 0;
  virtual void	setHost(std::string const &host) = 0;
  virtual std::string const & getHost() const = 0;
  virtual void	end() = 0;
};
