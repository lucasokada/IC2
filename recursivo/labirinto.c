#include <stdio.h>
#include <stdlib.h>

//______________________________MATRIZ________________________________

//inicializa todas as posicoes com 0
int inicializa_matriz_auxiliar(int linha , int coluna, int matriz_auxiliar[10][10])
{
    int i, j;

    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
        {
            matriz_auxiliar[i][j] = 0;    
        }
    }

    return matriz_auxiliar[10][10];
}

void printa_matriz(int matriz[10][10])
{
    int i, j;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//______________________________COORDENADA INICIAL___________________________________

int verifica_ponto(int ponto)
{
    int valido;

    valido = (ponto >= 0) && (ponto < 10)  ? 1 : 0;

    return valido;
}

int definir_pontos()
{
    int ponto;
    scanf("%d", &ponto);

    return ponto;
}

int verifica_coordenada(int coordenada_linha, int coordenada_coluna, int matriz_principal[10][10])
{
    int valido;

    valido = matriz_principal[coordenada_linha][coordenada_coluna] == 1 ? 1 : 0;

    return valido;
}


int define_coordenada_linha()
{
    int coordenada_linha, valido;

    do{
        printf("digite a coordenada linha:\n");
        coordenada_linha = definir_pontos();  //digita a linha
        valido = verifica_ponto(coordenada_linha); // verifica a linha
        //printf("LINHA valido dentro de define_coordenada: %d\n", valido);

        if(valido != 1){
            printf("linha invalida. tente novamente\n");
        }

    }while(valido != 1);

    return coordenada_linha;
}

int define_coordenada_coluna()
{
    int coordenada_coluna, valido;

    do{
            printf("digite a coordenada coluna:\n");
    
            coordenada_coluna = definir_pontos(); //digita a coluna

            valido = verifica_ponto(coordenada_coluna); // verifica a coluna
            //printf("COLUNA valido dentro de define_coordenada: %d\n", valido);

            if(valido != 1){
                printf("coluna invalida. tente novamente\n");
            }

        }while(valido != 1);

    return coordenada_coluna;
}

int define_coordenada_linha_coluna(int coordenada_linha, int coordenada_coluna, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int valido;

    do{
        valido = verifica_coordenada(coordenada_linha, coordenada_coluna, matriz_principal);

        if(valido != 1){
           
            printf("a coordenada e invalida, tente novamente\n\n");

        }else{
           
            matriz_auxiliar[coordenada_linha][coordenada_coluna] = matriz_principal[coordenada_linha][coordenada_coluna];  
            
            printf("coordenada aceita\n\n");
        }

    }while(valido != 1);

    return matriz_principal[coordenada_linha][coordenada_coluna];
}

//________________________________MOVIMENTOS_____________________________________________

//-------------------------------------ABAIXO---------------------------------------------------------------------------
int verifica_abaixo(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_abaixo, valida_posicao, valida_coordenada, valida_abaixo;

    posicao_abaixo = linha_atual + 1; //a posicao posicao_abaixo sera a linha atual + 1

    valida_posicao = verifica_ponto(posicao_abaixo);//a posicao a posicao_abaixo deve ser >= 0 e <10

    valida_coordenada = verifica_coordenada(posicao_abaixo, coluna_atual, matriz_principal);// a posicao deve valer 1!!

    valida_abaixo = (valida_posicao) != 0 && (valida_coordenada != 0) ? 1 : 0;
}

int abaixo(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_abaixo = linha_atual + 1;

    linha_atual = posicao_abaixo;//atualiza posicao atual

    return linha_atual;
}

//---------------------------------------ACIMA-------------------------------------------------------------------------

int verifica_acima(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_acima, valida_posicao, valida_coordenada, valida_acima;

    posicao_acima = linha_atual - 1;

    valida_posicao = verifica_ponto(posicao_acima);//a posicao posicao_acima deve ser >= 0 e <10

    valida_coordenada = verifica_coordenada(posicao_acima, coluna_atual, matriz_principal);// a posicao deve valer 1!!

    valida_acima = (valida_posicao != 0) && (valida_coordenada != 0) ? 1 : 0;
}

int acima(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_acima = linha_atual - 1;

    linha_atual = posicao_acima;//atualiza posicao atual

    return linha_atual;
}
//-----------------------------------DIREITA------------------------------------------------------------------------------------

int verifica_direita(int linha_atual, int coluna_atual, int matriz_principal[10][10])
{
    int posicao_direita, valida_posicao, valida_coordenada, valida_direita;

    posicao_direita = coluna_atual + 1;

    valida_posicao = verifica_ponto(posicao_direita);//a posicao posicao_direita deve ser >= 0 e <10

    valida_coordenada = verifica_coordenada(posicao_direita, coluna_atual, matriz_principal);// a posicao deve valer 1!!

    valida_direita = (valida_posicao != 0) && (valida_coordenada != 0) ? 1 : 0;

    return valida_direita;
}

int direita(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_direita = coluna_atual + 1;

    linha_atual = posicao_direita;//atualiza posicao atual

    return linha_atual;
}

//------------------------------------ESQUERDA-----------------------------------------------------------------------------------

int verifica_esquerda(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_esquerda, valida_posicao, valida_coordenada, valida_esquerda;

    posicao_esquerda = coluna_atual - 1;

    valida_posicao = verifica_ponto(posicao_esquerda);//a posicao posicao_esquerda deve ser >= 0 e <10

    valida_coordenada = verifica_coordenada(posicao_esquerda, coluna_atual, matriz_principal);// a posicao deve valer 1!!

    valida_esquerda = (valida_posicao != 0) && (valida_coordenada != 0) ? 1 : 0;

    return valida_esquerda;
}

int esquerda(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_esquerda = coluna_atual - 1;

    linha_atual = posicao_esquerda;//atualiza posicao atual

    return linha_atual;
}

//-------------------------------------------------------------------------------------------------------------------------------------

int resolve_labirinto(int coordenada_linha_final, int coordenada_coluna_final,
                int coordenada_linha_atual, int coordenada_coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int contador = 0, valido;

    if(coordenada_linha_atual != coordenada_linha_final && coordenada_coluna_atual != coordenada_coluna_final){
    
        valido =  verifica_direita(coordenada_linha_atual, coordenada_coluna_atual, matriz_principal);
        printf("valido: %d\n", valido);

        if(valido != 0){
            
            coordenada_coluna_atual = direita(coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);
            matriz_auxiliar[coordenada_linha_atual][coordenada_coluna_atual] = 1;
            matriz_principal[coordenada_linha_atual][coordenada_coluna_atual - 1] = 0;
            contador++;

            printf("entrou em direita\n");
        }else{}
        //-------------
        valido = verifica_abaixo(coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);

        if(valido != 0){
            coordenada_linha_atual = abaixo(coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);
            matriz_auxiliar[coordenada_linha_atual][coordenada_coluna_atual] = 1;
            matriz_principal[coordenada_linha_atual - 1][coordenada_coluna_atual] = 0;
            contador++;

            printf("entrou em abaixo\n");
        }
        //-------------------------
        valido = verifica_esquerda(coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);

        if(valido != 0){
            coordenada_coluna_atual = esquerda(coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);
            matriz_auxiliar[coordenada_linha_atual][coordenada_coluna_atual] = 1;
            matriz_principal[coordenada_linha_atual][coordenada_coluna_atual + 1] = 0;
            contador++;

            printf("entrou em esquerda\n");
        }
        //--------------------------

        valido = verifica_acima(coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);

        if(valido != 0){
            coordenada_linha_atual = acima(coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);
            matriz_auxiliar[coordenada_linha_atual][coordenada_coluna_atual] = 1;
            matriz_principal[coordenada_linha_atual + 1][coordenada_coluna_atual] = 0;
            contador++;

            printf("entrou em acima\n");
        }

        printf(" passou aqui +1\n");
        printf("contador dentro dessa vez: %d\n", contador);

        contador = resolve_labirinto(coordenada_linha_final, coordenada_coluna_final, coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);
        printf("\n");
        printa_matriz(matriz_auxiliar);
        printf("\n");

        int matriz_principal[10][10] = 
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 
        0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 
        0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 
        1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 
        0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 
        1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 
        0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 
        0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
        1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 
        0, 0, 1, 0, 0, 1, 1, 0, 0, 1};

    }else{
        return contador;
    }
}

