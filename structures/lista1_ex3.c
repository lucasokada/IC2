#include <stdio.h>
#include <stdio.h>
#include <string.h>

enum tipo {shell=1, ring, mini};                                  //considerando os sabores e tamanhos
enum sabor {chocolate=1, baunilha, limao, franboesa, morango};    // de doces temos 15 possibilidades(3x5)

struct tipo_dados_pedido
{
    char nome[40];
    int quantidade[15];
    enum tipo tamanho[15];
    enum sabor sabor_doce[15];
};

void sabor_doces(struct tipo_dados_pedido dados_pedido, int posicao)
{ 
    switch(dados_pedido.sabor_doce[posicao])
    {
    case chocolate:
        printf("sabor chocolate\n");
        break;
    case baunilha:
        printf("sabor baunilha\n");
        break;
    case limao:
        printf("sabor limao\n");
        break;
    case franboesa:
        printf("sabor franboesa\n");
        break;
    case morango:
        printf("sabor morango\n");
        break;
    default:
        break;
    }
}

void tamanho_doces(struct tipo_dados_pedido dados_pedido, int posicao)
{
    switch(dados_pedido.tamanho[posicao])
    {
    case shell:
        printf("tamanho shell\n");
        break;
    case ring:
        printf("tamanho ring\n");
        break;
    case mini:
        printf("tamanho mini\n");
        break;
    default:
        break;
    }
}

int verifica_pedido()
{
    int verifica;

    printf("deseja algo mais?\n");
    scanf("%d", &verifica);

    return verifica;
}

struct tipo_dados_pedido realiza_pedido(int *tamanho)
{
    struct tipo_dados_pedido dados_pedido;
    int adicionar_pedido;
    *tamanho=0;

    printf("nome do cliente:\n");
    scanf(" %[^\n]", dados_pedido.nome);
    do{
        printf("quantidade de doces:\n");
        scanf("%d", &dados_pedido.quantidade[*tamanho]);

        printf("sabor dos doces:\n");
        scanf("%d", &dados_pedido.sabor_doce[*tamanho]);
        sabor_doces(dados_pedido, *tamanho);

        printf("tamanho dos doces:\n");
        scanf("%d", &dados_pedido.tamanho[*tamanho]);
        tamanho_doces(dados_pedido, *tamanho);

        (*tamanho)++;

        printf("doces\n");
        adicionar_pedido = verifica_pedido();

    }while(adicionar_pedido != -1);

    return dados_pedido;
}

void adiciona_em_arquivo(struct tipo_dados_pedido dados_pedido, int *tamanho)
{
    int i;
    FILE *file;

    file = fopen("pedidos.txt", "a");

    fprintf(file, "%s\n", dados_pedido.nome);

    for(i=0; i<(*tamanho); i++)
    {
        fprintf(file, "%d\n", dados_pedido.quantidade[i]);
        fprintf(file, "%d\n", dados_pedido.sabor_doce[i]);
        fprintf(file, "%d\n", dados_pedido.tamanho[i]);
    }

    fclose(file);
}

void adiciona_pedido(struct tipo_dados_pedido dados_pedido, int *tamanho)
{
    int pedidos, realizar_pedido;
    
    do{
        printf("pedidos\n");
        pedidos = verifica_pedido();
        
        if(pedidos != -1){
            dados_pedido = realiza_pedido(&tamanho);
            adiciona_em_arquivo(dados_pedido, &tamanho);
        }else{
            printf("pedidos encerrados\n");
        }
    }while(pedidos != -1);
}

int main()
{
    int pedido, *tamanho;

    struct tipo_dados_pedido dados_pedido;

    adiciona_pedido(dados_pedido, &tamanho);
}
