#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*typedef struct type_dimension dimension;
typedef struct type_matrix matrix;

struct type_dimension
{
    int line;
    int column;
};

struct type_matrix
{
    dimension dimensions;
    int *element;
};*/

int insert_dimension()
{
    int dimension;

    scanf("%d", &dimension);

    return dimension;
}

bool existence_condition(int lineA, int columnB)
{
    bool exist;

    exist = lineA == columnB ? true : false;

    return exist;
}

void alloc_matrix(int ***matrix, int line, int column)
{
    int i;
    
    matrix = (int **)malloc(line * sizeof(int *));

    for(i=0; i<line; i++)
    {
        matrix[i] = (int *)malloc(column * sizeof(int));
    }
}

int **insert_values(int line, int column)
{
    int i, j;
    int **matrix; 

    srand(time(NULL));

    for(i=0; i<line; i++)
    {
        for(j=0; j<column; j++)
        {
            matrix[i][j] = rand() % 5;
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
    int lineA, columnA, lineB, columnB;
    int **matrixA, **matrixB;
    int **multipy_matrix;
    bool condition;

    printf("line A\n");
    lineA = insert_dimension();
    printf("column A\n");
    columnA = insert_dimension();

    printf("line B\n");
    lineB = insert_dimension();
    printf("column B\n");
    columnB = insert_dimension();

    condition = existence_condition(lineA, columnB);
    
    if(condition != false){

        alloc_matrix(&matrixA, lineA, columnA);
        matrixA = insert_values(lineA, columnA);
        print_matrix(matrixA, lineA, columnA);

        printf("\n");

        /*alloc_matrix(matrixB, lineB, columnB);
        matrixB = insert_values(lineB, columnB);
        print_matrix(matrixB, lineB, columnB);
        */

    }else{
        
        printf("the multiply isn't possible\n");
    }
    
}