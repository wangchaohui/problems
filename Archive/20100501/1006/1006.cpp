#include <stdio.h>
#include <algorithm>
using namespace std;
const double pii = (double)3.14159265358979;

int d[100010];

int main()
{
	int p,n,i,m;
	double r,ans;
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d %lf",&n,&r);
		for(i=0;i<n;i++)
			scanf("%d",&d[i]);
		sort(d,d+n);
		m=0;
		for(i=0;i<n-1;i++)
			if(m<d[i+1]-d[i])
				m=d[i+1]-d[i];
		if(m==0)puts("Inf");
		else
		{
			ans=r*2*pii/n/m;
			if(r*2*pii/n*(n-1)/(d[n-1]-d[0])<ans)
				ans=r*2*pii/n*(n-1)/(d[n-1]-d[0]);
			printf("%.3lf\n",ans);
		}

	}
	return 0;
}