#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void verifica_nota(struct tipo_matricula_aluno matricula_aluno[], int count)
{
    
}

void cadastra_aluno(struct tipo_matricula_aluno matricula_aluno[], int *count)
{
    //int count=0;
    FILE *file;
    file = fopen("tarefa3.txt", "w"); //cria / acessa arquivo com permissao de escrita

     do
    {
        printf("digite a matricula do aluno %d:\n", *count+1);
        scanf("%d", &matricula_aluno[*count].matricula);

        if(matricula_aluno[*count].matricula != -1){
        
            fprintf(file, "matricula %d: ", *count+1);
            fprintf(file, "%d\n", matricula_aluno[*count].matricula);

            fprintf(file, "nome do aluno: ");
            printf("digite o nome do aluno:\n");
            scanf(" %[^\n]s", matricula_aluno[*count].nome_aluno);
            fprintf(file, "%s\n", matricula_aluno[*count].nome_aluno);

            printf("digite a nota 1 do aluno:\n");
            fprintf(file, "nota1 do aluno: ");
            do{
                scanf("%f", &matricula_aluno[*count].nota1);    //verifica e registra nota 1
                if(matricula_aluno[*count].nota1 < 0 || matricula_aluno[*count].nota1 > 10){
                    printf("nota invalida.tente novamente!\n");
                }
            }while((matricula_aluno[*count].nota1 < 0) || (matricula_aluno[*count].nota1 > 10));
            fprintf(file, "%.2f\n", matricula_aluno[*count].nota1);

            printf("digite a nota 2 do aluno:\n");
            fprintf(file, "nota2 do aluno: ");
            do{
                scanf("%f", &matricula_aluno[*count].nota2);    //verifica e registra nota 2
                if(matricula_aluno[*count].nota2 < 0 || matricula_aluno[*count].nota2 > 10){
                    printf("nota invalida.tente novamente!\n");
                }
            }while((matricula_aluno[*count].nota2 < 0) || (matricula_aluno[*count].nota2 >10));
            fprintf(file, "%.2f\n", matricula_aluno[*count].nota2);

            (*count)++;
        }


    } while (*count < 10 && matricula_aluno[*count].matricula != -1);
    
    fclose(file);
    printf("%d", *count);
}

int verifica_existencia(struct tipo_matricula_aluno matricula_aluno[], int count)
{
    int matricula_desejada;
    int achou, i, posicao;

    FILE *file;

    file = fopen("tarefa3.txt", "r");

    printf("digite a matricula do aluno desejado:\n");
    scanf("%d", &matricula_desejada);

    while(fscanf(file, ))
        {
        achou = matricula_desejada == matricula_aluno[i].matricula ? 1 : 0;
        if(achou == 1){
            posicao = i;
            //printf("existe\n");
        }
    }
    if(achou == 0){
            printf("matricula nao encontrada. tente novamente!\n");
        }

    return posicao;
}

void mudar_notas(struct tipo_matricula_aluno matricula_aluno[], int count)
{
    verifica_existencia(matricula_aluno, count);


}


int main()
{
    int tamanho = 10;
    struct tipo_matricula_aluno matricula_aluno[tamanho];
    int count = 0, matricula_desejada;

    cadastra_aluno(matricula_aluno, &count);
    mudar_notas(matricula_aluno, count);

}

