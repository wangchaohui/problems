#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIGITS 4
#define BASE 10000

typedef long long I;
typedef int BG[30000];

void strtobig(char *s,int *d)
{
	int a,l,i;
	while(*s=='0')s++;
	if(*s=='\0'){d[0]=1;d[1]=0;return;}
	l=strlen(s);
	d[0]=(l-1)/DIGITS+1;
	for(i=1;i<d[0];i++)
		for(d[i]=0,a=l-DIGITS*i;a<l-DIGITS*(i-1);a++)
			d[i]=d[i]*10+s[a]-'0';
	for(d[i]=0,a=0;a<l-DIGITS*(i-1);a++)
		d[i]=d[i]*10+s[a]-'0';
}

int modint(int *x,int y)
{
	int a,r=0;
	for(a=x[0];a>=1;a--)
		r=((I)r*BASE+x[a])%y;
	return r;
}

char s[100010];

BG d;

int main()
{
	int i,x;
	while(gets(s))
	{
		if(strlen(s)==1)
		{
			for(i=9;i>=1;i--)
			{
				if(i!=9)putchar(' ');
				printf("%c",s[0]);
			}
			putchar('\n');
			continue;
		}
		strtobig(s,d);
		for(i=9;i>=1;i--)
		{
			x=modint(d,i);
			for(;x+i<10;x+=i);
			if(i!=9)putchar(' ');
			printf("%d",x);
		}
		putchar('\n');
	}
	return 0;
}