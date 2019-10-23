#include <stdio.h>
#include <stdio.h>

void inicializa_vetor(int tamanho, int *vet)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        scanf("%d", &vet[i]);
    }
}

void preenche_arquivo1(int tamanho, int *vet)
{
    int i;
    FILE *file;

    file = fopen("arq1.txt", "w");

    for(i=0; i<tamanho; i++)
    {
        fprintf(file, "%d ", vet[i]);
    }
}


void preenche_arquivo2(int tamanho, int *vet)
{
    int i;
    FILE *file;

    file = fopen("arq2.txt", "w");

    for(i=0; i<tamanho; i++)
    {
        fprintf(file, "%d ", vet[i]);
    }
}

void preenche_vet3(int *vet1, int *vet2, int *vet3)
{
    int i;

    FILE *file1, *file2;

    file1 = fopen("arq1.txt", "r");

    i = 0;
    while(fscanf(file1, "%d", &vet1[i]) != EOF && i < 5)
    {
        if(i == 0){    
            vet3[i] = vet1[1];
        }else{
            vet3[i+2] = vet1[1];
        }

        i++;
    }
    fclose(file1);

    file2 = fopen("arq2.txt", "r");

    i=1;
    while(fscanf(file1, "%d", &vet1[i]) != EOF && i < 5)
    {
        if(i == 1){    
            vet3[i] = vet1[1];
        }else{
            vet3[i+2] = vet1[1];
        }

        i++;
    }
    fclose(file2);

}

void preenche_arquivo3(int tamanho, int *vet)
{
    int i;
    FILE *file;

    file = fopen("arq3.txt", "w");

    for(i=0; i<tamanho; i++)
    {
        fprintf(file, "%d ", vet[i]);
    }
}

int main()
{
    int tamanho = 5;
    int vet1[5], vet2[5], vet3[10];
    int num[5];
    int i=0;

    printf("digite os valores do vetor 1:\n");
    inicializa_vetor(tamanho, vet1);
    preenche_arquivo1(tamanho, vet1);

    printf("digite os valores do vetor 2:\n");
    inicializa_vetor(tamanho, vet2);
    preenche_arquivo2(tamanho, vet2);

    preenche_vet3(vet1, vet2, vet3);
    preenche_arquivo3(2*tamanho, vet3);
}