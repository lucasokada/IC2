#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **fill_matrix(int **matrix, int line, int column)
{
    int i, j;
    
    srand(time(NULL));

    matrix = malloc(line * sizeof(int *)); /* reservar um bloco de memoria vazio do tamanha declarado
    na funçao malloc para *matrix */


    for(i=0; i<line; i++)
    {
        matrix[i] = malloc(column * sizeof(int)); /* reservar um bloco de memoria vazio do tamanha declarado
        na funçao malloc para **matrix */

        for(j=0; j<column; j++)
        {
            matrix[i][j] = rand() % 100;
        }        
    }

    return matrix;
}

void print_matrix(int **matrix, int line, int column)
{
    int i, j;

    for(i=0; i<line; i++)
    {
        for(j=0; j<column; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int **matrix;   //declaraçao ponteiro de ponteiro. int * -> matrix. int * -> *matrix
    int line, column, i, j;

    srand(time(NULL));

    printf("enter the line size:\n");
    scanf("%d", &line);

    printf("enter de column size:\n");
    scanf("%d", &column);

    matrix = fill_matrix(matrix, line, column);

    print_matrix(matrix, line, column);
    //--------------realloc----------------------

    printf("enter the new line value:\n");
    scanf("%d", &line);

    printf("enter the new column value:\n");
    scanf("%d", &column);

    matrix = realloc(matrix, line * sizeof(int *)); //redimension the line size

    for(i=0; i<line; i++)
    {
        matrix[i] = realloc(*matrix, column * sizeof(int )); //redimension column size

        for(j=0; j<column; j++)
        {
            matrix[i][j] = rand() % 100;
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    free(matrix);

    return 0;
}