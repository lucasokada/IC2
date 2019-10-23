#include <stdio.h>
#include <stdlib.h>

enum Combustivel {gasolina = 1, alcool, diesel};

struct Dados_automoveis
{
    int codigo_carro;
    char marca[50];
    char tipo[50];
    char ano[4];
    enum Combustivel combustivel;
    float preco_venda;  
};

struct Dados_automoveis preenche_dados()
{
    struct Dados_automoveis dados;

    printf("codigo carro:\n");
    scanf("%d", &dados.codigo_carro);

    printf("marca: \n");
    scanf(" %[^\n]", dados.marca);

    printf("tipo:\n");
    scanf(" %[^\n]", dados.tipo);

    printf("ano:\n");
    scanf(" %[^\n]", dados.ano);

    printf("combustivel usado:\n1 - gasolina\n2 - alcool\n3 - diesel\n");
    scanf("%d", &dados.combustivel);

    printf("preco:\n");
    scanf("%f", &dados.preco_venda);

    return dados;
}

void grava_arquivo(struct Dados_automoveis dados)
{
    FILE *file;

    file = fopen("cadastro_carros.txt", "a");

    fwrite(&dados, sizeof(dados), 1, file);

    fclose(file);
}

void mostra_cadastro()
{
    struct Dados_automoveis dados_lidos;

    FILE *file;

    file = fopen("cadastro_carros.txt", "r");

    while(fread(&dados_lidos, sizeof(dados_lidos), 1, file) == 1)
    {
        printf("%d -", dados_lidos.codigo_carro);
        printf("%s -", dados_lidos.marca);
        printf("%s -", dados_lidos.tipo);
        printf("%s -", dados_lidos.ano);
        printf("%d -", dados_lidos.combustivel);
        printf("%.2f -", dados_lidos.preco_venda);
    }
    printf("\n");

    fclose(file);
}

int codigo_desejado()
{
    int codigo_desejado;

    printf("digite o codigo desejado:\n");
    scanf("%d", &codigo_desejado);

    return codigo_desejado;
}

int verifica_existencia(int codigo)
{
    FILE *file;
    int contador = 0, existe = -1;
    struct Dados_automoveis dados_lidos;

    printf("antes de while\n");

    while(fread(&dados_lidos, sizeof(dados_lidos), 1, file) == 1 && existe == -1)
    {
        printf("dentro de while\n");
        existe = codigo == dados_lidos.codigo_carro ? contador : -1;
        contador++;
    }
    printf("depois de while\n");

    if(existe != -1){
        printf("contador :%d\n", contador);
    }else{
        printf("nao achado\n");
    }

    return existe;
}

void posiciona_ponteiro(FILE *file, int tamanho)
{
    struct Dados_automoveis dados_lidos;

    fseek(file, /*tamanho * sizeof(dados_lidos)*/ 0, SEEK_SET);    
}

void printa_informacao_escolhida()
{ 
    struct Dados_automoveis dados_lidos;
    int codigo, existe = -1, contador;

    FILE *file;

    file = fopen("cadastro_carros.txt", "r");

    printf("digite o codigo:\n");
    scanf("%d", &codigo);

    while(fread(&dados_lidos, sizeof(dados_lidos), 1, file) == 1 && existe == -1)
    {
        printf("dentro de while\n");
        existe = codigo == dados_lidos.codigo_carro ? contador : -1;
        contador++;
    }
    printf("depois de while\n");

    if(existe != -1){
        printf("contador :%d\n", contador);
    }else{
        printf("nao achado\n");
    }


    if(existe != -1){

        fseek(file, contador * sizeof(dados_lidos), SEEK_SET);
        fread(&dados_lidos, sizeof(dados_lidos), 1, file);

        printf("%d -", dados_lidos.codigo_carro);
        printf("%s -", dados_lidos.marca);
        printf("%s -", dados_lidos.tipo);
        printf("%s -", dados_lidos.ano);
        printf("%d -", dados_lidos.combustivel);
        printf("%.2f -", dados_lidos.preco_venda);

        printf("\n");
    }

    fclose(file);
}

int main()
{
    struct Dados_automoveis dados;

    //dados = preenche_dados();
    //grava_arquivo(dados);
    mostra_cadastro();
    printf("\n");

    printa_informacao_escolhida();
}