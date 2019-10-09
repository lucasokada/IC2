#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void posiciona_ponteiro_arquivo(FILE *file)
{
    fseek(file, 0, SEEK_END); //posiciona ponteiro arquivo no fim do arquivo
}

void printa(char *caractere)
{
    int i;

    for (i = 0; i < strlen(caractere); i++)
    {
        printf("%c", caractere[i]);
    }
}

char *retorna_nome_arquivo()
{
    char *nome_arquivo;
    int c;
    int count_char = 0;

    nome_arquivo = (char *)malloc(100 * sizeof(char));

    while ((c = fgetc(stdin)) != '\r' && c != '\n')
    {
        nome_arquivo[count_char] = c;
        count_char++;
    }

    nome_arquivo[count_char] = '\0';

    return nome_arquivo;
}

char *percorre_arquivo()
{
    int size = 0, c, is_valid_fseek = 1;
    FILE *file;
    char *tmp, *retorno, nome_arquivo[250];

    strcpy(nome_arquivo, retorna_nome_arquivo());

    file = fopen(nome_arquivo, "r");

    retorno = (char *)malloc(sizeof(char));

    fseek(file, 0, SEEK_END); //ponteiro posicionado no fim do arquivo

    while (is_valid_fseek)
    {
        //fseek retorna valor diferente de 0, caso o posicionamento do ponteiro falhe.
        //Logo, se falhar, significa que estamos no inicio do arquivo
        if (fseek(file, -1 * sizeof(char), SEEK_CUR) != 0)
        {
            is_valid_fseek = 0;
        }
        else
        {
            c = fgetc(file);
            fseek(file, -1 * sizeof(char), SEEK_CUR);

            retorno[size] = c;

            if (size > 0)
            {
                tmp = (char *)realloc(retorno, strlen(retorno) + 1 * sizeof(char));

                if (tmp != NULL)
                {
                    retorno = tmp;
                }
            }

            size++;
        }
    }

    retorno[size] = '\0';

    fclose(file);
    return retorno;
}

int main(int argc, char *argv[])
{
    char *caractere = percorre_arquivo();
    printa(caractere);

    free(caractere);

    return 0;
}