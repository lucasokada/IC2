#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_dados
{
    int matricula;
    char nome[40];
    float salario_bruto;
    float salario_INSS;
    float salario_liquido;
};

void preenche_dados(struct tipo_dados dados_funcionarios[80])
{
    int i;
    for(i=0; i<80; i++)
    {
        printf("matricula %d:\n", i+1);
        scanf("%d", &dados_funcionarios[i].matricula);

        printf("nome:\n");
        scanf(" %[^\n]", dados_funcionarios[i].nome);

        printf("salario bruto:\n");
        scanf("%f", &dados_funcionarios[i].salario_bruto);

        printf("\n\n");
    }
}

void printa_dados_preenchidos(struct tipo_dados dados_funcionarios[80])  //teste
{
    int i;
    for(i=0; i<80; i++)
    {
        printf("%d, %s, %f\n", dados_funcionarios[i].matricula, dados_funcionarios[i].nome, dados_funcionarios[i].salario_bruto);
    }    
}

float deducao_INSS(int posicao, struct tipo_dados dados_funcionarios[80])
{
    dados_funcionarios[posicao].salario_INSS = 0.12 * dados_funcionarios[posicao].salario_bruto;
    
    return dados_funcionarios[posicao].salario_INSS;
}

float func_salario_liquido(int posicao, struct tipo_dados dados_funcionarios[80])
{
    dados_funcionarios[posicao].salario_liquido = dados_funcionarios[posicao].salario_bruto - dados_funcionarios[posicao].salario_INSS;

    return dados_funcionarios[posicao].salario_liquido;
}

void contra_cheque(struct tipo_dados dados_funcionarios[80])
{
    int i;
    float salario_INSS;
    float salario_liquido;

    for(i=0; i<80; i++)
    {
        printf("%d\n", dados_funcionarios[i].matricula);
        printf("%s\n", dados_funcionarios[i].nome);
        printf("%f\n", dados_funcionarios[i].salario_bruto);

        salario_INSS = deducao_INSS(i, dados_funcionarios);
        printf("%f\n", dados_funcionarios[i].salario_INSS); //OBS

        salario_liquido = func_salario_liquido(i, dados_funcionarios);
        printf("%f\n", dados_funcionarios[i].salario_liquido);
        printf("\n\n");
    } 
}


int main()
{
    struct tipo_dados dados_funcionarios[80];

    preenche_dados(dados_funcionarios);
    //printa_dados_preenchidos(dados_funcionarios);   //teste
    contra_cheque(dados_funcionarios);
}
