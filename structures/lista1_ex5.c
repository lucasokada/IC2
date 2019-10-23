// no caso deste exercicio achei mais eficiente guadar os dados dos materias arquivos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------INFORMACOES GERAIS-------------
struct informacoes_material
{
    char nome_produto[40];
    char modelo_produto[40];
    char fabricante[40];
    float preco;
    int quantidade_disponivel;
};

//------------------------METAL--------------------
enum metal_empregado {torneira = 1, chuveiro, ducha, valvula, cuba};
enum local_uso {cozinha = 1, banheiro, lavanderia, geral};

struct tipo_metal
{
    enum metal_empregado metal_empregado;
    enum local_uso local_uso;
    struct informacoes_material informacoes;
};

//-------------------------REVESTIMENTO-------------
enum revestimento_empregado {ceramica = 1, esmaltado, porcelanato};

struct tipo_revestimento
{
    int tamanho;
    int PEI;
    enum revestimento_empregado revestimento_empregado;
    struct informacoes_material informacoes;
};

//----------------------------LOUÇA--------------------
enum louca_empregada {vaso_sanitario = 1, bidet, coluna, tanque};
enum cor_louca {branco = 1, marfim, salmao, verde, cinza};

struct tipo_louca
{
    int tamanho;
    enum louca_empregada louca_empregada;
    enum cor_louca cor;
    struct informacoes_material informacoes;
};

//------------------UNION--------------------
union tipo_produto
{
    struct tipo_metal metal;
    struct tipo_revestimento revestimento;
    struct tipo_louca louca;
};

struct executa
{
    union tipo_produto produto;
};


//-----------METODOS METAL----------------------------------------------
struct executa preenche_metal()
{
    int categoria, local_uso;
    struct executa executa;

    printf("categoria do produto desejado:\n");
    scanf("%d", &categoria);//enum
    executa.produto.metal.metal_empregado = categoria;

    printf("local de uso:\n");
    scanf("%d", &local_uso);//enum
    executa.produto.metal.local_uso = local_uso;

    printf("nome do produto:\n");
    scanf(" %[^\n]", executa.produto.metal.informacoes.nome_produto);

    printf("modelo:\n");
    scanf(" %[^\n]", executa.produto.metal.informacoes.modelo_produto);

    printf("fabricante:\n");
    scanf(" %[^\n]", executa.produto.metal.informacoes.fabricante);
    fflush(stdin);
    
    printf("preço:\n");
    scanf("%f", &(executa.produto.metal.informacoes.preco));

    printf("unidades em estoque:\n");
    scanf("%d", &(executa.produto.metal.informacoes.quantidade_disponivel));

    return executa;
}

void mostra_metal_empregado(struct executa executa, FILE *file)
{

    switch(executa.produto.metal.metal_empregado)
    {
        case torneira:
            fprintf(file, "torneira\n");
            break;
        case chuveiro:
            fprintf(file, "chuveiro\n");
            break;
        case ducha:
            fprintf(file, "ducha\n");
            break;
        case valvula:
            fprintf(file, "valvula\n");
            break;
        case cuba:
            fprintf(file, "cuba\n");
            break;
        default:
            break;   
    }
}

void mostra_local_uso(struct executa executa, FILE *file)
{
    switch(executa.produto.metal.local_uso)
    {
        case 1:
            fprintf(file, "cozinha\n");
            break;
        case 2:
            fprintf(file, "banheiro\n");
            break;
        case 3:
            fprintf(file, " lavanderia\n");
            break;
        case 4:
            fprintf(file, "geral\n");
            break;
        default:
            break;   
    }
}

void metal_arquivo(struct executa executa)
{
    FILE *file;

    file = fopen("metal.txt", "a");

    mostra_metal_empregado(executa, file);
    mostra_local_uso(executa, file);
    fprintf(file, "%s\n", executa.produto.metal.informacoes.nome_produto);
    fprintf(file, "%s\n", executa.produto.metal.informacoes.modelo_produto);
    fprintf(file, "%s\n", executa.produto.metal.informacoes.fabricante);
    fprintf(file, "%.2f\n", executa.produto.metal.informacoes.preco);
    fprintf(file, "%d\n", executa.produto.metal.informacoes.quantidade_disponivel);

    fclose(file);
}

//----------------METODOS REVESTIMENTOS------------------
int valida_PEI(struct executa executa)
{
    int valido;

    valido = executa.produto.revestimento.PEI >= 1 && executa.produto.revestimento.PEI <= 5 ? 1 : 0;
    
    return valido;
}

void mostra_revestimento_empregado(struct executa executa, FILE *file)
{
    switch(executa.produto.revestimento.revestimento_empregado)
    {
    case 1:
        fprintf(file, "ceramica\n");
        break;
    case 2:
        fprintf(file, "esmaltado\n");
        break;
    case 3:
        fprintf(file, "porcelanato\n");
        break;
    default:
        break;
    }
}

struct executa preenche_revestimento()
{
    int valido;
    struct executa executa;

    printf("tamanho do produto desejado:\n");
    scanf("%d", &executa.produto.revestimento.tamanho);

    do{
        printf("PEI:\n");
        scanf("%d", &executa.produto.revestimento.PEI);
        valido = valida_PEI(executa);

        if(valido != 1){
            printf("invalido. tente novamente\n");
        }
    }while(valido != 1);

    printf("material:\n");
    scanf("%d", &executa.produto.revestimento.revestimento_empregado);

