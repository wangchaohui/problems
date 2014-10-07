#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,d[110],i,p,q,s,t;
	while(scanf("%d %d",&n,&m)==2)
	{
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		d[n]=0;	
		s=0;
		while(1)
		{
			sort(d,d+n);
			reverse(d,d+n);
			if(d[m-1]==0)break;
			for(p=m;d[m-1]==d[p];p++);
			for(q=m-1;q>=0 && d[m-1]==d[q];q--);
			t=(d[m-1]-d[p])/m;
			if(q>=0)
			{
				if(t>(d[q]-d[m-1])/(p-q-1))
					t=(d[q]-d[m-1])/(p-q-1);
				if(t!=0)
				{
					s+=t*(p-q-1);
					for(i=0;i<=q;i++)
						d[i]-=t*(p-q-1);
					for(;i<p;i++)
						d[i]-=t;
				}
				else
				{
					s++;
					for(i=0;i<m;i++)
						d[i]--;
				}
			}
			else
			{
				if(t!=0)
				{
					s+=t;
					for(i=0;i<p;i++)
						d[i]-=t;
				}
				else
				{
					s++;
					for(i=0;i<m;i++)
						d[i]--;
				}
			}
			
			
		}
		printf("%d\n",s);
	}
	return 0;
}