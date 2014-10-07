#include <stdio.h>
#include <string.h>

char s[10000];
char Name[100],Weapon[2];
char Name2[100],Weapon2[2];

void match()
{
	int i,j;
	for(j=0;j<2;j++)
		for(i=0;i<2;i++)
		{
			if(Weapon[i]=='R' && Weapon2[j]=='S' || Weapon[i]=='S' && Weapon2[j]=='P' || Weapon[i]=='P' && Weapon2[j]=='R' )
			{
				printf("%s, Weapon: %c VS %s, Weapon: %c\n",Name,Weapon[i],Name2,Weapon2[j]);
				printf("Won: %s\n",Name);
				return;
			}
			if(Weapon[i]=='S' && Weapon2[j]=='R' || Weapon[i]=='P' && Weapon2[j]=='S' || Weapon[i]=='R' && Weapon2[j]=='P' )
			{
				printf("%s, Weapon: %c VS %s, Weapon: %c\n",Name,Weapon[i],Name2,Weapon2[j]);
				printf("Won: %s\n",Name2);
				strcpy(Name,Name2);Weapon[0]=Weapon2[0];Weapon[1]=Weapon2[1];
				return;
			}
		}
	printf("Won: %s\n",Name);
}

int sd(char *s)
{
	int i,j,f;
	char *p;
	for(i=1;s[i] && s[i]!=']';i++)
	{
		if(s[i]=='[')
		{
			p=s+i+sd(s+i);
			break;
		}
	}
	j=1;
	if(!(s[i] && s[i]!=']'))
	{
		f=0;
		for(;j<i && s[j]!='[' && s[j]!=']';j++)
			if(s[j]=='(')
			{
				sscanf(s+j,"(%[^-]-%c-%c)",Name,&Weapon[0],&Weapon[1]);
				while(s[j]!=')')j++;
				f=1;
				break;
			}
			if(f==0 && s[i] && s[i]!=']')
			{
				for(;*p && *p!=']';p++)
					if(*p=='(')
					{
						sscanf(p,"(%[^-]-%c-%c)",Name,&Weapon[0],&Weapon[1]);
						while(*p!=')')p++;
						f=1;
						break;
					}
			}
	}
	do{
		f=0;
		for(;j<i && s[j]!='[' && s[j]!=']';j++)
			if(s[j]=='(')
			{
				sscanf(s+j,"(%[^-]-%c-%c)",Name2,&Weapon2[0],&Weapon2[1]);
				while(s[j]!=')')j++;
				match();
				f=1;
				break;
			}
		if(f==0 && s[i] && s[i]!=']')
		{
			for(;*p && *p!=']';p++)
				if(*p=='(')
				{
					sscanf(p,"(%[^-]-%c-%c)",Name2,&Weapon2[0],&Weapon2[1]);
					while(*p!=')')p++;
					match();
					f=1;
					break;
				}
		}
	}while(f);
	if(s[i] && s[i]!=']')if(*p)return p-s+1;
	else return p-s;
	if(s[j])return j+1;
	return j;
}

int main()
{
	int i,f=0;
	while(gets(s) && s[0])
	{
		if(f)putchar('\n');else f=1;
		sd(s);
		printf("Final Winner: (%s-%c-%c)\n",Name,Weapon[0],Weapon[1]);
	}
	return 0;
}
