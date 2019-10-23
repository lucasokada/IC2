#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>


#define min(a,b) (((a)<(b))?(a):(b))
#define linhas 100
#define colunas 100
 

int Verificar(int mat[linhas][colunas], int passou[linhas][colunas], int x, int y)
{
	if (mat[x][y] == 0 || passou[x][y])
		return 0;
	return 1;
}
 
int Valido(int x, int y, int M, int N)
{
	if (x < M && y < N && x >= 0 && y >= 0)
		return 1;
	return 0;
}

void Caminho(int mat[linhas][colunas], int passou[linhas][colunas], int i, int j, int x, int y, int *dist_min, int dist, int M, int N){
	if (i == x && j == y){
		*dist_min = min(dist, *dist_min);
		return;
	}
	passou[i][j] = 1;
	if (Valido(i + 1, j, M, N) && Verificar(mat, passou, i + 1, j))
		Caminho(mat, passou, i + 1, j, x, y, dist_min, dist + 1, M, N);
	if (Valido(i, j + 1, M, N) && Verificar(mat, passou, i, j + 1))
		Caminho(mat, passou, i, j + 1, x, y, dist_min, dist + 1, M, N);
	if (Valido(i - 1, j, M, N) && Verificar(mat, passou, i - 1, j))
		Caminho(mat, passou, i - 1, j, x, y, dist_min, dist + 1, M, N);
	if (Valido(i, j - 1, M, N) && Verificar(mat, passou, i, j - 1))
		Caminho(mat, passou, i, j - 1, x, y, dist_min, dist + 1, M, N);
	passou[i][j] = 0;
}
 
int main(){
	int mat[linhas][colunas], i, j, oi, oj, x, y, M, N;
	scanf(" %d", &M); 	scanf(" %d", &N); scanf(" %d", &oi);
	scanf(" %d", &oj);	scanf(" %d", &x);scanf(" %d", &y);
	 
	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++){
			scanf(" %d", &mat[i][j]);
		}
	}
 
	int passou[linhas][colunas];
	memset(passou, 0, sizeof passou);
	
	int dist_min = INT_MAX;
	Caminho(mat, passou, oi, oj, x, y, &dist_min, 0, M, N);
 
	if(dist_min != INT_MAX)
		printf("%d", dist_min);
	
	return 0;
}