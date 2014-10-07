#include <stdio.h>
#include <string.h>

typedef long long I;
typedef int BG[3000];

int p[2][10];
BG A,B,C;

void strtobig(char *s,int *d)
{
	int a,l;
	l=strlen(s);
	d[0]=l;
	for(a=0;a<l;a++)d[l-a]=s[a]-'0';
}

void mulbig(int *x,int *y,int *z)
{
	int a,b,l;
	l=x[0]+y[0];
	for(a=0;a<=l;a++)z[a]=0;
	for(a=1;a<=x[0];a++)
	{
		if(x[a]==0)continue;
		for(b=1;b<=y[0];b++)
			z[a+b-1]^=y[b]; /* changed for BASE 2 */
	}
	for(b=1;b<l;b++)
		if(z[b]>=2){z[b+1]+=z[b]/2;z[b]%=2;}
	z[0]=l-1;
}

int main()
{
	char s[2000];
	int n,i,j,CC=0;
	strtobig("1011011",p[0]);
	strtobig("1111001",p[1]);
	while(scanf("%s",s)==1)
	{
		printf("Case %d: ",++CC);
		strtobig(s,A);
		mulbig(p[0],A,B);
		mulbig(p[1],A,C);
		for(i=B[0];i>=1;i--)
			printf("%d%d",B[i],C[i]);
		putchar('\n');
	}
	return 0;
}