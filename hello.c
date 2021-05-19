#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Hello World\n");
	for(int i =1 ; i < argc; i++)
	{
		printf("\nArg %d has a value %s\n", i, argv[i]);

	}

	return 0;
}
