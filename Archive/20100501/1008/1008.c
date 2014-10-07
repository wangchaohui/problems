#include <stdio.h>

int xormul(int x,int y)
{
	int i,s=0;
	for(;x;x>>=1)
	{
		if(x&1)
			s^=y;
		y<<=1;
	}
	return s;
}

int main()
{
	int T,n,dx[1010],dy[1010],i,s;
	scanf("%d",&T);
	while(T--)
	{
		s=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&dx[i],&dy[i]);
			s^=xormul(dx[i]-1,dy[i]-1);
		}
		if(s)puts("Have a try, lxhgww.");
		else puts("Don't waste your time.");

	}
	return 0;
}