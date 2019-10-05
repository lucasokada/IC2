#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void posiciona_ponteiro_arquivo(FILE *file)
{
    fseek(file, 0, SEEK_END);  //posiciona ponteiro arquivo no fim do arquivo
}

void realoca_memoria(char *caractere, int tamanho)
{
    realloc(caractere, tamanho * sizeof(char));
}

int percorre_arquivo(char *caractere)
{
    int size = 0;
    int quantidade_fim_arquivo = 1, caractere_auxiliar;
    FILE *file, *file_inicio;

    file = fopen("arquivo.txt", "r");
    file_inicio = fopen("arquivo.txt", "r");

    posiciona_ponteiro_arquivo(file);   //ponteiro posicionado no fim do arquivo

    while(quantidade_fim_arquivo <= 1){

        //printf("dentro de while\n");
        
        if(fseek(file, -1 * sizeof(char), SEEK_CUR) != 0){
            quantidade_fim_arquivo++;
            //printf("dentro de if\n");
        }else{

            //fseek(file, -1 * sizeof(char), SEEK_CUR);
        caractere_auxiliar = getc(file);
        printf("%c", caractere_auxiliar);
        //fseek(file, -1 * sizeof(char), SEEK_CUR);

        if(fseek(file, -1 * sizeof(char), SEEK_CUR) != 0){
            quantidade_fim_arquivo++;
            //printf("dentro de if\n");
        }else{
            
            caractere[size] = caractere_auxiliar;
            size++;
            realoca_memoria(caractere, size);
           // printf("dentro de else\n");
        }                
    }

        
    }

    return size;
}

void printa(char *caractere, int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%c", caractere);
    }
}

int main()
{
    char *caractere;
    int tamanho;
    
    caractere = malloc(sizeof(char)); //alocando um bloco de memoria com o tamanho de um char em bytes

    tamanho = percorre_arquivo(caractere);

    //printa(caractere, tamanho);
}