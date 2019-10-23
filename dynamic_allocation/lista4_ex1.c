#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tipo_lista lista;

struct tipo_lista
{
    int num;
    lista *next;
};

void cria_lista(lista **head)
{
    lista *new_node, *current;

    new_node = (lista *)malloc(sizeof(lista));

    srand(time(NULL));

    if(*head == NULL)
    {
        *head = new_node;

    }else{

        current = *head;

        while(current != NULL)
        {
            current = current->next;
        }

        current = new_node;
    }

    new_node->num = rand() % 5;
    new_node->next = NULL;
}

void printa_lista(lista *head)
{
    lista *current;

    current = head;

    while(current != NULL)
    {
        printf("%d ", current->num);

        current = current->next;
    }
}

int main()
{
    lista *head = NULL;

    cria_lista(&head);
    printa_lista(head);
    printf("\n");
}