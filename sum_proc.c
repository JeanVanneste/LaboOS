#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/wait.h>
#include <sys/types.h>

void readFile(char* filePath, int array[], int arraySize);

int main(){
	char* filePath = "data";
	const int arraySize = 100;
	int array[arraySize];

	readFile(filePath, array, arraySize);

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

void readFile(char* filePath, int array[], int arraySize)
{
	for (int i = 0; i<arraySize; i++)
	{
		array[i] = NULL;
	}
	FILE* file = fopen(filePath, "r");
	char buffer[20];


	fclose(file);
}
