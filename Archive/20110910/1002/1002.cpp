#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int,int> X[100010];
pair<int,int> Y[100010];

int xi[100010];
int yi[100010];

int main()
{
	int N,M;
	while(scanf("%d %d",&N,&M)==2 && (N!=0 || M!=0))
	{
		int i,x,y;
		for(i=0;i<N;i++)
		{
			scanf("%d %d",&x,&y);
			X[i]=make_pair(x,i);
			Y[i]=make_pair(y,i);
		}
		sort(X,X+N);
		sort(Y,Y+N);
		for(i=0;i<N;i++)
		{
			xi[X[i].second]=i;
			yi[Y[i].second]=i;
		}
		while(M-->0)
		{
			int c,d,C=0;
			scanf("%d %d",&c,&d);
			if(c==0)
			{
				int l=lower_bound(X,X+N,make_pair(d-1,2000000000))-X;
				int u=upper_bound(X,X+N,make_pair(d,2000000000))-X;
				for(i=l;i<u;i++)
				{
					if(~X[i].second)
					{
						C++;
						Y[yi[X[i].second]].second=-1;
						X[i].second=-1;
					}
				}
			}
			else
			{
				int l=lower_bound(Y,Y+N,make_pair(d-1,2000000000))-Y;
				int u=upper_bound(Y,Y+N,make_pair(d,2000000000))-Y;
				for(i=l;i<u;i++)
				{
					if(~Y[i].second)
					{
						C++;
						X[xi[Y[i].second]].second=-1;
						Y[i].second=-1;
					}
				}
			}
			printf("%d\n",C);
		}
		putchar('\n');
	}
	return 0;
}
