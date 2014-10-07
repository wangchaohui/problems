#include <stdio.h>

int value(char ch)
{
	switch(ch)
	{
	case 'A':
		return 14;
	case 'K':
		return 13;
	case 'Q':
		return 12;
	case 'J':
		return 11;
	case 'T':
		return 10;
	default:
		return ch-'0';
	}
}

int main()
{
	char Trump,rank[4][15],suit[4][15];
	int i,j,lead,c,w,ns,ew;
	while(scanf(" %c",&Trump)==1 && Trump!='#')
	{
		ns=ew=0;
		for(i=0;i<4;i++)
			for(j=0;j<13;j++)
			{
				scanf(" %c",&rank[i][j]);
				scanf(" %c",&suit[i][j]);
			}
		lead=0;
		for(i=0;i<13;i++)
		{
			c=0;w=lead;
			for(j=(lead+1)%4;c<4;j=(j+1)%4,c++)
			{
				if(suit[w][i]==Trump)
				{
					if(suit[j][i]==Trump && value(rank[j][i])>value(rank[w][i]))
					{
						w=j;
					}
				}
				else
				{
					if(suit[j][i]==Trump || suit[j][i]==suit[lead][i] && value(rank[j][i])>value(rank[w][i]))
					{
						w=j;
					}
				}
			}
			lead=w;
			if(w%2==0)
				ns++;
			else
				ew++;
		}
		if(ns>ew)printf("NS %d\n",ns-6);
		else printf("EW %d\n",ew-6);
	}
	return 0;
}