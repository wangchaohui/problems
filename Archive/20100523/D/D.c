#include <stdio.h>
#include <ctype.h>
#include <memory.h>

typedef struct{
	int card[2][11];
}JM;

JM a;

int pl(int *a)
{
	int i,h;
	h=0;
	for(i=0;i<10;i++)
		h+=a[i];
	if(h%3!=0)return 0;
	for(i=0;i<8;i++)
		if(a[i])
		{
			if(a[i+1]<a[i] || a[i+2]<a[i])return 0;
			a[i+1]-=a[i];a[i+2]-=a[i];
		}
	if(a[8] || a[9])return 0;
	return 1;
}

int iswin(JM *a)
{
	int i,j;
	JM b;
	for(j=0;j<10;j++)
		if(a->card[0][j]+a->card[1][j]>=3)
		{
			if(a->card[0][j]==2)
			{
				b=*a;
				b.card[0][j]=0;
				b.card[1][j]--;
				if(pl(b.card[0]) && pl(b.card[1]))return 1;
			}
			if(a->card[1][j]==2)
			{
				b=*a;
				b.card[1][j]=0;
				b.card[0][j]--;
				if(pl(b.card[0]) && pl(b.card[1]))return 1;
			}
		}
	if(pl(a->card[0]) && pl(a->card[1]))return 1;
	return 0;
}

int main()
{
	int n,i,j,h;
	char s[100];
	while(scanf("%d %s",&n,s)==2 && n)
	{
		memset(a.card,0,sizeof(a.card));
		for(i=0;i<n;i++)
		{
			if(isupper(s[i]))
				a.card[0][s[i]-'A']++;
			else
				a.card[1][s[i]-'a']++;
		}
		h=n;
		for(i=0;i<2;i++)
		{		
			for(j=0;j<10;j++)
				if(a.card[i][j]>=3)
				{
					h-=a.card[i][j];
					a.card[i][j]=0;
				}
		}
		if(h%3!=0 || !iswin(&a))
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}