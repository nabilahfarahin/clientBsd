#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>

#define PORT 3490
#define MAXDATASIZE 300

int main(int argc,char *argv[])
{
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct hostent *he;
	struct sockaddr_in serv_addr;
	
	if(argc !=2)
	{
		fprintf(stderr,"Client-Usage: %s the_client_hostname\n", 
argv[0]); 
		return 1;
	}

if((he=gethostbyname(argv[1])) == NULL)
{
	perror("gethostbyname()");
	return(1);
}
else
	printf("Client-The Remote Host is: %s\n",argv[1]);

if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
{
	perror("socket()");
	return(1);
}
else
	printf("Client-The socket() sockfd is OK...\n");


serv_addr.sin_family = AF_INET;
printf("Server-Using %s and port %d...\n",argv[1], PORT);

serv_addr.sin_port = htons(PORT);
serv_addr.sin_addr = *((struct in_addr *)he->h_addr);

memset(&(serv_addr.sin_zero), '\0', 8);

if(connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(struct 
sockaddr)) == -1)
{
	perror("connect()");
	return 1;
}
else
	printf("Client-The connect() is OK...\n");

if((numbytes=recv(sockfd,buf,MAXDATASIZE-1, 0)) == -1)
{
	perror("recv()");
	return 1;
}
else
	printf("Client-The recv() is OK...\n");

buf[numbytes] = '\0';
printf("Client-Received: %s", buf);

printf("Client-Closing sockfd\n");
close(sockfd);
return 0;

}
