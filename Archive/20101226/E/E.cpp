#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long I;

struct P{
	int x,y,t,w;
	bool operator<(const P &b)const{
		return (I)x*x+(I)y*y<(I)b.x*b.x+(I)b.y*b.y;
	}
};

P p[600];
int c[600][600];
int v[600][600];
int m[600];
int X[600];
int tot=0;
int f[2][10010];

int main()
{
	int n,x0,y0,i,j,k,T;
	int pre,now;
	while(scanf("%d %d %d %d",&x0,&y0,&n,&T)==4)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&p[i].x,&p[i].y,&p[i].t,&p[i].w);
			p[i].x-=x0;p[i].y-=y0;
		}
		sort(p,p+n);
		tot=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
				if((I)p[i].x*p[j].x>=0 && (I)p[i].y*p[j].y>=0 && (I)p[i].x*p[j].y==(I)p[i].y*p[j].x)
					break;
			if(i==j)
			{
				X[i]=tot++;
				c[X[i]][0]=p[i].t;
				v[X[i]][0]=p[i].w;
				m[X[i]]=1;
			}
			else
			{
				c[X[j]][m[X[j]]]=c[X[j]][m[X[j]]-1]+p[i].t;
				v[X[j]][m[X[j]]]=v[X[j]][m[X[j]]-1]+p[i].w;
				m[X[j]]++;
			}
		}
		pre=0;now=1;
		memset(f[pre],0,sizeof(f[pre]));
		for(i=0;i<tot;i++)
		{
			memcpy(f[now],f[pre],sizeof(f[now]));
			for(j=T;j>=0;j--)
				for(k=0;k<m[i] && j>=c[i][k];k++)
					if(f[now][j]<f[pre][j-c[i][k]]+v[i][k])
						f[now][j]=f[pre][j-c[i][k]]+v[i][k];
			swap(pre,now);
		}
		printf("%d\n",f[pre][T]);
	}
	return 0;
}
