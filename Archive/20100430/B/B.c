#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define maxw 1000000000

typedef struct{
	int mp,damage;
}Magic;

typedef struct{
	int n,hp[105];
}Monsters;

Magic all[105],single[105];
int ma,ms,mm[100010],cc[100010],ANS;

int main()
{
	int n,m,i,j,mp,damage,ss,mg;
	char s[10];
	Monsters monster;
	scanf("%d",&n);
	monster.n=n;mg=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&monster.hp[i]);
		if(monster.hp[i]>mg)mg=monster.hp[i];
	}
	scanf("%d",&m);
	ma=0;ms=0;
	for(i=0;i<m;i++)
	{
		scanf("%*s %d %s %d",&mp,&s,&damage);
		if(s[0]=='A' && damage>0)
		{
			all[ma].mp=mp;
			all[ma].damage=damage;
			ma++;
		}
		if(s[0]=='S' && damage>0)
		{
			single[ms].mp=mp;
			single[ms].damage=damage;
			ms++;
		}
	}
	for(i=1;i<=100000;i++)mm[i]=maxw;
	mm[0]=0;
	for(j=0;j<ms;j++)
	{
		for(i=0;i<=100000;i++)
			if(i-single[j].damage<0)
			{
				if(mm[i]>single[j].mp)
					mm[i]=single[j].mp;
			}
			else if(mm[i]>mm[i-single[j].damage]+single[j].mp)
				mm[i]=mm[i-single[j].damage]+single[j].mp;
	}
	for(i=1;i<=100000;i++)cc[i]=maxw;
	cc[0]=0;
	for(j=0;j<ma;j++)
	{
		for(i=0;i<=100000;i++)
			if(i-all[j].damage<0)
			{
				if(cc[i]>all[j].mp)
					cc[i]=all[j].mp;
			}
			else if(cc[i]>cc[i-all[j].damage]+all[j].mp)
				cc[i]=cc[i-all[j].damage]+all[j].mp;
	}
	ANS=1000000000;
	if(ms==0){printf("%d\n",cc[mg]);return;}
	for(i=0;i<=100000;i++)
	{
		ss=cc[i];
		for(j=0;j<monster.n;j++)
			if(monster.hp[j]>i)
				ss+=mm[monster.hp[j]-i];
		if(ss<ANS)ANS=ss;
		if(ma==0)break;
	}
	printf("%d\n",ANS);
	return 0;
}