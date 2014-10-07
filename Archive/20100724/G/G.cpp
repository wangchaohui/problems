#include <stdio.h>
#include <memory.h>
#define maxw 10000000

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin( 
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(

int n,dist[110][110];

void Floyd()
{
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				checkmin(dist[i][j],dist[i][k]+dist[k][j]);
}

int a[110],b[110],c[110],m[110],to[110][110],cost[110][110];
int f[110][110][3];

int main()
{
	int d,i,j,k,x,ans;
	while(scanf("%d %d",&n,&d)==2)
	{
		for(i=0;i<n;i++)for(j=0;j<n;j++)dist[i][j]=maxw;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&a[i],&b[i],&c[i],&m[i]);
			//dist[i][i]=0;
			for(j=0;j<m[i];j++)
			{
				scanf("%d %d",&to[i][j],&cost[i][j]);
				dist[i][to[i][j]]=cost[i][j];
			}
		}
		Floyd();
		memset(f,-1,sizeof(f));
		f[1][0][0]=a[0];ans=0;d--;
		for(i=2;i<=d;i++)
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(dist[k][j]==maxw)continue;
					for(x=0;x<3;x++)
					{
						if(dist[k][j]<=f[i-1][k][x])
							checkmax(f[i][j][0],f[i-1][k][x]-dist[k][j]+a[j]);
					}
				}
				if(~f[i-1][j][2])checkmax(f[i][j][2],f[i-1][j][2]+c[j]);
				if(~f[i-1][j][1])checkmax(f[i][j][2],f[i-1][j][1]+c[j]);
				if(~f[i-1][j][0])checkmax(f[i][j][1],f[i-1][j][0]+b[j]);
			}
		for(i=0;i<n;i++)for(x=0;x<3;x++)checkmax(ans,f[d][i][x]);
		printf("%d\n",ans);
	}
	return 0;
}