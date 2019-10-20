#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    int matriculo;
    char nome[100];
    struct aluno *next;
} aluno;

void inserir_lista(aluno **head, int id)
{
    aluno *new_node = (aluno *)malloc(sizeof(aluno));

    new_node->matriculo = id;
    strcpy(new_node->nome, "teste 123");
    new_node->next = NULL;

    aluno *current = *head;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
    }
}

void remover_lista(aluno **head, int id)
{
    aluno *current = *head;
    aluno *previous = *head;
    int achou = 0;

    while (!achou && current != NULL)
    {
        if (current->matriculo == id)
        {
            if ((*head)->matriculo == current->matriculo)
            {
                *head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            free(current);
            achou = 1;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if (!achou)
    {
        printf("Chave %d nao encontrada na lista!", id);
    }
}

void imprime_lista(aluno *head)
{
    aluno *current = head;

    while (current != NULL)
    {
        printf("\n%d \n", current->matriculo);
        puts(current->nome);

        current = current->next;
    }
}

int main()
{
    aluno *head = NULL;

    remover_lista(&head, 1);

    inserir_lista(&head, 1);
    //imprime_lista(head);

    inserir_lista(&head, 2);
    //imprime_lista(head);

    remover_lista(&head, 2);
    imprime_lista(head);

    return 0;
}