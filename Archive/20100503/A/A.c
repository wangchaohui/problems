#include <stdio.h>
#include <memory.h>
#include <math.h>

int I[300],O[300],R[300],C[300];

int main()
{
	int s,a,c,n,i,ms,ma,mc;
	double H,t,m=100;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&I[i]);
	for(s=0;s<16;s++)
		for(a=0;a<16;a++)
			for(c=0;c<16;c++)
			{
				memset(C,0,sizeof(C));
				R[0]=s;
				for(i=1;i<=n;i++)
				{
					R[i]=(a*R[i-1]+c)%256;
					O[i]=(I[i]+R[i])%256;
					C[O[i]]++;
				}
				H=0;
				for(i=0;i<256;i++)
					if(C[i]>0)
					{
						t=(double)C[i]/n;
						H-=t*log(t);
					}
				if(H+1e-8<m)
				{
					m=H;
					ms=s,ma=a,mc=c;
				}

			}
	printf("%d %d %d\n",ms,ma,mc);
	return 0;
}