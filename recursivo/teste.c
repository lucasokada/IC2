void inicializa_matriz(int matriz_principal)
{
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
}

//_______________________________________________________MAIN______________________________________________________

int main()
{
    int matriz_principal[10][10];
    
   inicializa_matriz(matriz_principal);
}