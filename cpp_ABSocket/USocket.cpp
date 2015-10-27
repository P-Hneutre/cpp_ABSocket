#include "USocket.hh"

USocket::USocket()
{
	this->_fd = 0;
	this->_sockAddr = NULL;
	this->_sockAddrIn = NULL;
	this->_sockIn = NULL;
	this->_hostInfo = NULL;

}

USocket::~USocket()
{

}

void	USocket::setHost(std::string host)
{
	this->_hostInfo = gethostbyname(host);
}

void	USocket::setPort(std::string port)
{
	this->_port = htons(port);
}

std::string	USocket::getHostName()
{
	return (this->_host);
}

short	USocket::getPort()
{
	return (this->_port);	
}

bool	USocket::connectToServer(std::string host, std::string port)
{
	this->setHostName(host);
	this->setPort(port);
	this->_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_fd == INVALID_SOCKET)
	{
		this->_error = INVALID_SOCKET;
		return (false);
	}
	
	if (this->_hostInfo == NULL) 
	{
		this->_error = UNKNOWN_HOST;
		return (false);
	}

	this->_sockAddrIn.sin_addr = *(IN_ADDR *)this->_hostInfo->h_addr;
	this->_sockAddrIn.sin_port = this->_port; 
	this->_sockAddrIn.sin_family = AF_INET;

	if (connect(this->_fd, (SOCKADDR *)&this->_sockAddr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		this->_error = CONNECT_FAIL;
		return (false);
	}
}

bool	USocket::connectFromAcceptedFd(int fd)
{

}

int		USocket::recvData(char	*buffer, int size)
{
	int n = 0;
	if ((n = recv(this->_fd, buffer, size, 0)) < 0)
		this->_error = ERR_RECV;
	buffer[n] = 0;
	return n;
}

int 	USocket::sendData(std::string buffer)
{
	if (send(this->_fd, buffer.c_str() , buffer.size(), 0) < 0)
		this->_error = ERR_SEND;

}

int		USocket::getError()
{
	return (this->_error);
}

void	USocket::end()
{
	closesocket(this->_fd);
}