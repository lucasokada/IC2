#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//---------------structs, unions e enums--------------

enum obras {livros = 1, teses, periodicos, sair};


struct tipo_livro_catalogado
{
    char autor[20];
    char titulo[20];
    char data[10];
    char editora[20];
    char cidade[20];
};

enum modalidade_graduacao {mestrado = 1, doutorado};

struct tipo_tese_catalogada
{
    char titulo[20];
    char autor[20];
    char data[10];
    char universidade[20];
    char programa_pos_graduacao[20];
    enum modalidade_graduacao modalidade_graduacao;
    char orientador[20];
};

enum mes {Janeiro = 1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Deszembro};

struct tipo_periodico_catalogado
{
    char titulo[20];
    char volume[20];
    enum mes mes;
    char ano[4];
    char editora[20];
    char cidade[20];
    int numero_paginas;
};

union categorias
{
    struct tipo_livro_catalogado livro_catalogado;
    struct tipo_tese_catalogada tese_catalogada;
    struct tipo_periodico_catalogado periodico_catalogado;
};

struct tipo_categoria_escolhida
{
    union categorias union_categorias;
};

//----------------------funçoes-------------------------
int menu(enum obras enum_obras)
{

    printf("-------------------------\n");
    printf("1 - Livros\n");
    printf("2 - Teses\n");
    printf("3 - Periodicos\n");
    printf("4 - Sair\n");
    printf("-------------------------\n");
    printf("Digite a opcao desejada\n");
    scanf("%d", &enum_obras);

    return enum_obras;
}

void cadastrar_livro(struct tipo_categoria_escolhida categoria_escolhida[], int *count)
{
    printf("A opçao escolhida foi LIVROS\n\n");
    printf("Digite o nome do autor:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.livro_catalogado.autor);
    printf("Digite o titulo da obra:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.livro_catalogado.titulo);
    printf("Digite o titulo da data:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.livro_catalogado.data);
    printf("Digite o titulo da editoda:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.livro_catalogado.editora);
    printf("Digite o titulo da cidade:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.livro_catalogado.cidade);
    (*count)++;
}

void cadastrar_teses(struct tipo_categoria_escolhida categoria_escolhida[], int *count)
{
    printf("A opçao escolhida foi TESES\n\n");
    printf("Digite o nome do autor:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.tese_catalogada.autor);
    printf("Digite o titulo da tese:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.tese_catalogada.titulo);
    printf("Digite a data da tese:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.tese_catalogada.data);
    printf("Digite a universidade:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.tese_catalogada.universidade);
    printf("Digite o programa de pos-graduaçao:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.tese_catalogada.programa_pos_graduacao);
    printf("Digite a modalidade da pos-graduaçao:\n");
    scanf("%d", &categoria_escolhida[*count].union_categorias.tese_catalogada.modalidade_graduacao);
    switch (categoria_escolhida[*count].union_categorias.tese_catalogada.modalidade_graduacao)
    {
    case 1:
        printf("A modalidade eh MESTRADO\n");
        break;
    case 2:
        printf("A modalidade eh DOUTORADO\n");
        break;
    }
    printf("Digite o nome do orientador:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.tese_catalogada.orientador);
    (*count)++;
}

void cadastrar_periodicos(struct tipo_categoria_escolhida categoria_escolhida[], int *count)
{
    printf("A opçao escolhida foi PERIODICOS\n\n");
    printf("Digite o nome do titulo:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.titulo);
    printf("Digite o volume:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.volume);
    printf("Digite o mes:\n");
    scanf("%d", &categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
    switch (categoria_escolhida[*count].union_categorias.periodico_catalogado.mes)
    {
    case 1:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 2:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 3:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 4:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 5:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 6:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 7:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 8:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 9:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 10:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 11:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    case 12:
        printf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.mes);
        break;
    }
    printf("Digite o ano:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.ano);
    printf("Digite a editora:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.editora);
    printf("Digite a cidade:\n");
    scanf("%s", categoria_escolhida[*count].union_categorias.periodico_catalogado.cidade);
    printf("Digite o numero de paginas:\n");
    scanf("%d", &categoria_escolhida[*count].union_categorias.periodico_catalogado.numero_paginas);
    (*count)++;
}

void preenche_cadastro(enum obras enum_obras, struct tipo_categoria_escolhida categoria_escolhida[] ,int *count ,int opcao)
{
    do
    {
        opcao = menu(enum_obras);
        switch (opcao)
        {
        case 1:
            cadastrar_livro(categoria_escolhida, &count);
            break;
        case 2:
            cadastrar_teses(categoria_escolhida, &count);
            break;
        case 3:
            cadastrar_periodicos(categoria_escolhida, &count);
            break;
        }

    } while (opcao != 4);
}

void mostra_acervo(struct tipo_categoria_escolhida categoria_escolhida[] ,int *count ,int opcao)
{
    int i;

    if(opcao == 4){
        for(i=0; i < *count; i++)
        {
            categoria_escolhida[i];
        }
    }
}

//========================main============================

int main()
{
    int opcao, count = 0;

    enum obras enum_obras;
    struct tipo_categoria_escolhida categoria_escolhida[count];

    preenche_cadastro(enum_obras,categoria_escolhida , &count ,opcao);
    mostra_acervo(categoria_escolhida, &count ,opcao);
}
