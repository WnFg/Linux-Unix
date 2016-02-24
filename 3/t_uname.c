#define _GNU_SOURCE
#include <sys/utsname.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
	struct utsname uts;

	if(uname(&uts) == -1)
		errExit("uname");

	printf("Node name: %s\n", uts.nodename);
	printf("System name: %s\n", uts.sysname);
	printf("Release: %s\n", uts.release);
	exit(EXIT_SUCCESS);
}
