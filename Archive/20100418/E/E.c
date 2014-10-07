#include <stdio.h>

int main()
{
	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c)==3)
	{
		if(a<1)puts("1");
		else if(a<2 && b==0)puts("2");
		else if(a<3 && b==0)puts("3");
		else if(a+b*2<4)puts("4");
		else printf("%d\n",a+b*2+c*5+1);
	}
	return 0;
}