#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define maxn 1000
#define maxm 2000
#define maxw 2000000000

struct edge{
	int x,y,next;
};


struct edge g[maxm+1];
int n,first[maxn+1],tot;

int k[maxn+1];
int price[maxn+1][50];
int power[maxn+1][50];

void init_graph()
{
	int i;
	for(i=1;i<=n;i++)
		first[i]=-1;
	tot=0;
}

void add_edge(int a,int b)
{
	tot++;
	g[tot].x=a;g[tot].y=b;
	g[tot].next=first[a];first[a]=tot;
	tot++;
	g[tot].x=b;g[tot].y=a;
	g[tot].next=first[b];first[b]=tot;
}

int visited[maxn+1];

int f[maxn+1][201];

void dfs(int x)
{
	int i,j,a,ff=0;
	if(visited[x])return;
	visited[x]=1;
	for(i=0;i<=200;i++)
	{
		f[x][i]=maxw;
	}
	for(i=first[x];i!=-1;i=g[i].next)
	{
		int y=g[i].y;
		if(!visited[y])
		{
			dfs(y);
			ff=1;
			for(j=200;j>=0;j--)
			{
				int mm=0;
				for(a=0;a<=j;a++)
					mm=max(mm,min(f[x][j-a],f[y][a]));
				f[x][j]=mm;
			}
		}
	}
	if(ff==0)for(i=0;i<=200;i++)f[x][i]=0;
	for(i=200;i>=0;i--)
	{
		int mm=f[x][i];
		for(j=0;j<k[x];j++)
		{
			if(i<price[x][j])continue;
			mm=max(mm,f[x][i-price[x][j]]+power[x][j]);
		}
		f[x][i]=mm;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,M;
		scanf("%d",&n);
		init_graph();
		for(i=0;i<n-1;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			add_edge(a,b);
		}
		scanf("%d",&M);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k[i]);
			for(j=0;j<k[i];j++)
				scanf("%d %d",&price[i][j],&power[i][j]);
		}
		memset(visited,0,sizeof(visited));
		dfs(1);
		printf("%d\n",f[1][M]);
	}
	return 0;
}