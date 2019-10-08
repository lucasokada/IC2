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

char *percorre_arquivo(const char *nome_arquivo)
{
    int size = 0;
    int quantidade_fim_arquivo = 1;
    FILE *file;
    char *tmp, *retorno;

    retorno = (char *)malloc(sizeof(char));

    file = fopen(nome_arquivo,  "r");

    posiciona_ponteiro_arquivo(file); //ponteiro posicionado no fim do arquivo

    while (quantidade_fim_arquivo <= 1)
    {
        if (fseek(file, -1 * sizeof(char), SEEK_CUR) != 0)
        {
            quantidade_fim_arquivo++;
        }
        else
        {
            char c = getc(file);

            if (c == '\n')
            {
                fseek(file, -2 * sizeof(char), SEEK_CUR);
                retorno[size] = c;
                size++;
                if (size > 0)
                {
                    tmp = (char *)realloc(retorno, strlen(retorno) + 1 * sizeof(char));

                    if (tmp != NULL)
                    {
                        retorno = tmp;
                    }
                }
            }
            else
            {
                fseek(file, -1 * sizeof(char), SEEK_CUR);
            }

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

const char *retorna_nome_arquivo()
{
    char *nome_arquivo;
    char c;
    int count_char = 0;

    nome_arquivo = (char *)malloc(100 * sizeof(char));

    while ((c = fgetc(stdin)) != EOF && c != '\n')
    {
        nome_arquivo[count_char] = c;
        count_char++;
    }

    nome_arquivo[count_char] = '\0';

    return nome_arquivo;
}

int main()
{
    const char *nome_arquivo = retorna_nome_arquivo();

    char *caractere = percorre_arquivo(nome_arquivo);
    printa(caractere);

    free(caractere);

    return 0;
}