#include <stdlib.h>
#include <stdio.h>
#include "ugid_functions.h"
#include <sys/socket.h>
#include <sys/un.h>
#include "tlpi_hdr.h"
#include <signal.h>
//#include <stddef.h>
static void sigHandler(int sig)
{
	printf("Ouch!\n");
}

int main()
{
	int j;
	if(signal(SIGINT, sigHandler) == SIG_ERR)
		errExit("signal");

	for(j = 0; ; j++){
		printf("fdsf\n");
		sleep(3);
	}
	return 0;
}
