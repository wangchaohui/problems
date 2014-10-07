#include <stdio.h>

int main()
{
	int A,B,N,CC=0;
	scanf("%d",&N);
	while(N--)
	{
		int a[16];
		int i;
		for(i=1;i<=15;i++)scanf("%d",&a[i]);
		a[15]%=2;
		int t=0;
		A=0;B=0;
		if(a[15]%2)
		{
			A++;
			t=1;
		}
		int aa,bb;
		aa=a[3]+a[4];
		bb=a[5]+a[6];
		if(aa>=bb)
		{
			aa-=bb;
			if(t==0)
			{
				A-=aa/2;
				if(aa%2)t=1;
			}
			else
			{
				A-=(aa+1)/2;
				if(aa%2)t=0;
			}
		}
		else
		{
			aa=bb-aa;
			if(t==0)
			{
				A+=(aa+1)/2;
				if(aa%2)t=1;
			}
			else
			{
				A+=aa/2;
				if(aa%2)t=0;
			}
		}
		aa=a[11]+a[12]+a[13]+a[14];
		if(aa%2)
		{
			t=1-t;
		}
		aa=a[7]+a[8];
		bb=a[9]+a[10];
		if(aa>=bb)
		{
			aa-=bb;
			if(t==0)
			{
				A+=aa/2;
				if(aa%2)t=1;
			}
			else
			{
				A+=(aa+1)/2;
				if(aa%2)t=0;
			}
		}
		else
		{
			aa=bb-aa;
			if(t==0)
			{
				A-=(aa+1)/2;
				if(aa%2)t=1;
			}
			else
			{
				A-=aa/2;
				if(aa%2)t=0;
			}
		}
		A+=(a[1]-a[2])*2;
		printf("Case #%d: ",++CC);
		if(t==0)
		{
			if(A>0)puts("Alice");
			else puts("Bob");
		}
		else
		{
			if(A<0)puts("Bob");
			else puts("Alice");
		}
	}
	return 0;
}