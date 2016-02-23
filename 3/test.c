#include <stdlib.h>
#include <stdio.h>
#include "ugid_functions.h"

int main(int argc, char **argv)
{	
	if(argc == 1)
		exit(-1);
	int x = 0, t = 1;
	int i;
	for(i = strlen(argv[1]) - 1; i >=0; i--){
		x += (argv[1][i] - '0')*t;
		t *= 10;
	}
	printf("%s\n", userNameFromId(x));
	return 0;
}
