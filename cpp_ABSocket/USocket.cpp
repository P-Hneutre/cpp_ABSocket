#include "USocket.hh"



USocket::USocket()
{
}


USocket::~USocket()
{
}


int	USocket::AbConnectToServer(std::string domain, short port, std::string protocol) {

}

int	USocket::AbSocket(int domain, int host, int protocol) {
	return (socket(domain, host, protocol));
}

int	USocket::AbBind(SOCKET socket, const struct sockaddr *addr, size_t addrlen) {
	return (bind(socket, addr, addrlen));
}

int	USocket::AbListen(SOCKET socket, int backlog) {
	return (listen(socket, backlog));
}

int	USocket::AbConnect(SOCKET socket, const struct sockaddr *addr, size_t addrlen) {
	return (connect(socket, addr, addrlen));
}

int	USocket::AbAccept(SOCKET socket, struct sockaddr *addr, size_t *addrlen) {
	return (accept(socket, addr, (socklen_t *)addrlen));
}

int	USocket::AbSend(SOCKET socket, const void *buffer, size_t size, int flags) {
	return (send(socket, buffer, size, flags));
}

int	USocket::AbRecv(SOCKET socket, void *buffer, size_t size, int flags) {
	return (recv(socket, buffer, size, flags));
}

int	USocket::AbSendTo(SOCKET socket, const void *buffer, size_t size, int flags, const struct sockaddr *sockaddr, size_t sockaddrlen) {
	return (sendto(socket, buffer, size, flags, sockaddr, sockaddrlen));
}



int	USocket::AbRecvFrom(SOCKET socket, void *buffer, size_t size, int flags, struct sockaddr *sockaddr, size_t *sockaddrlen) {
	return (recvfrom(socket, buffer, size, flags, sockaddr, (socklen_t *)sockaddrlen));
}
