#include <stdio.h>
#include <stdio.h>

int main()
{
    int tamanho = 5;
    int vet1[5], vet2[5];
    int num[5];
    int i=0;

    FILE *file;

    file = fopen("teste.txt", "w");

    while(fscanf(file, "%d", &vet1[i]) != EOF && i < 5)
    {
        printf("digite o valor:\n");
        scanf("%d", &vet1[i]);

        fprintf(file, "%d", vet1[i]);

        i++;
    }

    fclose(file);
}