#include <stdio.h>
#include <string.h>
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin( 
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax( 

int V;
int f[10001];
int d[20][20];

void ZeroOnePack(int cost,int value)
{
	int i;
	for(i=V;i>=cost;i--)
		checkmax(f[i],f[i-cost]+value);
}

void CompletePack(int cost,int value)
{
	int i;
	for(i=cost;i<=V;i++)
		checkmax(f[i],f[i-cost]+value);
}

void MultiplePack(int cost,int value,int amount)
{
	int k=1;
	if(cost*amount>=V)
	{
		CompletePack(cost,value);
		return;
	}
	while(k<amount)
	{
		ZeroOnePack(k*cost,k*value);
		amount-=k;
		k*=2;
	}
	ZeroOnePack(amount*cost,amount*value);
}

int main()
{
	int N,i,j,a,b;
	while(scanf("%d %d",&N,&V)==2)
	{
		memset(d,0,sizeof(d));
		for(i=0;i<N;i++)
		{
			scanf("%*s %d %d",&a,&b);
			d[a][b]++;
		}
		memset(f,0,sizeof(f));
		for(i=0;i<=10;i++)
		{
			for(j=0;j<=10;j++)
				MultiplePack(i,j,d[j][i]);
		}
		printf("%d\n",f[V]);
	}
	return 0;
}