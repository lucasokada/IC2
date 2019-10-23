#include <stdio.h>

int main()
{
    int x, y, xini, yini, xfim, yfim, i, j, mat[100][100], percurso[100][100], trajetoatual = 0;

    scanf("%d" ,&x);
    scanf("%d" ,&y);
    scanf("%d" ,&xini);
    scanf("%d" ,&yini);
    scanf("%d" ,&xfim);
    scanf("%d" ,&yfim);
    for(i=0; i<x; ++i){
    for(j=0; j<y; ++j)
    {
    scanf("%d" ,&mat[i][j]);
    percurso[i][j] = 0;
    }}
    
    printf("%i" ,labirinto(x, y, mat, percurso, xini, yini, xfim, yfim, &trajetoatual));
}



int labirinto(int x, int y, int mat[][y], int percurso[][y], int xloc, int yloc, int xend, int yend, int *atual)
{
	
    int menor;

    if(*atual == 0)
    {
    menor = x*y;
    }

    *atual = *atual + 1;

    percurso[xloc][yloc] = 1;
     if(xloc == xend && yloc == yend)
    {
        //caminho mais curto foi encontrado
        if(menor > *atual)
        {
            menor = *atual;
        }

        *atual = *atual - 1;
        return menor;
    }
      else if(mat[xloc+1][yloc] == 1 && xloc+1<x && percurso[xloc+1][yloc] == 0)
    {
        labirinto(x, y, mat, percurso, xloc+1, yloc, xend, yend, &*atual);
        percurso[xloc+1][yloc] = 0;
    }

    else if(mat[xloc][yloc+1] == 1 && yloc+1<y && percurso[xloc][yloc] == 0)
    {
        labirinto(x, y, mat, percurso, xloc, yloc+1, xend, yend, &*atual);
        percurso[xloc][yloc+1] = 0;
    }

    else if(mat[xloc-1][yloc] == 1 && xloc-1>=0 && percurso[xloc-1][yloc] == 0)
    {
        labirinto(x, y, mat, percurso, xloc-1, yloc, xend, yend, &*atual);
        percurso[xloc-1][yloc] = 0;
    }

    else if(mat[xloc][yloc-1] == 1 && yloc-1>=0 && percurso[xloc][yloc-1] == 0)
    {
        labirinto(x, y, mat, percurso, xloc, yloc-1, xend, yend, &*atual);
        percurso[xloc][yloc-1] = 0;
    }

    *atual = *atual -1;
    return menor;
}