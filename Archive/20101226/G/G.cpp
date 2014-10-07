#include <stdio.h>
#include <string.h>

typedef long long I;

int main()
{
	int n,t;
	I w,b,z;
	char s[100];
	while(scanf("%d",&n)==1)
	{
		w=b=z=0;
		while(n--)
		{
			scanf("%s %d",s,&t);
			if(strcmp(s,"ww")==0)w+=t*2;
			if(strcmp(s,"w")==0)w+=t;
			if(strcmp(s,"bb")==0)b+=t*2;
			if(strcmp(s,"b")==0)b+=t;
			if(strcmp(s,"wb")==0)z-=t;
			if(strcmp(s,"bw")==0)z+=t;
		}
		if(z>=0)
		{
			if(w+(z+1)/2>b)printf("win");
			else printf("lose");
			if(w+z/2<b)printf(" lose\n");
			else printf(" win\n");
		}
		else
		{
			if(w>b+(-z)/2)printf("win");
			else printf("lose");
			if(w<b+(-z+1)/2)printf(" lose\n");
			else printf(" win\n");
		}
	}
	return 0;
}
