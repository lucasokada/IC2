#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_conjunto conjunto;

struct tipo_conjunto
{
    int numero;
    conjunto *next;
};

int determina_tamanho()
{
    int size;

    scanf("%d", &size);

    return size;
}

void cria_lista(conjunto **head, int size)
{
    if (size != 0)
    {

        conjunto *current; //ponteiro auxiliar
        conjunto *new_node;

        new_node = (conjunto *)malloc(sizeof(conjunto)); //aloca novo nó na memoria

        scanf("%d", &new_node->numero);
        new_node->next = NULL;

        if (*head == NULL)
        {
            *head = new_node;
        
        }else{
            
            current = *head;

            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = new_node;
        }
    }
}

void cria_conjunto(conjunto **head, int size)
{
    int aux_size = 1;

    do
    {
        cria_lista(head, size);
        aux_size++;

    } while (aux_size <= size);
}

void remove_repetido(conjunto *head)
{
    conjunto *fix_pointer, *current_pointer, *prev_pointer;

    fix_pointer = head;

    while (fix_pointer != NULL)
    {
        current_pointer = fix_pointer->next;
        prev_pointer = fix_pointer;

        while (current_pointer != NULL)
        {
            if (fix_pointer->numero == current_pointer->numero)
            {
                prev_pointer->next = current_pointer->next;
                free(current_pointer);

                current_pointer = prev_pointer;
            }

            prev_pointer = current_pointer;
            current_pointer = current_pointer->next;
        }

        fix_pointer = fix_pointer->next;
    }
}

void diferenca(conjunto *head_x, conjunto *head_y, conjunto **head_diferenca)
{
    conjunto *current_x, *current_y, *current_diferenca, *new_node_diferenca;
    int repetido;

    current_x = head_x; 

    while (current_x != NULL) 
    {
        repetido = 0;
        current_y = head_y; 

        while (current_y != NULL && repetido == 0)
        {
            if (current_x->numero == current_y->numero) 
            {
                repetido = 1;

            }else{

                current_y = current_y->next;
            }
        }

        if (repetido == 0)  
        {
            //adiciona_conjunto(&head_diferenca, current_x);

            new_node_diferenca = (conjunto *)malloc(sizeof(conjunto));
            
            if(*head_diferenca == NULL){

                *head_diferenca = new_node_diferenca;

            }else{

                current_diferenca = *head_diferenca;

                while(current_diferenca->next != NULL)
                {
                    current_diferenca = current_diferenca->next;
                }

                current_diferenca->next = new_node_diferenca;
            }

            new_node_diferenca->numero = current_x->numero;
            new_node_diferenca->next = NULL;
        }

        current_x = current_x->next; 
    }
}

void diferenca_simetrica(conjunto *head_x, conjunto *head_y, conjunto **head_simetrico)
{
    conjunto *current_simetrico;

    *head_simetrico = head_x;

    current_simetrico = head_x;

    while(current_simetrico->next != NULL)
    {
        current_simetrico = current_simetrico->next;
    }

    current_simetrico->next = head_y;
}

void printa_lista(conjunto *head)
{
    conjunto *current;

    current = head;

    while (current != NULL)
    {
        printf("%d ", current->numero);

        current = current->next;
    }
}

int main()
{
    int size_A, size_B;
    conjunto *head_A = NULL, *head_B = NULL;
    conjunto *head_AB = NULL, *head_BA = NULL;
    conjunto *head_simetrico = NULL;

    size_A = determina_tamanho();
    cria_conjunto(&head_A, size_A);

    size_B = determina_tamanho();
    cria_conjunto(&head_B, size_B);

    remove_repetido(head_A);
    remove_repetido(head_B);

    //A-B
    if (size_A != 0)
    {
        diferenca(head_A, head_B, &head_AB);
        printa_lista(head_AB);
        printf("\n");
    }
    else
    {

        printf("\n");
    }

    //B-A
    if (size_B != 0)
    {
        diferenca(head_B, head_A, &head_BA);
        printa_lista(head_BA);
        printf("\n");
    }
    else
    {

        printf("\n");
    }

    if(size_A != 0){

        diferenca_simetrica(head_AB, head_BA, &head_simetrico);
        printa_lista(head_simetrico);

    }else{

        diferenca_simetrica(head_BA, head_AB,&head_simetrico);
        printa_lista(head_simetrico);
    }
}