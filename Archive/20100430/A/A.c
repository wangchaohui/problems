#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct{
	int t,s,d;
}packets;

packets p[20010];
int d[20010];

int cmp(const void *a,const void *b)
{
	return ((packets*)a)->t-((packets*)b)->t;
}

int main()
{
	int n,m,i,c;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d %d",&p[i].t,&p[i].s,&p[i].d);
	qsort(p,m,sizeof(packets),cmp);
	memset(d,-1,sizeof(d));
	d[1]=0;c=1;
	for(i=0;i<m;i++)
		if(d[p[i].s]!=-1 && p[i].t>d[p[i].s] && d[p[i].d]==-1)
			d[p[i].d]=p[i].t,c++;
	printf("%d\n",c);
	return 0;
}