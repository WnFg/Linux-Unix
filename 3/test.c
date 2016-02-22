#include <stdlib.h>
#include <stdio.h>
extern char **environ;
int main(void)
{	
	char **ep;
	for(ep = environ; *ep != NULL; ep++)
		puts(*ep);
	puts(getenv("VIM"));
	char s[] = "asd=123";
	putenv(s);
	puts(getenv("asd"));
	char name[] = "asd";
	char value[] = "456";
	setenv(name, value, 1);
	puts(getenv("asd"));
	return 0;
}