//_______________________________________________________MAIN______________________________________________________

int main()
{
    int linha = 10, coluna = 10;
    int matriz_auxiliar[linha][coluna];
    int coordenada_linha_inicial, coordenada_coluna_inicial;
    int coordenada_linha_final, coordenada_coluna_final;
    int coordenada_linha_atual, coordenada_coluna_atual;
    int contador;

    //int coordenada_linha, coordenada_coluna;

    int matriz_principal[10][10] = 
    {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 
    0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 
    0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 
    1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 
    0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 
    1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 
    0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 
    0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
    1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 
    0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
    
    printa_matriz(matriz_principal);
    printf("\n");

    inicializa_matriz_auxiliar(linha , coluna, matriz_auxiliar);
    printa_matriz(matriz_auxiliar);
    printf("\n");

    printf("COORDENADAS INICIAS\n");
    coordenada_linha_inicial = define_coordenada_linha();
    coordenada_coluna_inicial = define_coordenada_coluna();
    define_coordenada_linha_coluna(coordenada_linha_inicial, coordenada_coluna_inicial, matriz_principal, matriz_auxiliar);

    printf("COORDENADAS FINAIS\n");
    coordenada_linha_final = define_coordenada_linha();
    coordenada_coluna_final = define_coordenada_coluna();
    define_coordenada_linha_coluna(coordenada_linha_final, coordenada_coluna_final, matriz_principal, matriz_auxiliar);

    printa_matriz(matriz_auxiliar);
    printf("\n");

    //resolve_labirinto(posicao_inicial, posicao_final, matriz_principal, matriz_auxiliar);
    coordenada_linha_atual = coordenada_linha_inicial;
    coordenada_coluna_atual = coordenada_coluna_inicial;

    contador = resolve_labirinto(coordenada_linha_final, coordenada_coluna_final, coordenada_linha_atual, coordenada_coluna_atual, matriz_principal, matriz_auxiliar);
    printf("contador: %d", contador);

}