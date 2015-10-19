#ifndef WSOCKET_HH_
#define WSOCKET_HH_
#ifdef WIN32

#pragma comment(lib,"Ws2_32.lib")	
#include <winsock2.h>
#include <Windows.h>
#include <ws2tcpip.h>
#include <map>

class  Wsocket{
private:	
public:
	void	init(void);
	void	end(void);

}

#endif /*WSOCKET_HH_*/