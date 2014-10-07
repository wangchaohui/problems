#include <stdio.h>


int d[200][200];
int n;

void dfs(int i)
{
	int x=i/n,y=i%n;
	int j,k,s;
	if(i==n*n)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",d[j][k]);
			for(k=1;k<n;k++)
				printf(" %d",d[j][k]);
			puts("");
		}
	}
}

void ppp()
{
	int i,j;
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n-i;j++)
			d[i][j]=1;
		for(;j<n;j++)
			d[i][j]=0;
	}
	for(i=0;i<n/2;i++)
	{
		for(j=0;j<n/2;j++)
		{
			d[n/2+i][n/2+j]=-1;
		}
	}
	d[n/2][0]=1;d[n-1][n/2-1]=0;
	for(j=1;j<n/2-1;j++)
	{
		d[n/2][j]=0;
		d[n/2+j][0]=0;
	}
	for(j=0;j<n/2-1;j++)
	{
		d[n/2+j][n/2-1]=-1;
		d[n-1][j]=-1;
	}
	for(i=1;i<n/2-1;i++)
	{
		for(j=1;j<n/2-i;j++)
		{
			d[n/2+i][j]=0;
		}
		for(;j<n/2-1;j++)
		{
			d[n/2+i][j]=-1;
		}
	}
}