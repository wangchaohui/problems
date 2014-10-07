#include <stdio.h>

char B[2058][2058];
char s[100000];

int p;

void sd(int n,int x,int y)
{
	int i,j;
	if(s[p++]=='*')
	{
		sd(n/2,x,y);
		sd(n/2,x+n/2,y);
		sd(n/2,x,y+n/2);
		sd(n/2,x+n/2,y+n/2);
		return;
	}
	for(i=y;i<y+n;i++)
		for(j=x;j<x+n;j++)
			B[i][j]=s[p-1];
}

int main()
{
	int T,n,i,j,k,f=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %s",&n,s);
		if(n&(n-1))
		{
			puts("Invalid length");
			continue;
		}
		p=0;
		sd(n,1,1);f=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				if(B[i][j]=='1')
				{
					for(k=j;k+1<=n && B[i][k+1]=='1';k++);
					if(f)putchar(',');else f=1;
					if(k>j)
						printf("(%d-%d,%d)",j,k,i);
					else
						printf("(%d,%d)",j,i);
					j=k;
				}
		}
		putchar('\n');
	}
	return 0;
}
