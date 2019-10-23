#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tipo_dados dados;
typedef struct tipo_lista lista;

struct tipo_dados
{   
    /*char nome[50];
    int idade;
    float peso;
    float altura;*/

    int num;
};

struct tipo_lista
{
    dados informacoes;
    lista *next;
};

void menu()
{
    printf("-------------MENU------------\n");
    printf("1 - insere fim\n");
    printf("2 - insere comeco\n");
    printf("3 - insere posicao desejada\n");
    printf("-----------------------------\n");
}

dados preenche_informacoes()
{
    dados informacoes;

    /*printf("nome\n");
    scanf(" %[^\n]s", informacoes.nome);

    printf("idade\n");
    scanf("%d", &informacoes.idade);

    printf("peso\n");
    scanf("%f", &informacoes.peso);

    printf("altura\n");
    scanf("%f", &informacoes.altura);
    */

   printf("numero:\n");
   scanf("%d", &informacoes.num);

    return informacoes;
}

void cria_lista(lista **head)
{
    if(*head != NULL){

        *head = NULL;
    }
}

void insere_lista_fim(lista **head)
{
    lista *new_node;
    lista *current;

    new_node = (lista *)malloc(sizeof(lista));

    new_node->next = NULL;
    
    if(*head == NULL){

        *head = new_node;

    }else{

        current = *head;

        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
    }

    new_node->informacoes = preenche_informacoes();
}

void insere_lista_inicio(lista **head)
{
    lista *current, *new_node;

    current = *head;

    if(*head != NULL){

        new_node = (lista *)malloc(sizeof(lista));
        
        *head = new_node;
        new_node->informacoes = preenche_informacoes();
        new_node->next = current;
    }
}

int posicao_desejada()
{
    int posicao;

    printf("digite a posicao\n");
    scanf("%d", &posicao);

    return posicao;
}

int verifica_tamanho_lista(lista *head)
{
    lista *current;
    int tamanho = 1;

    current = head;

    while(current->next != NULL)
    {
        current = current->next;
        tamanho++;
    }

    printf("tamanho %d\n", tamanho);

    return tamanho;
}

bool verifica_valido(int tamanho, int posicao)
{
    bool valido;

    valido = posicao <= tamanho ? true : false;

    return valido;
}

bool verifica_posicao_encontrada(int pos_atual, int pos_desejada)
{
    bool achou;

    achou = pos_atual == pos_desejada ? true : false;

    return achou;
}

void insere_posicao_desejada(lista **head)
{
    lista *current, *previous, *new_node;
    unsigned int posicao, tamanho_lista, count = 2;
    bool valido, achou;

    current = (*head)->next;
    previous = *head;

    posicao = posicao_desejada();
    tamanho_lista = verifica_tamanho_lista(*head);
    valido = verifica_valido(tamanho_lista, posicao);

    if(valido != true){

        printf("posicao inexistente\n");

    }else{

        if(posicao != 1 && tamanho_lista != 2){

            while(count < posicao && current->next != NULL && achou != true)
            {
                count++;
                current = current->next;    
                previous = previous->next;

                achou = verifica_posicao_encontrada(count, posicao);
            }

            if(achou == true){

                new_node = (lista *)malloc(sizeof(lista));

                previous->next = new_node;
                new_node->informacoes = preenche_informacoes();
                new_node->next = current;

            }else{

                printf("posicao nao encontrada\n");
            }

        }else if(posicao == 1){

            insere_lista_inicio(head);
        
        }else if(tamanho_lista == 2){

            new_node = (lista *)malloc(sizeof(lista));

            previous->next = new_node;
            new_node->informacoes = preenche_informacoes();
            new_node->next = current;
        }
    }

}

void printa_lista(lista *head)
{
    lista *current;

    current = head;

    while(current != NULL)
    {
        /*printf("nome:");
        puts(current->informacoes.nome);
        printf("idade:%d\n", current->informacoes.idade);
        printf("peso:%.2f\n", current->informacoes.peso);
        printf("altura:%.2f\n\n", current->informacoes.altura);*/

        printf("numero : %d\n", current->informacoes.num);

        current = current->next;
    }
}

int valida(int escolha)
{
    int valido;

    valido = escolha > 0 && escolha < 4 ? 1 : 0;

    return valido;
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
    int escolha, valido;

    cria_lista(&head);

    do{

        menu();

        escolha = insere_escolha();

        valido = valida(escolha);

        if(valido != 0){
            
            switch(escolha){
            
                case 1:
                    insere_lista_fim(&head);
                    printf("\n");
                    printa_lista(head);
                    break;
                    
                case 2:
                    insere_lista_inicio(&head);
                    printf("\n");
                    printa_lista(head);
                    break;

                case 3:
                    insere_posicao_desejada(&head);
                    printf("\n");
                    printa_lista(head);
                    break;

                default:
                    break;
            }
        }

    }while(valido != 0);
}