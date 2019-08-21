#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum enum_obras {livros = 1, teses = 2, periodicos = 3};

//==================================================

struct tipo_livro_catalogado
{
    char autor[50];
    char titulo[50];
    char data[9];
    char editora[50];
    char cidade[50];
};

//==================================================
enum modalidade {mestrado = 1, doutorado = 2};

struct tipo_tese_catalogada
{
    char autor[50];
    char titulo[50]; 
    char data[9];
    char universidade[50];
    char pos_graduacao[50];
    enum modalidade enum_modalidade;
    char orientador[50];
};

//==================================================

enum mes {Janeiro = 1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Dezembro};

struct tipo_periodico_catalogado
{
    char titulo[50];
    char volume[50];
    enum mes enum_mes;
    char ano[4];
    char editora[50];
    char cidade[50]; 
    int numero_paginas;
};


//------------------------functions-------------------
int menu()
{
    int opcao;

    printf("----------MENU----------\n");
    printf("1 - livro\n");
    printf("2 - tese\n");
    printf("3 - periodicos\n");
    printf("4 - sair\n");
    printf("-------------------------\n");
    printf("digite a opçao desejada: \n");
    scanf("%d", &opcao);

    return (opcao);
}

void cadastra_livros(struct tipo_livro_catalogado livro_catalogado[], int *count_livros) //OPÇAO 1
{
    printf("A opçao escolhida foi livros\n");

    printf("Digite o nome do autor:\n");
    scanf("%s", livro_catalogado[*count_livros].autor);
    printf("Digite o título da obra:\n");
    scanf("%s", livro_catalogado[*count_livros].titulo);
    printf("Digite a data de publicação da obra:\n");
    scanf("%s", livro_catalogado[*count_livros].data);
    printf("Digite o nome da editora:\n");
    scanf("%s", livro_catalogado[*count_livros].editora);
    printf("Digite a cidade em que o autor vive:\n");
    scanf("%s", livro_catalogado[*count_livros].cidade);
    (*count_livros)++; //TAMANHO DO VETOR LIVROS

}

void cadastra_tese(enum modalidade enum_modalidade, struct tipo_tese_catalogada tese_catalogada[], int *count_teses)//opcao 2
{

    printf("A opçao escolhida foi teses\n");
    printf("Digite o nome do autor:\n");
    scanf("%s", tese_catalogada[*count_teses].autor);
    printf("Digite o título da tese:\n");
    scanf("%s", tese_catalogada[*count_teses].titulo);
    printf("Digite a data de publicação da tese:\n");
    scanf("%s", tese_catalogada[*count_teses].data);
    printf("Digite a universidade da publicaçao:\n");
    scanf("%s", tese_catalogada[*count_teses].universidade);
    printf("Digite a área de pós-graduaçao\n");
    scanf("%s", tese_catalogada[*count_teses].pos_graduacao);
    printf("Digite a modalidade da pós-graduaçao\n");
    printf("1 - Mestrado\n2 - Doutorado\n");
    scanf("%d", &tese_catalogada[*count_teses].enum_modalidade);
    
    switch(tese_catalogada[*count_teses].enum_modalidade)
    {
        case 1:
            printf("A opçao escolhida foi MESTRADO\n");
            break;
        case 2:
            printf("A opçao escolhida foi DOUTORADO\n");
            break;
    }
    printf("Digite o nome do orientador:\n");
    scanf("%s", tese_catalogada[*count_teses].orientador);
    (*count_teses)++;//TAMANHO DO VETOR TESES
}

void cadastra_periodico(enum mes enum_mes, struct tipo_periodico_catalogado periodico_catalogado[], int *count_periodicos)//opcao 3
{
    printf("A opçao escolhida foi periodicos\n");
    printf("Digite o título do periodico:\n");
    scanf("%s",periodico_catalogado[*count_periodicos].titulo);
    printf("Digite o volume do periodico:\n");
    scanf("%s", periodico_catalogado[*count_periodicos].volume);
    printf("Digite o mes de 1 - 12:\n");
    scanf("%d", &periodico_catalogado[*count_periodicos].enum_mes);
    switch (periodico_catalogado[*count_periodicos].enum_mes)
    {
        case 1:
            printf("Janeiro\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 2:
            printf("%Fevereiro\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 3:
            printf("Março\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 4:
            printf("Abril\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 5:
            printf("Maio\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 6:
            printf("Junho\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 7:
            printf("Julho\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 8:
            printf("Agosto\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 9:
            printf("Setembro\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 10:
            printf("Outubro\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 11:
            printf("Novembro\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
        case 12:
            printf("Dezembro\n", periodico_catalogado[*count_periodicos].enum_mes);
            break;
    }
    printf("Digite o ano:\n");
    scanf("%s", periodico_catalogado[*count_periodicos].ano);
    printf("Digite a editora\n");
    scanf("%s", periodico_catalogado[*count_periodicos].editora);
    printf("Digite a cidade:\n");
    scanf("%s", periodico_catalogado[*count_periodicos].cidade);
    printf("Digite o numero de paginas:\n");
    scanf("%d", &periodico_catalogado[*count_periodicos].numero_paginas);
    (*count_periodicos)++;  //tamanho do vetor periodicos
}


//---------------------------main-------------------------

int main()
{
    int opcao, count_livros = 0, count_teses = 0, count_periodicos = 0;
    
    enum enum_obras obras;
    struct tipo_livro_catalogado livro_catalogado[count_livros];
    enum modalidade enum_modalidade;
    struct tipo_tese_catalogada tese_catalogada[count_teses];
    enum mes enum_mes;
    struct tipo_periodico_catalogado periodico_catalogado[count_periodicos];

    do{
        do{                                                        //{ verifica se a opçao é valida
            opcao = menu();
            if(opcao < 1 || opcao > 4){
                printf("Opçao indisponivel. Tente novamente\n\n");
            }                                                               
        }while(opcao < 1 && opcao > 4);                           //}

        obras = opcao;
        switch(obras)
        {
            case 1:                                     //CADASTRO DOS LIVROS   
                cadastra_livros(livro_catalogado, &count_livros);
                break;
            case 2:
                cadastra_tese(enum_modalidade, tese_catalogada, &count_teses);
                break;
            case 3:
                cadastra_periodico(enum_mes, periodico_catalogado, &count_periodicos);
        }   

    }while(opcao != 4);

}
