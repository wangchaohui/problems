#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int d[110],f[110][40];

int main()
{
	int T,t[40],n,i,j,k,x,y;
	scanf("%d",&T);
	for(i=0;i<T;i++)scanf("%d",&t[i]);
	scanf("%d",&n);
	for(i=0;i<=100;i++)d[i]=24;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		if(y<d[x])d[x]=y;
	}
	for(j=0;j<T;j++)
		f[0][j]=200;
	f[0][T-1]=0;
	for(i=1;i<=100;i++)
	{
		for(j=0;j<T;j++)
		{
			f[i][j]=f[i-1][(j+T-1)%T];
			if(t[j]>d[i])f[i][j]=200;
		}
		for(j=0;j<T;j++)
			if(f[i][0]>f[i-1][j]+1)
				f[i][0]=f[i-1][j]+1;
	}
	k=200;
	for(j=0;j<T;j++)if(f[100][j]<k)k=f[100][j];
	printf("%d\n",k);
	return 0;
}