#include <stdio.h>
#include <memory.h>

int d[100001],C[100001];

int lowbit(int n)
{
	return n&(-n);
}

int sum(int *c,int end)
{
	int sum=0;
	while(end>0)
	{
		sum+=c[end];
		end-=lowbit(end);        
	}
	return sum;
}

void update(int *c,int pos,int num)
{
	while(pos<=c[0]) 
	{
		c[pos]+=num;
		pos+=lowbit(pos);
	}
}

int main()
{
	int n,m,i,t,a,b;
	while(scanf("%d %d",&n,&m)==2)
	{
		memset(C,0,sizeof(C));
		C[0]=n;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&d[i]);
			update(C,i,d[i]);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d %d %d",&t,&a,&b);
			if(t==0)
			{
				printf("%d\n",sum(C,b)-sum(C,a-1));
			}
			else
			{
				update(C,a,b-d[a]);
				d[a]=b;
			}
		}

	}
	return 0;
}