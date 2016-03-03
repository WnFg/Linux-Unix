#include "id6_ucase.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
//	printf("%u\n", inet_addr("1.1.1.1"));
	struct sockaddr_in a;
	printf("%u\n", inet_pton(AF_INET, "1.1.1.1", &a.sin_addr));
	printf("%u\n", a.sin_addr);
	char s[20];
	inet_ntop(AF_INET, &a.sin_addr, s, 20);
	printf("%s\n", s);
	return 0;
}
