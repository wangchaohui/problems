#include <stdio.h>
#include <algorithm>
using namespace std;

typedef __int64 I;

I f[65536][16];

int d[5][5],K[5][5];

int X[16],Y[16],h,hh;

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)==2)
	{
		int i,j,k,a;
		h=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&d[i][j]);
				if(d[i][j]==0)
				{
					X[h]=i;
					Y[h]=j;
					K[i][j]=h;
					h++;
				}
			}
		}
		hh=1<<h;
		memset(f,0,sizeof(f));
		for(i=0;i<h;i++)f[1<<i][i]=1;
		for(i=1;i<hh;i++)
		{
			for(j=0;j<h;j++)
			{
				if(i>>j&1)
				{
					k=i^(1<<j);
					for(a=0;a<h;a++)
					{
						if(k>>a&1 && f[k][a]>0)
						{
							int xj,yj,xa,ya;
							xj=X[j];yj=Y[j];
							xa=X[a];ya=Y[a];
							int xl=max(xj,xa)-min(xj,xa);
							int yl=max(yj,ya)-min(yj,ya);
							int p,q,F=1;
							if(xl>0)
							{
								for(p=min(xj,xa)+1;p<max(xj,xa);p++)
								{
									if((p-xa)*yl%xl==0)
									{
										q=(p-xa)*(yj-ya)/(xj-xa)+ya;
										if(d[p][q]==1 || d[p][q]==0 && ((k>>K[p][q]&1)==0))
										{
											F=0;
											break;
										}
									}
								}
							}
							else
							{
								for(p=min(yj,ya)+1;p<max(yj,ya);p++)
								{
									if(d[xa][p]==1 || d[xa][p]==0 && ((k>>K[xa][p]&1)==0))
									{
										F=0;
										break;
									}
								}
							}
							if(F==0)continue;
							f[i][j]+=f[k][a];
						}
					}
				}
			}
		}
		I ans=0;
		for(i=0;i<h;i++)ans+=f[hh-1][i];
		printf("%I64d\n",ans);
	}
	return 0;
}