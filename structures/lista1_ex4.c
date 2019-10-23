#include <stdio.h>
#include <stdlib.h>
#include <math.h>

union tipo_uniade
{
    double graus;
    double radianos;
};


struct tipo_triangulo
{
    double altura_trianglo;
    double largura_trianglo;
    double hipotenusa_triangulo;
};

struct tipo_executa
{
    struct tipo_triangulo dados_triangulo;
    union tipo_uniade unidade;
};



//  INSERIR A ALTURA DO TRIANGULO
double altura(struct tipo_executa executa) 
{

    printf("digite o valor da altura:\n");
    scanf("%lf", &executa.dados_triangulo.altura_trianglo);

    return executa.dados_triangulo.altura_trianglo;
}

// INSERIR A LARGURA DO TRIANGULO
double largura(struct tipo_executa executa)
{

    printf("digite o valor da largura:\n");
    scanf("%lf", &executa.dados_triangulo.largura_trianglo);

    return executa.dados_triangulo.largura_trianglo;
}

//CALCULA HIPOTENUSA
double calcula_hipotenusa(struct tipo_executa executa)
{
    double altura_triangulo, largura_triangulo, soma_catetos;
    double potencia = 2;

    altura_triangulo = altura(executa);
    largura_triangulo = largura(executa);

    soma_catetos = (pow(altura_triangulo, potencia) + pow(largura_triangulo, potencia));
    
    executa.dados_triangulo.hipotenusa_triangulo = sqrt(soma_catetos);

    return executa.dados_triangulo.hipotenusa_triangulo;

}

double diferenca_lados(struct tipo_executa executa)
{
    double altura_triangulo, largura_triangulo, diferenca;
    
    altura_triangulo = altura(executa);
    largura_triangulo = largura(executa);

    diferenca = altura_triangulo - largura_triangulo;
    if(diferenca < 0){
        diferenca = diferenca * -1;     //modulo do numero
    }

    return diferenca;
}

double soma_lados(struct tipo_executa executa)
{
    double altura_triangulo, largura_triangulo, soma;
    
    altura_triangulo = altura(executa);
    largura_triangulo = largura(executa);

    soma = altura_triangulo + largura_triangulo;

    return soma;
}

//  CONDICAO DE EXISTENCIA DO TRIANGULO
int condicao_existencia(struct tipo_executa executa)
{
    int valido;
    float diferenca;
    float soma;
    double altura_triangulo, largura_triangulo, hipotenusa_triangulo;

    altura_triangulo = altura(executa);
    largura_triangulo = largura(executa);
    hipotenusa_triangulo = calcula_hipotenusa(executa);

    diferenca = diferenca_lados(executa);

    valido = (diferenca < hipotenusa_triangulo) && (hipotenusa_triangulo < soma) ? 1 : 0;
    
    return valido;
}

int main()
{
    struct tipo_executa executa;
}