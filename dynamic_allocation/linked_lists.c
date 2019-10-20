#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_dados dados;
typedef struct tipo_lista lista;

struct tipo_dados
{   
    char nome[50];
    int idade;
    float peso;
    float altura;
};

struct tipo_lista
{
    dados informacoes;
    lista *next;
};

/*void cria_lista(lista **head)
{
    if(*head != NULL){

        *head = NULL;
    }
}*/

dados preenche_informacoes()
{
    dados informacoes;

    printf("nome\n");
    scanf(" %[^\n]s", informacoes.nome);

    printf("idade\n");
    scanf("%d", &informacoes.idade);

    printf("peso\n");
    scanf("%f", &informacoes.peso);

    printf("altura\n");
    scanf("%f", &informacoes.altura);

    return informacoes;
}

void adiciona_lista(lista **head)
{
    lista *new_node;
    lista *current;

    new_node = (lista *)malloc(sizeof(lista));

    if(*head == NULL){
        
        *head = new_node;

        new_node->informacoes = preenche_informacoes();
        new_node->next = NULL;

    }else{

        current = *head;

        while(current != NULL)
        {
            current = current->next;
        }

        current = new_node;
        new_node->informacoes = preenche_informacoes();
        new_node->next = NULL;
    }
}

int insere_escolha()
{
    int escolha;

    printf("digite escolha\n");
    scanf("%d", &escolha);

    return escolha;
}

int main()
{
    lista *head = NULL;
    int escolha;

    do{
        
        escolha = insere_escolha();

        if(escolha != 0){
            
            adiciona_lista(&head);
        }

    }while(escolha != 0);
}