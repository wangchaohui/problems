#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define AS(x) while(!(x))puts(#x);

typedef struct{
	int s;
	short d[1000][1000],r[1000][1000+1],c[1000][1000+1];
}Sudoku;

int N;
Sudoku ANS;

void Sudoku_init(Sudoku *a)
{
	int i,j,k;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			a->d[i][j]=0;
		}
	for(i=0;i<N;i++)
		for(k=1;k<=N;k++)
		{			
			a->r[i][k]=N;
			a->c[i][k]=N;
		}
	a->s=0;
}

int Sudoku_imp(Sudoku *a,int x,int y,int k)
{
	int i;
	if(a->r[x][k]==0)return -1;
	if(a->c[y][k]==0)return -1;
	a->r[x][k]=0;
	a->c[y][k]=0;
	for(i=1;i<=N;i++)
	{
		if(a->r[x][i]>0)a->r[x][i]--;
		if(a->c[y][i]>0)a->c[y][i]--;
	}
	return 0;
}

int Sudoku_add(Sudoku *a,int x,int y,int k)
{
	if(a->d[x][y]!=0)return -1;
	a->d[x][y]=k;
	if(Sudoku_imp(a,x,y,k)==-1)return -1;
	if(x==y)return;
	if(a->d[y][x]!=0)return -1;
	a->d[y][x]=k;
	if(Sudoku_imp(a,y,x,k)==-1)return -1;
	return 0;
}

int Sudoku_try(Sudoku *a)
{
	int i,j,k,f=0;
	for(k=1;k<=N;k++)
		for(i=0;i<N;i++)
		{
			if(a->r[i][k]==1)
				for(j=0;j<N;j++)
					if(a->d[i][j]==0)
					{
						if(Sudoku_add(a,i,j,k)==-1)return -1;
						f=1;
						break;
					}
			if(a->c[i][k]==1)
				for(j=0;j<N;j++)
					if(a->d[j][i]==0)
					{
						if(Sudoku_add(a,j,i,k)==-1)return -1;
						f=1;
						break;
					}
		}
	return f;
}

int Sudoku_serch(Sudoku *a)
{
	int i,j,k,g;
	Sudoku *c;
	c=(Sudoku*)malloc(sizeof(Sudoku));
	for(;a->s<N*N;a->s++)
	{
		i=a->s/N;j=a->s%N;
		if(a->d[i][j]==0)
		{
			for(k=1;k<=N;k++)
			{
				*c=*a;
				if(Sudoku_add(c,i,j,k)==-1)continue;
				while((g=Sudoku_try(c))==1);
				if(g==-1)continue;
				if(Sudoku_serch(c))
					return 1;
			}
			free(c);
			return 0;
		}
	}
	ANS=*a;
	return 1;
}

int main()
{
	int i,j,t;
	Sudoku *a;
	a=(Sudoku*)malloc(sizeof(Sudoku));
	while(1){
	scanf("%d",&N);
	Sudoku_init(a);
	for(i=0;i<N;i++)
	{
		Sudoku_add(a,i,i,1);
		Sudoku_add(a,i,N-i-1,N);
	}
	//Sudoku_add(a,i,i,1);
	while((t=Sudoku_try(a))==1);
	AS(t!=-1);
	Sudoku_serch(a);
	for(i=0;i<N;i++)
	{
		printf("%d",ANS.d[i][0]-1);
		for(j=1;j<N;j++)
			printf(" %d",ANS.d[i][j]-1);
		putchar('\n');
	}
	}
	return 0;
}