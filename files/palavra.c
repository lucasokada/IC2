#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50];
    FILE *file;

    file = fopen("palavras.txt", "r");

    while(/*fread(string, sizeof(string), 1, file)*/ fscanf(file, "%s", string) != EOF){
        printf("%s\n", string);
    }

    fclose(file);
}