#include <stdio.h>
#include <stdlib.h>

int digita_numero()
{
    int n;

    printf("digite o numero que deseja converter:\n");
    scanf("%d", &n);

    return n;
}

int transforma_binario(int n)
{
    int *resto, quociente, dividendo;
    int contador = 0;

    n = quociente;

    if(quociente != 0){

        dividendo = quociente;

        resto[contador] = dividendo % 2;

        contador++;

        transforma_binario(n);

    }else{

        return contador;
    }
}

int main()
{
    int numero;
    int contador;

    numero = digita_numero();

    contador = transforma_binario(numero);
}