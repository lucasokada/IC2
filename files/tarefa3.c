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

int func_escolha()
{
    int escolha;
    printf("escolha a opçao:\n");
    scanf("%d", &escolha);

    return escolha;
}

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
    fseek(file, 0, SEEK_SET);   //posiciona o ponteiro no começo do arquivo
    while(quantidade_linha < numero_linha  && fscanf(file, "%c", &c))   //ler as linhas ate a ultima linha
    {
        //printf("%c ", c);
        if(c == '\n'){
            quantidade_linha++;
        }
    }
    
}

void consultar_matricula()//  OPÇAO 1
{
    int existe = verifica_existencia();
    struct tipo_matricula_aluno aluno;

    FILE *file;
    file = fopen("tarefa3.txt", "r");

    posiciona_arquivo(existe, file);
    fscanf(file, "%d %s %f %f", &aluno.matricula, aluno.nome_aluno, &aluno.nota1, &aluno.nota2);

    printf("%d %s %f %f \n", aluno.matricula, aluno.nome_aluno, aluno.nota1, aluno.nota2);

    fclose(file);

}

void mudar_notas() // OPÇAO 2
{
    int existe = verifica_existencia();
    float nota;
    struct tipo_matricula_aluno aluno;

    if (existe != -1)
    {
        FILE *file;
        file = fopen("tarefa3.txt", "r+");

        posiciona_arquivo(existe, file);
        
        fscanf(file, "%d %s %f %f", &aluno.matricula, aluno.nome_aluno, &aluno.nota1, &aluno.nota2);
        printf("%d %s %f %f \n", aluno.matricula, aluno.nome_aluno, aluno.nota1, aluno.nota2);

        posiciona_arquivo(existe, file);

        printf("mude as notas:\n");
    
        do //*colocar em um metodo
        {
            printf("mude a nota 1:\n"); 
            scanf("%f", &nota);
            validar_nota(nota);
            if(!validar_nota(nota)){
                printf("nota invalida. Tente novamente!\n");
            }else{
                aluno.nota1 = nota;
            }
        }while(!validar_nota);

        do //*colocar em um metodo
        {
            printf("mude a nota 2:\n");
            scanf("%f", &nota);
            validar_nota(nota);
            if(!validar_nota(nota)){
                printf("nota invalida. Tente novamente!\n");
            }else{
                aluno.nota2 = nota;
            }
        }while(!validar_nota);


        fprintf(file, "%d %s %f %f", aluno.matricula, aluno.nome_aluno, aluno.nota1, aluno.nota2);

        fclose(file);
    }
    else
    {
        printf("Aluno nao encontrado! \n");

    }
}

void atualizar_banco_dados(struct tipo_matricula_aluno matricula_aluno[], int quantidade_inserida, FILE *file)
{   //metodo que atualiza o banco de dados (struct) a partir do arquivo, ja que esse possui as ultimas alteraçoes

    struct tipo_matricula_aluno aluno;
    int i=0;

    file = fopen("tarefa3.txt", "r");   //abrir arquivo com permissao de leitura
    
    while(i < quantidade_inserida && fscanf(file, "%d %s %f %f", &aluno.matricula, aluno.nome_aluno, &aluno.nota1, &aluno.nota2)!= EOF) 
    {
        matricula_aluno[i].matricula = aluno.matricula;    
        strcpy(matricula_aluno[i].nome_aluno, aluno.nome_aluno);
        matricula_aluno[i].nota1 = aluno.nota1;
        matricula_aluno[i].nota2 = aluno.nota2;

        printf("%d, %s, %f, %f\n", matricula_aluno[i].matricula, matricula_aluno[i].nome_aluno, matricula_aluno[i].nota1, matricula_aluno[i].nota2);
        i++;
    }
    fclose(file);
}

int perorrer_banco_dados(struct tipo_matricula_aluno matricula_aluno[], int quantidade_inserida)
{   //percorre o banco de dados que foi atualizado ate a matricula desejada
    
    int i, matricula_desejada, posicao, igual = 0;

    printf("digite a matricula desejada:\n");
    scanf("%d", &matricula_desejada);
    

    do{
        printf("matricula %d \n", matricula_aluno[i].matricula);
        if(matricula_aluno[i].matricula == matricula_desejada){
            igual = 1;
            posicao = i;
            printf("%d", posicao);
        }
        i++;

    }while(igual != 1 && i < quantidade_inserida);
    
    return posicao; //retorna a posiçao da matricula procurada
}

int sobrescrever_dados(struct tipo_matricula_aluno matricula_aluno[], int posicao, int quantidade_inserida)
{   //sobrescrever as informaçoes do aluno deesejado pelas informaçoes do aluno seguinte
    matricula_aluno[posicao].matricula = matricula_aluno[posicao + 1].matricula;
    strcpy(matricula_aluno[posicao].nome_aluno, matricula_aluno[posicao + 1].nome_aluno);
    matricula_aluno[posicao].nota1 = matricula_aluno[posicao + 1].nota1;
    matricula_aluno[posicao].nota2 = matricula_aluno[posicao + 1].nota2;

    quantidade_inserida--;  //diminuir o tamanho do vetor 

    return quantidade_inserida;
}

void excluir_matricula()    //OPÇAO 3
{
    struct tipo_matricula_aluno matricula_aluno[10];
    int quantidade_inserida, posicao;

    FILE *file;

    atualizar_banco_dados(matricula_aluno, quantidade_inserida, file);
    posicao = perorrer_banco_dados(matricula_aluno, quantidade_inserida);
    quantidade_inserida = sobrescrever_dados(matricula_aluno, posicao, quantidade_inserida);
    
    file = fopen("tarefa3.txt", "w+");

    for(int i=0; i < quantidade_inserida - 1; i++)
    {
        fprintf(file, "%d %s %f %f \n", matricula_aluno[i].matricula, matricula_aluno[i].nome_aluno, matricula_aluno[i].nota1, matricula_aluno[i].nota2);
    }

}

void opcoes(struct tipo_matricula_aluno matricula_aluno[])
{
    int escolha;
    cadastra_aluno(matricula_aluno);
    menu();

    do
    {
        escolha = func_escolha();

        switch (escolha)
        {
        case 1:
            consultar_matricula();
            break;
        case 2:
            mudar_notas();
            break;
        case 3:
            excluir_matricula();
            break;
        default:
            break;
        }
    }while(escolha != 4);
}

int main()
{
    struct tipo_matricula_aluno matricula_aluno[10];

    opcoes(matricula_aluno);
}
