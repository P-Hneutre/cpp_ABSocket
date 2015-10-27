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

void	USocket::setHostName(std::string host)
{
	this->_host = host;
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
		perror("socket()");
		exit(errno);
	}


	hostinfo = gethostbyname(hostname); /* on récupère les informations de l'hôte auquel on veut se connecter */
	if (hostinfo == NULL) /* l'hôte n'existe pas */
	{
		fprintf(stderr, "Unknown host %s.\n", hostname);
		exit(EXIT_FAILURE);
	}

	sin.sin_addr = *(IN_ADDR *)hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
	sin.sin_port = htons(PORT); /* on utilise htons pour le port */
	sin.sin_family = AF_INET;

	if (connect(sock, (SOCKADDR *)&sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		perror("connect()");
		exit(errno);
	}


}

bool	USocket::connectFromAcceptedFd(int fd)
{

}

int		USocket::recv(std::string buffer, int size)
{

}
int 	USocket::send(std::string  data)
{

}