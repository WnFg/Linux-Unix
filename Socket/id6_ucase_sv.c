#include "id6_ucase.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	struct sockaddr_in6 svaddr, claddr;
	int sfd, j;
	ssize_t numBytes;
	socklen_t len;
	char buf[BUF_SIZE];
	char claddrStr[INET6_ADDRSTRLEN];

	sfd = socket(AF_INET6, SOCK_DGRAM, 0);
	if( sfd == -1 ){
		printf("%s\n", "create sfd!");
		exit(EXIT_FAILURE);
	}
	//printf("sdfsdf \n");
	memset(&svaddr, 0, sizeof(struct sockaddr_in6));
	svaddr.sin6_family = AF_INET6;
	svaddr.sin6_addr = in6addr_any;
	svaddr.sin6_port = htons(PORT_NUM);

	if(bind(sfd, (struct sockaddr*) &svaddr, sizeof(struct sockaddr_in6)) == -1){
		printf("%s\n", "bind!");
		exit(EXIT_FAILURE);
	}

	for(;;){
		len = sizeof(struct sockaddr_in6);
		numBytes = recvfrom(sfd, buf, BUF_SIZE, 0, (struct sockaddr*)&claddr, &len);
		if(numBytes == -1){
			printf("recvfrom\n");
			exit(EXIT_FAILURE);
		}
		buf[numBytes++] = '\0';	
		printf("SV recvfrom: %s\n", buf);
		system(buf);
		if(inet_ntop(AF_INET6, &claddr.sin6_addr, claddrStr,
					INET6_ADDRSTRLEN) == NULL){
			printf("inet_ntop\n");
			exit(EXIT_FAILURE);
		}else{
			printf("Server received %ld bytes from (%s, %u)\n", (long)numBytes, claddrStr, ntohs(claddr.sin6_port));
		}

		for(j = 0; j < numBytes; j++)
			buf[j] = toupper((unsigned char) buf[j]);

		if(sendto(sfd, buf, numBytes, 0, (struct sockaddr *)&claddr, len) != numBytes){
			printf("sendto\n");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
