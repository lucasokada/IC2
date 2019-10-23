#include <stdio.h>
#include <stdlib.h>

int preenche_numero()
{
    int n;

    scanf("%d", &n);

    return n;
}

int multiplica(int n1, int n2, int contador, int soma)
{

    if(contador == n2){
        
        return soma;

    }else{

        if(contador > 0)
        {
            soma += n1;
            contador++;

            soma = multiplica(n1, n2, contador, soma);

        }else{

            contador++;
            soma = multiplica(n1, n2, contador, soma);
        }
    } 
}

int main()
{
    int numero1, numero2, multiplicacao, contador = 0, soma = 0;

    printf("digite numero 1:\n");
    numero1 = preenche_numero();

    printf("digite numero 2:\n");
    numero2 = preenche_numero();

    multiplicacao = multiplica(numero1, numero2, contador, soma);
    printf("multiply = %d", multiplicacao);
    
}