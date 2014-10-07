#include <stdio.h>

int main()
{
	char s[1000];
	int i,j,x,y;
	while(gets(s))
	{
		j=0;
		for(i=0;s[i];i++)if(s[i]!=',')s[j++]=s[i];
		s[j]='\0';
		if(sscanf(s,"%d %d",&x,&y)==2)printf("%d\n",x+y);
	}
	return 0;
}
