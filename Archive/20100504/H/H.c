#include <stdio.h>
#include <memory.h>

char s[90000];

int main()
{
	int d[20],i,t,n,c,b;
	while(gets(s)!=NULL)
	{
		if(s[0]=='0' && s[1]=='\0')break;
		memset(d,0,sizeof(d));
		d[0]=1;
		t=0;c=0;
		for(i=0;s[i];i++)
		{
			n=s[i]-'0';
			if(n==0)
			{
				c+=d[t]-1;
				//d[t]++;
				b=0;
				continue;
			}
			if(i%2==0)t=(t+n)%11;
			else t=(t+11-n)%11;
			c+=d[t];
			d[t]++;
			b=n;
		}
		printf("%d\n",c);
	}
	return 0;
}