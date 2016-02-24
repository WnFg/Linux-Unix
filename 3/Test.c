#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("123\n");
	fork();
	printf("456 is %d\n", getppid());
	return 0;
}
