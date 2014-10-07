#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 1e-8

struct ans{
	int a,b;
};

struct ans ANS[10000];
int tot;

int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

int cmp(const void *a,const void *b)
{
	return ((struct ans*)a)->a-((struct ans*)b)->a;
}

int main()
{
	int c,m,n,r,a,b,t,i,C=0;
	while(scanf("%d",&c)==1 && c)
	{
		if(C++)putchar('\n');
		printf("Case %d:\n",C);
		m=sqrt(c);r=sqrt(c/2);tot=0;
		for(;m>r;m--)
		{
			if(m*m>c)continue;
			n=sqrt(c-m*m)+eps;
			if(m*m+n*n==c)
			{
				a=m*m-n*n;
				b=2*m*n;
				if(a>b)
				{
					t=a;
					a=b;
					b=t;
				}
				if(a>0 && gcd(a,c)==1)
				{
					
					ANS[tot].a=a;
					ANS[tot].b=b;
					tot++;
				}
			}
		}
		qsort(ANS,tot,sizeof(ANS[0]),cmp);
		printf("There are %d solution(s).\n",tot);
		for(i=0;i<tot;i++)
			printf("%d^2 + %d^2 = %d^2\n",ANS[i].a,ANS[i].b,c);
	}
	return 0;
}