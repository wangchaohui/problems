#include <stdio.h>
#define N 15

int d[2000],u[10000],tot;
int n,k,s,o;

void pl(int i)
{
	int j,kk,c,t;
	if(i==n)
	{
		for(j=0;j<n;j++)
		{
			c=0;
			for(kk=(j+1)%n;kk!=j && d[kk]==d[j];kk=(kk+1)%n)c++;
			if(c>=k)return;
		}
		for(kk=0;kk<n;kk++)
		{
			t=0;
			for(j=0;j<n;j++)
			{
				t*=2;
				t+=d[(j+kk)%n];	
			}
			for(j=0;j<tot;j++)
				if(u[j]==t)break;
			if(j!=tot)break;
		}
		
		if(kk==n)
		{
			u[tot++]=t;
			s++;
		}	
		return;
	}
	d[i]=0;
	pl(i+1);
	d[i]=1;
	pl(i+1);
}

int main()
{
	freopen("out.txt","w",stdout);
	printf("  ");
	for(n=1;n<=N;n++)
		printf("%7d",n);
	putchar('\n');
	for(n=1;n<=N;n++)
	{
		printf("%2d",n);
		for(k=1;k<=n;k++)
		{
			s=0;o=0;tot=0;
			pl(0);
			printf("%7d",s);
		}
		putchar('\n');
	}
	return 0;
}