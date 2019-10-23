#include <stdio.h>
#include <stdlib.h>

int digita_decimal()
{
    int num;

    scanf("%d", &num);

    return num;
}

int binario(int num, int *vet, int count)
{
    int dividendo, resto, quociente;

    if(num == 1){

        vet[count] = 1;

        printf("1\n");
        printf("vet %d\n", vet[count]);
        return count;

    }else{
        
        dividendo = num;

        resto = dividendo % 2;

        quociente = dividendo / 2;

        vet[count] = resto;

        printf("vet %d\n", vet[count]);

        printf("resto: %d\n ", resto);

        count++;

        return binario(quociente, vet, count);
    }
}

int main()
{
    int decimal, vetor[100], vetor_inverte[100], count = 0, tamanho, i, j;

    printf("digite o numero decimal\n");
    decimal = digita_decimal();

    tamanho = binario(decimal, vetor, count);
    printf("tamanho %d\n", tamanho);

    printf("vet em main:\n");
    
    for(i=0; i <= tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("vetor inverte:\n");
    j=0;
    for(i=tamanho; i >= 0; i--)
    {
        vetor_inverte[j] = vetor[i];
        printf("%d ", vetor_inverte[j]);
        j++;
    }
}