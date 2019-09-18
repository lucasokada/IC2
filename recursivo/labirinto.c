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

void printa_matriz(int linha , int coluna, int matriz[10][10])
{
    int i, j;

    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
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


int define_coordenada(int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int coordenada_linha, coordenada_coluna, valido;
    int coordenada_valida;

    do{

        do{
            printf("digite a coordenada linha:\n");
            coordenada_linha = definir_pontos();  //digita a linha
            valido = verifica_ponto(coordenada_linha); // verifica a linha
            //printf("LINHA valido dentro de define_coordenada: %d\n", valido);

            if(valido != 1){
                printf("linha invalida. tente novamente\n");
            }

        }while(valido != 1);

        do{
            printf("digite a coordenada coluna:\n");
            coordenada_coluna = definir_pontos(); //digita a coluna
            valido = verifica_ponto(coordenada_coluna); // verifica a coluna
            //printf("COLUNA valido dentro de define_coordenada: %d\n", valido);

            if(valido != 1){
                printf("coluna invalida. tente novamente\n");
            }

        }while(valido != 1);

        //a coordenada deve ter valor 1!!!
        coordenada_valida = verifica_coordenada(coordenada_linha, coordenada_coluna, matriz_principal);
        
        if(coordenada_valida != 1){
           
            printf("a coordenada e invalida, tente novamente\n\n");

        }else{
           
            matriz_auxiliar[coordenada_linha][coordenada_coluna] = matriz_principal[coordenada_linha][coordenada_coluna];  
            
            printf("coordenada aceita\n\n");
        }

    }while(coordenada_valida != 1); //a coordenada inicial e final deve ser 1!!

    return matriz_principal[coordenada_linha][coordenada_coluna];
}

//________________________________MOVIMENTOS_____________________________________________

int abaixo(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_abaixo, valida_posicao, valida_coordenada;

    posicao_abaixo = linha_atual + 1; //a posicao posicao_abaixo sera a linha atual + 1

    valida_posicao = verifica_ponto(posicao_abaixo);//a posicao a posicao_abaixo deve ser >= 0 e <10

    valida_coordenada = verifica_coordenada(posicao_abaixo, coluna_atual, matriz_principal);// a posicao deve valer 1!!

    if(valida_posicao != 0 && valida_coordenada != 0){
        
        printf("a coordenada posicao_abaixo eh valida\n");
        linha_atual = posicao_abaixo;//atualiza posicao atual

        return linha_atual;
    
    }else{
        printf("posicao posicao_abaixo invalida\n\n");
    }
}

int acima(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_acima, valida_posicao, valida_coordenada;

    posicao_acima = linha_atual - 1;

    valida_posicao = verifica_ponto(posicao_acima);//a posicao posicao_acima deve ser >= 0 e <10

    valida_coordenada = verifica_coordenada(posicao_acima, coluna_atual, matriz_principal);// a posicao deve valer 1!!

    if(valida_posicao != 0 && valida_coordenada != 0){
        
        printf("a coordenada posicao_acima eh valida\n");
        linha_atual = posicao_acima;//atualiza posicao atual

        return linha_atual;
    
    }else{
        printf("posicao posicao_acima invalida\n\n");
    }
}

int direita(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_direita, valida_posicao, valida_coordenada;

    posicao_direita = coluna_atual + 1;

    valida_posicao = verifica_ponto(posicao_direita);//a posicao posicao_direita deve ser >= 0 e <10

    valida_coordenada = verifica_coordenada(posicao_direita, coluna_atual, matriz_principal);// a posicao deve valer 1!!

    if(valida_posicao != 0 && valida_coordenada != 0){
        
        printf("a coordenada posicao_direita eh valida\n");
        linha_atual = posicao_direita;//atualiza posicao atual

        return linha_atual;
    
    }else{
        printf("posicao posicao_direita invalida\n\n");
    }
}

int esquerda(int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    int posicao_esquerda, valida_posicao, valida_coordenada;

    posicao_esquerda = coluna_atual - 1;

    valida_posicao = verifica_ponto(posicao_esquerda);//a posicao posicao_esquerda deve ser >= 0 e <10

    valida_coordenada = verifica_coordenada(posicao_esquerda, coluna_atual, matriz_principal);// a posicao deve valer 1!!

    if(valida_posicao != 0 && valida_coordenada != 0){
        
        printf("a coordenada posicao_esquerda eh valida\n");
        linha_atual = posicao_esquerda;//atualiza posicao atual

        return linha_atual;
    
    }else{
        printf("posicao posicao_esquerda invalida\n\n");
    }
}

void resolve_labirinto(int posicao_inicial, int posicao_final, int linha_atual, int coluna_atual, int matriz_principal[10][10], int matriz_auxiliar[10][10])
{
    //printf("RESOLVE LABIRINTO\n");
    //printf("posicao inicial: %d\n", posicao_inicial);
    //printf("posicao final: %d\n", posicao_final);
}

int main()
{
    int linha = 10, coluna = 10;
    int matriz_auxiliar[linha][coluna];
    int posicao_inicial, posicao_final;
    int linha_atual, coluna_atual;
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
    
    printa_matriz(linha , coluna, matriz_principal);
    printf("\n");

    inicializa_matriz_auxiliar(linha , coluna, matriz_auxiliar);
    printa_matriz(linha , coluna, matriz_auxiliar);
    printf("\n");

    printf("DEFINA POSICAO INICIAL\n");
    posicao_inicial = define_coordenada(matriz_principal, matriz_auxiliar);
    printf("\n");

    printf("DEFINA POSICAO FINAL\n");
    posicao_final = define_coordenada(matriz_principal, matriz_auxiliar);
    printf("\n");

    printa_matriz(linha , coluna, matriz_auxiliar);

    //resolve_labirinto(posicao_inicial, posicao_final, matriz_principal, matriz_auxiliar);
}