#pragma once

#include <string>
#include <iostream>
#include "ISocket.hh"

#define UNKNOWN_HOST 1
#define CONNECT_FAIL 2
#define ERR_RECV 3;
#define ERR_SEND 4;
#define ERR_BIND 5;
#define ERR_ACPT 6;

enum STATE_FIELD
{
  READ = 0,
  WRITE,
};

class ISocketServer
{
public:
  virtual ~ISocketServer() {};

public:
  virtual bool		init(std::string const &host, std::string const &port) = 0;
  virtual ISocket*	my_accept() = 0;
  virtual int  		my_select(int number, bool write) = 0;
  virtual void		clear(ISocket const & socket, STATE_FIELD state) = 0;
  virtual int 		isset(ISocket const & socket, STATE_FIELD state) = 0;
  virtual void		set(ISocket const & socket, STATE_FIELD state) = 0;
  virtual void		clearAll(STATE_FIELD state) = 0;
  virtual void		setTime(long sec, long usec) = 0;

  virtual void		setIn() = 0;
  virtual int		issetIn() = 0;
  virtual std::string	readIn() = 0;
};
