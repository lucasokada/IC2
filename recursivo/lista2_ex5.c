#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra[20] = {"palavra"};
    char buff[20];
    char letra;
    int achou = 0, linha = 0;
    long posicao;

    FILE *file;

    file = fopen("arquivoTest.txt", "r");

    while(fscanf(file, "%s", buff) != EOF && achou == 0)
    {
        if(strcmp(buff, palavra) == 0){
            achou = 1;
            posicao = ftell(file);
        }
    }

    fseek(file, 0, SEEK_SET);

    while(fscanf(file, "%c", &letra) != EOF && fseek(file, 0, SEEK_CUR) != posicao)
    {
        if(letra == '\n'){
            linha++;
        }
    }

    printf("achou %d\n", achou);
    printf("linha %d\n", linha);

    fclose(file);
}