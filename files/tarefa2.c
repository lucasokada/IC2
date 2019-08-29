#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tipo_alunos
{
    int matricula_aluno;
    char nome_aluno[20];
    float nota1;
    float nota2;
};


int menu()
{
    int opcao;

    printf("---------------MENU---------------\n");
    printf("1 - ler matricula\n");
    printf("2 - alterar notas\n");
    printf("3 - sair do programa\n");
    printf("-----------------------------------\n\n");
    printf("digite a opçao\n");
    scanf("%d", &opcao);

    return opcao;
}

void incluir_dados(int tamanho, struct tipo_alunos alunos[], FILE *file)
{
    int i; 

    file = fopen("alunos.txt", "wb"); //abrir arquivo permissao de escrita

    if(file == NULL){
        printf("o arquivo nao existe.\n");
        exit(1);
    }
    
    printf("cadastre os dados dos alunos:\n\n");

    for(i=0; i<tamanho; i++)
    {
        printf("matricula do aluno %d:\n", i+1);
        scanf("%d", &alunos[i].matricula_aluno);
        fwrite(&alunos[i].matricula_aluno, sizeof(/*struct tipo_alunos*/alunos[i].matricula_aluno), 1, file); //Escreve no arquivo a variavel
        //fwrite("\n", sizeof("\n"), 1, file); pula linha?

        printf("nome do aluno %d:\n", i+1);//fwrite(variavel, tamanho em bytes, quantidade de unidades(ex: vetores), arquivo);
        scanf(" %s", alunos[i].nome_aluno);
        fwrite(alunos[i].nome_aluno, sizeof(alunos[i].nome_aluno), 1, file);
        //fwrite("\n", sizeof("\n"), 1, file);

        printf("nota 1:\n");
        scanf("%f", &alunos[i].nota1);
        fwrite(&alunos[i].nota1, sizeof(alunos[i].nota1), 1, file);
        //fwrite("\n", sizeof("\n"), 1, file);

        printf("nota 2:\n");
        scanf("%f", &alunos[i].nota2);
        fwrite(&alunos[i].nota2, sizeof(alunos[i].nota2), 1, file);
        //fwrite("\n", sizeof("\n"), 1, file);

        printf("\n\n");
        //fwrite("\n", sizeof("\n"), 1, file);
    }
    fclose(file);

}

void ler_matricula(int tamanho, struct tipo_alunos alunos[], FILE *file) //opcao 1-ver dados do aluno  NAO FUNFA(AINDA)
{
    int matricula_desejada;
    int count = 0, i;
    int result;

    file = fopen("alunos.txt", "rb");//abre arquivo com permissao para leitura

    printf("digite a matricula do aluno desejado:\n");
    scanf("%d", &matricula_desejada);
    printf("chegou aqui");
   
    for(i=0; i<tamanho; i++)
   {
        result = alunos[i].matricula_aluno;
        printf("chegou aqui");

        if(result == matricula_desejada){
            fseek(file, count*sizeof(struct tipo_alunos), SEEK_SET);
            fread(&alunos, sizeof(struct tipo_alunos), 1, file);
            printf("matricula: %d\n", alunos[i].matricula_aluno);
            printf("nota 1: %.2f\n", alunos[i].nota1);
            printf("nota 2: %.2f\n", alunos[i].nota2);
            count++;
        }
    }
    if(count == 0){
        printf("aluno nao encontrado:\n");
    }
    
    fclose(file);//fecha arquivo
}

void alterar_notas(int tamanho, struct tipo_alunos alunos[], FILE *file)// opcao 2 - mudar notas 
{
    int matricula_desejada;
    int count = 0, i;
    int result;

    file = fopen("alunos.txt", "ab");//abre arquivo com permissao para alteraçao

    printf("digite a matricula do aluno desejado:\n");
    scanf("%d", &matricula_desejada);
   
    for(i=0; i<tamanho; i++)
    {
        result = alunos[i].matricula_aluno;

        if(result == matricula_desejada){
            
            fseek(file, count*sizeof(struct tipo_alunos), SEEK_SET); //fseek(arquivo, qtd bits que pula, origem)
            fread(&alunos, sizeof(struct tipo_alunos), 1, file);

            printf("nota 1:\n");
            scanf("%f", &alunos[i].nota1);
            fwrite(&alunos[i].nota1, sizeof(alunos[i].nota1), 1, file);

            printf("nota 2:\n");
            scanf("%f", &alunos[i].nota2);
            fwrite(&alunos[i].nota2, sizeof(alunos[i].nota2), 1, file);
            count++;
        }
    }
    if(count == 0){
        printf("aluno nao encontrado:\n");
    }

    fclose(file);//fecha arquivo
}   

int escolher_opcao(int tamanho, struct tipo_alunos alunos[], FILE *file)
{
    int escolha;

    incluir_dados(tamanho, alunos, file);

    do
    {
        escolha = menu();
        if(escolha == 1){
            ler_matricula(tamanho, alunos, file);
        }else if(escolha == 2){
            alterar_notas(tamanho, alunos, file);
        }
    } while (escolha != 3);
}

int main()
{
    int tamanho = 3;
    struct tipo_alunos alunos[tamanho];

    FILE *file;
    
    escolher_opcao(tamanho, alunos, file);
}



