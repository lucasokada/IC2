#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*fprintf e usado para ESCREVER uma lista formatada de variaveis em um arquivo 
    fprintf(file, "tipo de saida", variaveis); */
/*fscanf e usado para LER uma lista formatada de variaveis em um arquivo
    fscaf(file, "tipo de saida", variaveis); */

struct tipo_matricula_aluno
{
    int matricula;
    char nome_aluno[50];
    float nota1;
    float nota2;
};

void menu()
{
    printf("---------------MENU---------------\n");
    printf("1 - consultar matricula\n");
    printf("2 - mudar notas\n");
    printf("3 - excluir matricula\n");
    printf("4 - sair\n");
    printf("-----------------------------------\n");
}

int escolha()
{
    int escolha;
    printf("escolha a opçao:\n");
    scanf("%d", &escolha);
}

/*void verifica_nota(struct tipo_matricula_aluno matricula_aluno[], int count)
{
    
}*/

int validar_nota(float nota)
{
    return nota < 0 || nota > 10 ? 0 : 1;
}

struct tipo_matricula_aluno montar_aluno(int matricula_digitada)
{
    struct tipo_matricula_aluno aluno;
    float nota;

    aluno.matricula = matricula_digitada;

    printf("digite o nome do aluno: \n");
    scanf(" %[^\n]s", aluno.nome_aluno);

    printf("digite a nota 1 do aluno: \n");
    do
    {
        scanf("%f", &nota);

        if (!validar_nota(nota)){
            printf("nota invalida.tente novamente!\n");
        }else{
            aluno.nota1 = nota;
        }

    } while (!validar_nota(nota));

    printf("digite a nota 2 do aluno: \n");
    do
    {
        scanf("%f", &nota);

        if (!validar_nota(nota)){
            printf("nota invalida.tente novamente!\n");
        }else{
            aluno.nota2 = nota;
        }

    } while (!validar_nota(nota));

    return aluno;
}

void gravar_aluno_arquivo(struct tipo_matricula_aluno aluno)
{
    FILE *file;
    file = fopen("tarefa3.txt", "a"); //cria / acessa arquivo com permissao de escrita

    fprintf(file, "%d", aluno.matricula);
    fprintf(file, " %s", aluno.nome_aluno);
    fprintf(file, " %f", aluno.nota1);
    fprintf(file, " %f \n", aluno.nota2);

    fclose(file);
}

int cadastra_aluno(struct tipo_matricula_aluno matricula_aluno[])
{
    int quantidade_inserida = 0, matricula_digitada = 0;
    
    do
    {
        printf("digite a matricula do aluno %d:\n", quantidade_inserida + 1);
        scanf("%d", &matricula_digitada);

        if (matricula_digitada != -1)
        {
            matricula_aluno[quantidade_inserida] = montar_aluno(matricula_digitada);
            gravar_aluno_arquivo(matricula_aluno[quantidade_inserida]);

            quantidade_inserida++;
        }

    } while (quantidade_inserida < 10 && matricula_digitada != -1);

    printf("quantidade inserida %d\n", quantidade_inserida);

    return quantidade_inserida;
}


int verifica_existencia()
{
    int matricula_desejada;
    int achou = 0, posicao = -1;
    struct tipo_matricula_aluno aluno;

    FILE *file;
    file = fopen("tarefa3.txt", "r");

    printf("digite a matricula do aluno desejado:\n");
    scanf("%d", &matricula_desejada);

    while (achou == 0 && fscanf(file, "%d %s %f %f \n", &aluno.matricula, aluno.nome_aluno, &aluno.nota1, &aluno.nota2) != EOF)
    {
        posicao++;
        achou = matricula_desejada == aluno.matricula ? 1 : 0;
    }

    fclose(file);

    return achou == 1 ? posicao : -1;
}

void posiciona_arquivo(int numero_linha, FILE *file)
{
    char c;
    int quantidade_linha = 0;
    fseek(file, 0, SEEK_SET);
    while(quantidade_linha < numero_linha  && fscanf(file, "%c", &c))
    {
        printf("%c ", c);
        if(c == '\n'){
            quantidade_linha++;
        }
    }
    
}

void mudar_notas()
{
    int existe = verifica_existencia();
    struct tipo_matricula_aluno aluno;

    if (existe != -1)
    {
        FILE *file;
        file = fopen("tarefa3.txt", "r+");

        posiciona_arquivo(existe, file);
        
        fscanf(file, "%d %s %f %f", &aluno.matricula, aluno.nome_aluno, &aluno.nota1, &aluno.nota2);
        printf("%d %s %f %f \n", aluno.matricula, aluno.nome_aluno, aluno.nota1, aluno.nota2);

        posiciona_arquivo(existe, file);

        aluno.nota1 = 4;

        fprintf(file, "%d %s %f %f", aluno.matricula, aluno.nome_aluno, aluno.nota1, aluno.nota2);

        fclose(file);
    }
    else
    {
        printf("Aluno nao encontrado! \n");

    }
}

int main()
{
    int teste;
    char nome[20];
    fscanf(stdin, "%d", &teste);
    //fgets(nome, 20, stdin);
    //printf("\n nome %s\n", nome);
    fprintf(stdout, "\nvalor digitade %d\n", teste);
    /*int tamanho = 10;
    struct tipo_matricula_aluno matricula_aluno[tamanho];
    int count = 0, matricula_desejada;
*/
    //cadastra_aluno(matricula_aluno);
    //mudar_notas();
}