    printf("nome:\n");
    scanf(" %[^\n]", executa.produto.revestimento.informacoes.nome_produto);

    printf("modelo:\n");
    scanf(" %[^\n]", executa.produto.revestimento.informacoes.modelo_produto);

    printf("fabricante:\n");
    scanf(" %[^\n]", executa.produto.revestimento.informacoes.fabricante);

    printf("preco:\n");
    scanf("%f", &executa.produto.revestimento.informacoes.preco);

    printf("unidades em estoque:\n");
    scanf("%d", &executa.produto.revestimento.informacoes.quantidade_disponivel);

    return executa;
}

void revestimento_arquivo(struct executa executa)
{
    FILE *file;

    file = fopen("revestimento.txt", "a");

    fprintf(file, "%d\n", executa.produto.revestimento.tamanho);    
    fprintf(file, "%d\n", executa.produto.revestimento.PEI);
    mostra_revestimento_empregado(executa, file);
    fprintf(file, "%s\n", executa.produto.revestimento.informacoes.nome_produto);
    fprintf(file, "%s", executa.produto.revestimento.informacoes.modelo_produto);
    fprintf(file, "%s", executa.produto.revestimento.informacoes.fabricante);
    fprintf(file, "%.2f", &executa.produto.revestimento.informacoes.preco);
    fprintf(file, "%d", &executa.produto.revestimento.informacoes.quantidade_disponivel);

    fclose(file);
}

//-------------------METODOS LOUCA------------------
void mostra_louca_empregada(struct executa executa, FILE *file)
{
    switch(executa.produto.louca.louca_empregada)
    {
        case 1:
            fprintf(file, "vaso sanitario\n");
            break;
        case 2:
            fprintf(file, "bidet\n");
            break;
        case 3:
            fprintf(file, "coluna\n");
            break;
        case 4:
            fprintf(file, "tanque\n");
            break;
        default:
            break;
    }
}

void mostra_cor_empregada(struct executa executa, FILE *file)
{
    switch (executa.produto.louca.cor)
    {
    case 1:
        fprintf(file, "branco\n");
        break;
    case 2:
        fprintf(file, "marfim\n");
        break;
    case 3:
        fprintf(file, "salmao\n");
        break;
    case 4:
        fprintf(file, "verde\n");
        break;
    case 5:
        fprintf(file, "cinza\n");
        break;
    default:
        break;
    }
}

struct executa preenche_louca()
{
    struct executa executa;
    int tamanho_louca, louca_empregada, cor;

    printf("tamanho da louca:\n");
    scanf("%d", &tamanho_louca);
    executa.produto.louca.tamanho = tamanho_louca;

    printf("tipo de louca:\n");
    scanf("%d", &louca_empregada);
    executa.produto.louca.louca_empregada = louca_empregada;

    printf("cor:\n");
    scanf("%d", &cor);
    executa.produto.louca.cor = cor;

    printf("nome do produto:\n");
    scanf(" %[^\n]", executa.produto.louca.informacoes.nome_produto);

    printf("modelo:\n");
    scanf(" %[^\n]", executa.produto.louca.informacoes.modelo_produto);

    printf("fabricante:\n");
    scanf(" %[^\n]", executa.produto.louca.informacoes.fabricante);

    printf("preco:\n");
    scanf("%f", &executa.produto.louca.informacoes.preco);

    printf("unidades em estoque:\n");
    scanf("%d", &executa.produto.louca.informacoes.quantidade_disponivel);

    return executa;
}

void louca_arquivo(struct executa executa)
{
    FILE *file;

    file = fopen("louca.txt", "a");

    fprintf(file, "%d", executa.produto.louca.tamanho);
    mostra_louca_empregada(executa, file);
    mostra_cor_empregada(executa, file);    
    fprintf(file, "%s", executa.produto.louca.informacoes.nome_produto);
    fprintf(file, "%s", executa.produto.louca.informacoes.modelo_produto);
    fprintf(file, "%s", executa.produto.louca.informacoes.fabricante);
    fprintf(file, "%.2f", executa.produto.louca.informacoes.preco);
    fprintf(file, "%d", executa.produto.louca.informacoes.quantidade_disponivel);

    fclose(file);
}
//------------------------------------------------------------------------------------------------

void menu()
{
    printf("----------------------MENU------------------------\n");
    printf("poderao ser armazenados produtos dos tipos:\n");
    printf("1 - METAL\n");
    printf("2 - REVESTIMENTO\n");
    printf("3 - LOUCA\n");
    printf("para sair digite -1\n");
    printf("--------------------------------------------------\n");
}

int escolha()
{
    int tipo_escolhido;

    printf("digite a opcao desejada:\n");
    scanf("%d", &tipo_escolhido);

    return tipo_escolhido;
}

void regitra_dados()
{
    int tipo_escolhido;
    struct executa executa;

    do
    {
        menu();

        tipo_escolhido = escolha();

        switch(tipo_escolhido)
        {
        case 1:
            printf("METAL\n");
            executa = preenche_metal();
            metal_arquivo(executa);
            break;
        case 2:
            printf("REVESTIMENTO\n");
            executa = preenche_revestimento();
            revestimento_arquivo(executa);
        case 3:
            printf("LOUCA\n");
            executa = preenche_louca();
            louca_arquivo(executa);
        default:
            printf("ENCERRA\n");
            break;
        }
    } while(tipo_escolhido != -1);
    
}

int main()
{
    struct executa executa;

    regitra_dados();
}