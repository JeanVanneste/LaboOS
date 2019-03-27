#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/wait.h>
#include <sys/types.h>

#define ARRAY_SIZE 20

void readArray(int array[], int arraySize);

int main(){
    char* filePath = "./data";
    const int arraySize = ARRAY_SIZE;
    int array[ARRAY_SIZE];

    // Read file
    FILE* file = fopen(filePath, "r");
    if (file == NULL){ return 1; }
    else
    {
        for (int i = 0; i<ARRAY_SIZE; i++)
        {
            fscanf(file, "%d", &array[i]);
        }
    }
    readArray(array, arraySize);
    
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

void readArray(int array[], int arraySize)
{
    for (int i = 0; i<arraySize; i++)
    {
        printf("%d\n", array[i]);
    }
}
