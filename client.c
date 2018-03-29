#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int clientSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;

clientSocket = socket(PF_INET, SOCK_STREAM, 0);

serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(7891);
serverAddr.sin_addr.s_addr = inet_addr("192.168.61.129");
memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

addr_size= sizeof serverAddr;
connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

printf("Please enter a text: %s", buffer);
scanf("%s", buffer);
send(clientSocket, buffer , 100 , 0);
recv(clientSocket, buffer, 100, 0);

printf("The Server reply : %s", buffer);
return 0;
}
# clientBsd
