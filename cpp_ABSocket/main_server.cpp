#include <iostream>
#include <memory>

#include "WSocketServer.hh"
#include "WSocket.hh"

typedef std::auto_ptr<ISocket> Socket;

/*
	SERVER
 */
int main(int a, char **av)
{
  ISocketServer *server = new WSocketServer();
  server->init("127.0.0.1", "4242");
  Socket	client(server->my_accept());

  if (client.get() == NULL)
    {
      std::cout << "Accept failed" << std::endl;
      return (1);
    }
  client->sendData("fuck you bitch", 14);
  client->end();
  return (0);
}
