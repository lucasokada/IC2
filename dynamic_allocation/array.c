#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *fill_array(int *array, int array_size)
{
    int i = 0;

    srand(time(NULL));

    for(i = 0; i < array_size; i++)
    {
        array[i] = rand() % 50;
    }

    return array;
}

void print_array(int *array, int array_size)
{
    int i;

    for(i = 0; i < array_size; i++)
    {
        printf("%d", array[i]);
        printf("\n");
    }

}

int main()
{
    int *array;
    int array_size;

    printf("enter the array size:\n");
    scanf("%d", &array_size);

    array = malloc(array_size * sizeof(int));

    array = fill_array(array, array_size);

    print_array(array, array_size);

    free(array);

    return 0;
}