#include "id6_ucase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	struct sockaddr_in6 svaddr;
	int sfd, j;
	size_t msgLen;
	ssize_t numBytes;
	char resp[BUF_SIZE];

	if(argc < 3 || strcmp(argv[1], "--help") == 0){
		printf("~~~~~~~~~~\n");
		exit(EXIT_FAILURE);
	}

	sfd = socket(AF_INET6, SOCK_DGRAM, 0);
	if(sfd == -1){
		printf("socket\n");
		exit(EXIT_FAILURE);
	}

	memset(&svaddr, 0, sizeof(struct sockaddr_in6));
	svaddr.sin6_family = AF_INET6;
	svaddr.sin6_port = htons(PORT_NUM);

	if(inet_pton(AF_INET6, argv[1], &svaddr.sin6_addr) <= 0){
		printf("inet_pton\n");
		exit(EXIT_FAILURE);
	}

	for(j = 2; j < argc; j++){
		msgLen = strlen(argv[j]);
		if(sendto(sfd, argv[j], msgLen, 0, (struct sockaddr*)&svaddr, sizeof(struct sockaddr_in6)) != msgLen){
			printf("sendto\n");
			exit(EXIT_FAILURE);
		}

		numBytes = recvfrom(sfd, resp, BUF_SIZE, 0, NULL, NULL);
		if(numBytes == -1){
			printf("recvfrom\n");
			exit(EXIT_FAILURE);
		}

		printf("%s\n", resp);
	}

	exit(EXIT_SUCCESS);
}
