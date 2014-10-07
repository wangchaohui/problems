#include <stdio.h>

char a[3010][3010],b[3010][3010];
int x,y;

int main()
{
	int n,q,i,j,k,d,e;
	char p[5][5],s[10];
	while(scanf("%d",&n)==1)
	{
		if(n==0)break;
		for(i=0;i<n;i++)
		{
			gets(s);
			for(j=0;j<n;j++)
				a[i][j]=p[i][j]=getchar();
		}
		scanf("%d",&q);x=n;
		for(i=1;i<q;i++)
		{
			for(j=0;j<x;j++)
				for(k=0;k<x;k++)
				{
					if(a[j][k]!=' ')
					{
						for(d=0;d<n;d++)
							for(e=0;e<n;e++)
								b[j*n+d][k*n+e]=p[d][e];
					}
					else
					{
						for(d=0;d<n;d++)
							for(e=0;e<n;e++)
								b[j*n+d][k*n+e]=' ';
					}
				}
			x*=n;
			for(j=0;j<x;j++)
				for(k=0;k<x;k++)
					a[j][k]=b[j][k];
		}
		for(j=0;j<x;j++)
		{
			a[j][x]='\0';
			puts(a[j]);
		}
	}
	return 0;
}