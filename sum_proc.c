#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/wait.h>
#include <sys/types.h>

void readFile(FILE* file, int array[], int arraySize);

int main(){
	FILE* file = fopen("data", "r");
	const int arraySize = 100;
	int array[arraySize];

	readFile(file, array)

	pid_t pid = fork();

	if (pid < 0){ printf("Error"); }
	else if (pid == 0)
	{
		printf("Fils\n");
		execlp("/bin/echo", "echo", "Hello world!", NULL);
	}
	else
	{
		printf("Parents\n");
		wait(NULL);

		printf("Mon fils a fini\n");
	}

	return 0;
}

void readFile(FILE* file, int array[], int arraySize)
{
	for (int i = 0; i<arraySize; i++)
	{
		array[i] = NULL;
	}
}
