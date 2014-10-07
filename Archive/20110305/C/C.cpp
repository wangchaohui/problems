#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long I;

struct C{
	int n,g,m,p;
};

C d[100010];
C e[100010];
int p[100010][4];

int cmp1(const void *a,const void *b)
{
	return -((C*)a)->g+((C*)b)->g;
}

int cmp2(const void *a,const void *b)
{
	return -((C*)a)->m+((C*)b)->m;
}

int cmp3(const void *a_,const void *b_)
{
	I t;
	C *a=(C*)a_,*b=(C*)b_;
	t=-(I)a->g*b->p+(I)b->g*a->p;
	if(t>0)return 1;
	else if(t==0)return 0;
	else return -1;
}

int cmp4(const void *a_,const void *b_)
{
	I t;
	C *a=(C*)a_,*b=(C*)b_;
	t=-(I)a->m*b->p+(I)b->m*a->p;
	if(t>0)return 1;
	else if(t==0)return 0;
	else return -1;
}

int (*f[4])(const void*,const void*)={cmp1,cmp2,cmp3,cmp4};

int main()
{
	int n,m,i,k,t,mi,mn;
	while(scanf("%d %d",&n,&m)==2)
	{
		for(i=0;i<n;i++)
		{
			e[i].n=i;
			scanf("%d %d %d",&e[i].g,&e[i].m,&e[i].p);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&t);
			d[i]=e[t];
		}
		n=m;
		for(i=0;i<n;i++)
			d[i].n=i;
		for(k=0;k<4;k++)
		{
			qsort(d,n,sizeof(C),f[k]);
			for(i=0;i<n;i++)
				if(i>0 && f[k](d+i-1,d+i)==0)
					p[d[i].n][k]=p[d[i-1].n][k];
				else
					p[d[i].n][k]=i;
		}
		for(i=0;i<n;i++)
		{	
			mi=n+1;
			for(k=0;k<4;k++)
				if(p[i][k]<mi)
				{
					mi=p[i][k];mn=k;
				}
			printf("%d:%d\n",mi+1,mn+1);
		}
		printf("\n");
	}
	return 0;
}
