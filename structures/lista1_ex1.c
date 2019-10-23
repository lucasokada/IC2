#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_informacoes_produto
{
    char nome_produto[40];
    int unidades_disponiveis;
    float preco_unitario;
};

struct tipo_informacoes_loja
{
    char nome_loja[40];
    struct tipo_informacoes_produto informacoes_produto;
    float total_estoque;  //unidades_disponiveis * preco_unitario
};


//-----------------------------------------METODOS----------------------------------------

float total_estoque_podutos(int posicao_lojas, int posicao_produtos, struct tipo_informacoes_loja informacoes_loja[5][10])
{
  float soma = 0;
  
  if(strcmp(informacoes_loja[posicao_lojas][posicao_produtos].nome_loja, "-1") != 0){
    if(strcmp(informacoes_loja[posicao_lojas][posicao_produtos].nome_loja, "-1") != 0){
      soma += (informacoes_loja[posicao_lojas][posicao_produtos].informacoes_produto.unidades_disponiveis * informacoes_loja[posicao_lojas][posicao_produtos].informacoes_produto.preco_unitario);
    }
  }

  return soma;
}

int valida_nome(char nome[40])
{
  int valido;

  valido = strcmp(nome, "-1") != 0 ? 1 : -1;

  return valida_nome;
}

//____________________________________________PREENCHE DADOS DA LOJA___________________________________________________________
void preenche_dados_lojas(int lojas, int produtos, struct tipo_informacoes_loja informacoes_loja[5][10])
{
  int i=0, j=0, valido;
  float calcula_total_estoque;

  do{
      printf("nome da loja %d:", i+1);
      scanf(" %[^\n]", informacoes_loja[i][j].nome_loja);
      
      valido = valida_nome(informacoes_loja[i][j].nome_loja);

      if(valido != -1){
        do{
          printf("nome da loja %d", j+1);
          scanf(" %[^\n]", informacoes_loja[i][j].informacoes_produto.nome_produto);  

          valido = valida_nome(informacoes_loja[i][j].informacoes_produto.nome_produto);

          if(valido != -1){

            printf("unidades dispoiniveis:\n");
            scanf("%d", &informacoes_loja[i][j].informacoes_produto.unidades_disponiveis);

            printf("preco unitario:\n");
            scanf("%f", &informacoes_loja[i][j].informacoes_produto.preco_unitario);

            calcula_total_estoque = total_estoque_podutos(i, j, informacoes_loja);
          }
          
          j++;

        }while(valido != -1 && j < produtos);
      }
    
    printf("valor total em estoque:\n");
    scanf("%f", &calcula_total_estoque);

    i++;
    j=0;
    valido = valida_nome(informacoes_loja[i][j].nome_loja);

  }while(valido != -1 && i < lojas);
}
//-------------------------------------------------------------------------------------------------------

int verifica_existencia_loja(int lojas, struct tipo_informacoes_loja informacoes_loja[5][10], char nome[40])
{
  int i, existe;

  for(i=0; i<lojas; i++)
  {
    existe = strcmp(informacoes_loja[i][0].nome_loja, nome) == 0 ? i : -1; //se existir retorna a posicao da loja
  }

  return existe;
}

int valida_posicao_produto(int produtos, int posicao_produto)
{
  int i, valido;

  valido = posicao_produto >=0 && posicao_produto < produtos ? 1 : -1;

  return valido;
}

//_______________________________________________OPCAO 1__________________________________________________________

void incluir_produtos_loja(int lojas, int produtos, struct tipo_informacoes_loja informacoes_loja[5][10])
{
  int existe/*i*/, posicao_produto/*j*/, posicao_valida;
  char loja_desejada[40];

  printf("digite o nome da loja em que se deseja incluir produtos:\n");
  scanf(" %[^\n]", loja_desejada);

  existe = verifica_existencia_loja(lojas, informacoes_loja, loja_desejada);

  if(existe != -1){
    
    printf("digite a posicao do produto a ser adicionado:\n");
    scanf("%d", &posicao_produto);
    
    posicao_valida = valida_posicao_produto(produtos, posicao_produto);

    if(posicao_valida != -1){
      
      printf("digite o nome do produto a ser adicionado:\n");
      scanf(" %[^\n]", informacoes_loja[existe][posicao_produto].informacoes_produto.nome_produto);

      printf("digite as unidades disponiveis do produto a ser adicionado:\n");
      scanf("%d", &informacoes_loja[existe][posicao_produto].informacoes_produto.unidades_disponiveis);

      printf("digite o preco unitario do produto a ser adicionado:\n");
      scanf("%f", &informacoes_loja[existe][posicao_produto].informacoes_produto.preco_unitario);

    }else
      printf("posicao inexistente\n");
  }else
    printf("loja inexistente\n");
}
//-------------------------------------------------------------------------------------------------------

int verifica_existencia_produto(int produtos, int posicao_loja, struct tipo_informacoes_loja informacoes_loja[5][10], char nome[40])
{
    int existe, i;

    for(i=0; i<produtos; i++)
  {
    existe = strcmp(informacoes_loja[posicao_loja][i].informacoes_produto.nome_produto, nome) == 0 ? i : -1; //se existir retorna a posicao da loja
  }

  return existe;
}

int oferta_demanda(int posicao_loja, int posicao_prouto, int unidades_desejadas, struct tipo_informacoes_loja informacoes_loja[5][10])
{
    int possivel_realizar_compra;

    possivel_realizar_compra = informacoes_loja[posicao_loja][posicao_prouto].informacoes_produto.unidades_disponiveis > unidades_desejadas ? 1 : -1;

    return possivel_realizar_compra;
}

void efetuar_venda(int posicao_loja, int posicao_prouto, int unidades_desejadas, struct tipo_informacoes_loja informacoes_loja[5][10])
{
    int possivel;
    float preco;

    printf("digite as unidades desejadas do produto:\n");
    scanf("%d", &unidades_desejadas);
    possivel = oferta_demanda(posicao_loja, posicao_prouto, unidades_desejadas, informacoes_loja);

    if(possivel != -1){
        
        preco = unidades_desejadas * (informacoes_loja[posicao_loja][posicao_prouto].informacoes_produto.preco_unitario);
        printf("valor da compra: %.2f\n", preco);

    }else{
        printf("nao é possivel realizar compra.");
    }
}
//__________________________________________________OPCAO 2______________________________________________________________________

void remover_produto(int lojas, int produtos, struct tipo_informacoes_loja informacoes_loja[5][10])
{
    char loja_desejada[40], produto_desejado[40];
    int existe_loja, existe_produto, unidades_desejadas;

    printf("nome da loja desejada:\n");
    scanf(" %[^\n]", loja_desejada);

    existe_loja = verifica_existencia_loja(lojas, informacoes_loja, loja_desejada); //retorna posicao da loja!!
    
    if(existe_loja != -1){

        printf("nome do produto que deseja comprar:\n");
        scanf(" %[^\n]", produto_desejado);
        existe_produto = verifica_existencia_produto(produtos, existe_loja ,informacoes_loja, produto_desejado); // retorna posicao do produto!!

        if(existe_produto != -1){
            efetuar_venda(existe_loja, existe_produto, unidades_desejadas, informacoes_loja);
            informacoes_loja[existe_loja][existe_produto].informacoes_produto.unidades_disponiveis -= unidades_desejadas; //atualiza estoque
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------------------


int main()
{
  int lojas = 5, produtos = 10;
  struct tipo_informacoes_loja informacoes_loja;
}