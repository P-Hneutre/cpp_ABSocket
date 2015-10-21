#include "WSocket.hh"

WSocket::WSocket(void) {
	this->_wsaSocket = new WSADATA();
	if (WSAStartup(MAKEWORD(2, 2), _wsaSocket) != 0)
	{
	}
}


WSocket::~WSocket(void) {
	WSACleanup();
	delete (this->_wsaSocket);
}

int	WSocket::AbSocket(int domain, int type, int protocol) {
	return (WSASocket(domain, type, protocol, NULL, 0, NULL));
}

int	WSocket::AbBind(int socket, const struct sockaddr *addr, size_t addrlen) {
	return (bind(socket, addr, addrlen));
}

int	WSocket::AbListen(int socket, int backlog) {
	return (listen(socket, backlog));
}

int	WSocket::AbConnect(int socket, const struct sockaddr *addr, size_t addrlen) {
	return (WSAConnect(socket, addr, addrlen, NULL, NULL, NULL, NULL));
}

int	WSocket::AbAccept(int socket, struct sockaddr *addr, size_t *addrlen) {
	return (WSAAccept(socket, addr, (socklen_t *)addrlen, NULL, NULL));
}

int	WSocket::AbSend(int socket, const void *buffer, size_t size, int flags) {
	LPWSABUF	send_buf = new WSABUF();

	send_buf->buf = (char *)buffer;
	send_buf->len = size;
	if (WSASend(socket, send_buf, 1, &this->_error, flags, NULL, NULL) == SOCKET_ERROR)
		this->_error = SOCKET_ERROR;
	delete (send_buf);
	return (this->_error);
}

int	WSocket::AbSendTo(int socket, const void *buffer, size_t size, int flags, const struct sockaddr *sockaddr, size_t sockaddrlen) {
	LPWSABUF	send_buf = new WSABUF();

	send_buf->buf = (char *)buffer;
	send_buf->len = size;
	if (WSASendTo(socket, send_buf, 1, &this->_error, flags, (SOCKADDR *)sockaddr, sockaddrlen, NULL, NULL) == SOCKET_ERROR)
		this->_error = SOCKET_ERROR;
	delete (send_buf);
	return (this->_error);
}

int	WSocket::AbRecvFrom(int socket, void *buffer, size_t size, int flags, struct sockaddr *sockaddr, size_t *sockaddrlen) {
	LPWSABUF	recv_buf = new WSABUF();
	
	recv_buf->buf = (char *)buffer;
	recv_buf->len = size;
	if (WSARecvFrom(socket, recv_buf, 1, &this->_error, (LPDWORD)(&flags), (SOCKADDR *)sockaddr, (LPINT)sockaddrlen, NULL, NULL) == SOCKET_ERROR)
		this->_error = SOCKET_ERROR;
	delete (recv_buf);
	return (this->_error);
}
