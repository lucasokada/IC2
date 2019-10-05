#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int *array;
    int array_size, i;

    srand(time(NULL));

    printf("enter the array size:\n");
    scanf("%d", &array_size);

    array = malloc(array_size * sizeof(int));

    for(i=0; i<array_size; i++)
    {
        array[i] = rand() % 10;
        printf("%d ", array[i]);
    }
    
    printf("\n");

    free(array);

    return 0;
}