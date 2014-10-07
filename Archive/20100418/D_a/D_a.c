#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int d[9][9],p[9][9][10],r[9][10],c[9][10],s[9][10];
}Sudoku;

Sudoku ANS;

void Sudoku_init(Sudoku *a)
{
	int i,j,k;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
		{
			a->d[i][j]=0;
			a->p[i][j][0]=9;
		}
	for(i=0;i<9;i++)
		for(k=1;k<=9;k++)
		{			
			for(j=0;j<9;j++)
				a->p[i][j][k]=1;
			a->r[i][k]=9;
			a->c[i][k]=9;
			a->s[i][k]=9;
		}
}

int Sudoku_imp(Sudoku *a,int x,int y,int k)
{
	if(a->p[x][y][k]==0)return 0;
	a->p[x][y][k]=0;
	a->p[x][y][0]--;
	a->r[x][k]--;
	a->c[y][k]--;
	a->s[3*(x/3)+y/3][k]--;	
	if(a->d[x][y]==0 && a->p[x][y][0]==0)return -1;
	return 0;
}

int Sudoku_add(Sudoku *a,int x,int y,int k)
{
	int i,j,ss=3*(x/3)+y/3;
	if(a->d[x][y]!=0)return -1;
	if(!a->p[x][y][k])return -1;
	a->d[x][y]=k;
	for(i=0;i<9;i++)
	{
		if(Sudoku_imp(a,i,y,k)==-1)return -1;
		if(Sudoku_imp(a,x,i,k)==-1)return -1;
	}
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(Sudoku_imp(a,3*(x/3)+i,3*(y/3)+j,k)==-1)return -1;
	for(i=1;i<=9;i++)
		if(Sudoku_imp(a,x,y,i)==-1)return -1;
	return 0;
}

int main()
{
	int pp,i,j,t,n;
	Sudoku a;
	srand(time(NULL));
	freopen("in3.txt","w",stdout);
	pp=1000;
	puts("1000");
	while(pp--)
	{
		Sudoku_init(&a);
		n=rand()%20;
		for(i=0;i<n;i++)
		{
			t=rand()%10;
			if(t)Sudoku_add(&a,rand()%9,rand()%9,t);
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
				putchar('0'+a.d[i][j]);
			putchar('\n');
		}
	}
	return 0;
}