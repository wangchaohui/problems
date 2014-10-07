#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int D[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long a[400],b[400];

int ans_count = 0;
long long ans[4050000];
void work(){
	int i = 0,j,k;
	long long t,m;
	while(1){
		j = i/2;
		if(i&1){
			t = 0;
			for(m = pow(10.0,j+0.0)-1; m >= 0;--m){
				t += (m*pow(10.0,j+1.0)+m);
				for(k = 0;k < 10;++k)
					ans[ans_count++] = t+k*pow(10.0,j+0.0);
			}
		}
		else{
			for(m = pow(10.0,j+0.0)-1; m >= 0;--m)
				ans[ans_count++] = (m*pow(10.0,j+0.0)+m);
			{
				t += (m*pow(10.0,j+1.0)+m);
				for(k = 0;k < 10;++k)
					ans[ans_count++] = t+k*pow(10.0,j+0.0);
			}
		}
	}
}
int main()
{
	int T,k,i,tot,j;
	tot=0;
	for(i=1;i<=12;i++)
		for(j=1;j<=D[i];j++)
		{
			a[tot]=i*100+j;
			b[tot]=(j%10)*1000+(j/10)*100+(i%10)*10+i/10;
			tot++;
		}

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&k);
	}
	return 0;
}