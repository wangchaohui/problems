#include <stdio.h>
#include <set>
#include <string.h>
#include <string>
using namespace std;

int pc[4]={4,4,5,4};
char pl[4][10]={"Chinese","English","Japanese","German"};
int ppl[4][5]={{3,2,3,2},{2,3,4,3},{4,4,6,2,2},{4,3,3,3}};
set<string> s[4][4];
char pp[4][5][10][10]={
{{"[pn]","shi","[n]"},
{"[pn]","[vi]"},
{"[pn]","[vt]","[n]"},
{"ni","hao"}},

{{"[pn]","[vi]"},
{"[pn]","[vt]","[n]"},
{"There","is","a","[n]"},
{"Happy","new","year"}},

{{"[pn]","ha","[n]","desu"},
{"[pn]","ha","[n]","da"},
{"[pn]","ha","[n]","ga","[adj]","desu"},
{"[n]","saikou"},
{"yoi","otoshiwo"}},

{{"Ich","habe","ein","[n]"},
{"Ich","bin","[n]"},
{"Ich","heisse","[n]"},
{"Du","hast","[n]"}}
};

int getL(char *s)
{
	switch(s[0])
	{
	case 'C':
		return 0;
	case 'E':
		return 1;
	case 'J':
		return 2;
	case 'G':
		return 3;
	}
}

int getT(char *s)
{
	if(strcmp(s,"[pn]")==0)return 0;
	if(strcmp(s,"[n]")==0)return 1;
	if(strcmp(s,"[vi]")==0)return 2;
	if(strcmp(s,"[vt]")==0)return 3;
	if(strcmp(s,"[adj]")==0)return 2;
	return -1;
}

int check(char *ss,char *t,int j)
{
	string jyh=ss;
	int tt=getT(t);
	if(tt==-1)return !strcmp(ss,t);
	return s[j][tt].find(jyh)!=s[j][tt].end();
}

void solve()
{
	int T,C=0,n,m,i,j,k,l,t,c,a;
	char lang[10],word[40],type[10],hang[40],*p,pa[30][40];
	
	string jyh;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			s[i][j].clear();
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s %s %s",lang,type,word);
		l=getL(lang);
		t=getT(type);
		jyh=word;
		s[l][t].insert(jyh);
	}
	gets(hang);
	for(i=1;i<=m;i++)
	{
		gets(hang);
		c=0;
		p=hang;
		do{
			sscanf(p,"%s",pa[c]);
			c++;
			p=strchr(p,' ');
			if(!p)break;
			while(*p==' ')p++;
		}while(*p);
		for(j=0;j<4;j++)
		{
			for(k=0;k<pc[j];k++)
			{
				if(c!=ppl[j][k])continue;
				for(a=0;a<ppl[j][k];a++)
				{
					if(!check(pa[a],pp[j][k][a],j))break;
				}
				if(a==ppl[j][k])break;
			}
			if(k!=pc[j])
			{
				puts(pl[j]);
				break;
			}
		}
		if(j==4)puts("I don't know.");
	}
}

int main()
{
	int T,C=0;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d:\n",++C);
		solve();
	}
	return 0;
}