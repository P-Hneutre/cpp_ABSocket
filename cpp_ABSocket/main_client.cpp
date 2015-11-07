#include <iostream>
#include <memory>

#include "WSocket.hh"

typedef std::auto_ptr<ISocket> Socket;

/*
	CLIENT
 */
int		main(int ac, char **av)
{
  Socket	client(new WSocket());
  char		buffer[2014];
  int		len;

  client->init();
  try {
    client->connectToServer("127.0.0.1", "4242");
  } catch(...) {
		std::cerr << "connect process failed\n";
		return 1;
  }
  len = client->recvData(buffer, sizeof(buffer));
  std::cout << std::string(buffer, len) << std::endl;
  client->end();
  return (0);
}
