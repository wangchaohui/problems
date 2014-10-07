#include <stdio.h>
#include <memory.h>
#define maxw 2000000000

struct ANS{
	int a,n;
};

ANS f[110][110][410];
int d[110];
int c[110][110];
int n,m;

ANS dfs(int x,int y,int w)
{
	int i;
	ANS g,r;
	if(f[x][y][w].a!=-maxw)return f[x][y][w];
	r.a=-maxw;
	for(i=n-1;i>=0;i--)
	{
		if(c[x][i] && i!=x)
		{
			g=dfs(i,y,w+d[i]);
			if(-g.a>r.a)
			{
				r.a=-g.a;r.n=c[x][i];
			}
			else if(-g.a==r.a)r.n+=c[x][i];
		}
		if(c[y][i] && i!=y)
		{
			g=dfs(x,i,w-d[i]);
			if(-g.a>r.a)
			{
				r.a=-g.a;r.n=c[y][i];
			}
			else if(-g.a==r.a)r.n+=c[y][i];
		}
	}
	if(r.a==-maxw)r.a=200-w,r.n=0;
	f[x][y][w]=r;
	return r;
}

int main()
{
	int x,y,i,j,k,a,b;
	char s[200];
	ANS g;
	while(scanf("%d %d %d %d",&n,&m,&x,&y)==4)	
	{
		for(i=0;i<n;i++)for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<410;k++)f[i][j][k].a=-maxw;
		}
		for(i=0;i<n;i++)scanf("%1d",&d[i]);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			c[a][b]++;
		}
		g=dfs(x,y,201);
		printf("%d %d\n",g.a,g.n);
	}
	return 0;
}