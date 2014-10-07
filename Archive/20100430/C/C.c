#include <stdio.h>

typedef struct{
	int n;
	int d[11];
}lock;

int ANS;

int sd(int n,lock s,lock t,int now)
{
	int i,j,r,m=1000,rr;
	lock a,b;
	if(n==0)return 0;
	//if(now>=ANS)return ANS;
	r=(t.d[0]+10-s.d[0])%10;
	a.n=b.n=n-1;
	for(i=1;i<n;i++)
	{
		b.d[i-1]=t.d[i];
	}
	if(r==0)
	{
		for(i=1;i<n;i++)
		{
			a.d[i-1]=s.d[i];
		}
		return sd(n-1,a,b,now);
	}
	for(j=n;j>=1;j--)
	{
		for(i=1;i<j;i++)
		{
			a.d[i-1]=(s.d[i]+r)%10;
		}
		for(i=j;i<n;i++)
		{
			a.d[i-1]=s.d[i];
		}
		rr=sd(n-1,a,b,now+1);
		//printf("%d %d %d\n",n,j,r);
		if(rr+1<m)m=rr+1;
	}
	if(m<ANS)ANS=m;
	return m;
}

int main()
{
	int n,i;
	__int64 s,t;
	lock a,b;
	while(scanf("%d %I64d %I64d",&n,&s,&t)==3)
	{
		a.n=b.n=n;ANS=n;
		for(i=0;i<n;i++)
		{
			a.d[i]=s%10;
			s/=10;
			b.d[i]=t%10;
			t/=10;
		}
		printf("%d\n",sd(n,a,b,0));
	}
	
	return 0;
}