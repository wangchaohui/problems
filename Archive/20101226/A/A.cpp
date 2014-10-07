#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int D[110];

typedef pair<pair<int,int>,int> P;

int g[251][101][41];

P Q[1000010];

int main()
{
	int lh,ls,n,i,f;
	P p,t;
	int hp,sp,hp1,sp1,n1;
	int op,cl;
	while(scanf("%d %d %d",&lh,&ls,&n)==3)
	{
		f=0;
		for(i=1;i<=ls;i++)scanf("%d",&D[i]);
		memset(g,-1,sizeof(g));
		p=make_pair(make_pair(lh,0),n);
		Q[0]=p;
		g[lh][0][n]=0;
		op=1;cl=0;
		while(op>cl)
		{
			p=Q[cl++];
			hp=p.first.first;
			sp=p.first.second;
			n=p.second;
			if(n==0)
			{
				printf("%d\n",g[hp][sp][n]);
				f=1;
				break;
			}
			sp1=min(ls,sp+1);
			sp1=min(ls,sp1+(n-1)%3);
			if(hp>n-1)
			{
				t=make_pair(make_pair(hp-(n-1),sp1),n-1);
				if(g[t.first.first][t.first.second][t.second]==-1)
				{
					g[t.first.first][t.first.second][t.second]=g[hp][sp][n]+1;
					Q[op++]=t;
				}
			}
			hp1=min(lh,hp+lh/5);
			sp1=min(ls,sp+n%3);
			if(hp1>n)
			{
				t=make_pair(make_pair(hp1-n,sp1),n);
				if(g[t.first.first][t.first.second][t.second]==-1)
				{
					g[t.first.first][t.first.second][t.second]=g[hp][sp][n]+1;
					Q[op++]=t;
				}
			}
			if(sp>0)
			{
				n1=max(0,n-D[sp]);
				if(hp>n1)
				{
					t=make_pair(make_pair(hp-n1,min(ls,n1%3)),n1);
					if(g[t.first.first][t.first.second][t.second]==-1)
					{
						g[t.first.first][t.first.second][t.second]=g[hp][sp][n]+1;
						Q[op++]=t;
					}
				}
			}
		}
		if(f==0)puts("HELP!");
	}
	return 0;
}
