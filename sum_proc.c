#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

#define ARRAY_SIZE 20

void readArray(int array[], int arraySize);

int p[2];
char buffer[6];

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
//    readArray(array, arraySize);

    pipe (p);
    pid_t pid = fork();

    if (pid < 0){ printf("Error"); }
    else if (pid == 0)
    {
        int recv[4];

        close (p[1]);
        read (p[0], &recv[0], sizeof(recv[0]));
        close (p[0]);

        //buffer[5] = '\0';

        int child_result = 0;
        for (int i = 0; i<arraySize; i++)
        {
            if (i>10)
            {
                child_result+=array[i];
            }
        }
        printf("child recv: %d\n", recv[0]);

        int total_sum = child_result + recv[0];
        printf("child result: %d\n", child_result);
        printf("total sum: %d\n", total_sum);
    }
    else
    {
        close (p[0]);


        int parent_result = 0;
        for (int i = 0; i<arraySize; i++)
        {
            if (i<10)
            {
                parent_result+=array[i];
            }
        }

        write (p[1], &parent_result, sizeof(parent_result));
        close (p[1]);

        printf("parent result: %d\n", parent_result);
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

