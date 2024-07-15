#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1024
char *allocatedStrings[MAX_STRINGS];
int numAllocatedStrings = 0;

char *my_strdup(const char *s)
{
    char *dup = strdup(s);
    if (dup != NULL)
    {
        if (numAllocatedStrings < MAX_STRINGS)
        {
            allocatedStrings[numAllocatedStrings++] = dup;
        }
        else
        {
            fprintf(stderr, "Error: Too many allocated strings\n");
            exit(EXIT_FAILURE);
        }
    }
    return dup;
}

void freeAllStrings()
{
    for (int i = 0; i < numAllocatedStrings; i++)
    {
        free(allocatedStrings[i]);
    }
    numAllocatedStrings = 0;
}