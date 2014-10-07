#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;

struct tree{
	int n;
	double p;
	tree *left,*right;
};

map<string,int> m;

tree b[300];
int tot,mtot,i;
double pp[300];

string getTAG()
{
	string r;
	int ch;
	while((ch=getchar()) && isspace(ch));
	if(ch==EOF)exit(0);
	while((ch=getchar())!='>')r+=ch;
	return r;
}

void getLeaf(tree *x)
{
	char s[50];
	string jyh;
	tree *y;
	getTAG();
	scanf("%[^<]",s);
	jyh=s;
	if(m.find(jyh)==m.end())m[jyh]=mtot++;
	x->n=m[jyh];
	getTAG();
	getTAG();
	scanf("%lf",&x->p);
	pp[x->n]=x->p;
	getTAG();
	getTAG();
}

void getNode(tree *x)
{
	char s[50];
	string jyh;
	tree *y;
	jyh=getTAG();
	scanf("%[^<]",s);
	if(strcmp(s,"or")==0)x->n=-1;
	else x->n=-2;
	getTAG();//</value>
	do
	{
		jyh=getTAG();
		if(jyh=="node")
		{
			y=&b[tot++];
			y->left=NULL;
			y->right=x->left;
			x->left=y;
			getNode(y);
		}
		if(jyh=="leaf")
		{
			y=&b[tot++];
			y->left=NULL;
			y->right=x->left;
			x->left=y;
			getLeaf(y);
		}
	}while(jyh!="/node" && jyh!="/root");
}

int getP(tree *x)
{
	tree *y;
	if(x->n>=0)
		if(i>>x->n&1)
			return 1;
		else
			return 0;
	if(x->n==-1)
	{
		for(y=x->left;y;y=y->right)
			if(getP(y))
				return 1;
		return 0;
	}
	if(x->n==-2)
	{
		for(y=x->left;y;y=y->right)
			if(!getP(y))
				return 0;
		return 1;
	}
}

int main()
{
	char s[50];
	string jyh;
	tree *x;
	int ch,j;
	int h;
	double ss,t;
	while((ch=getchar())!=EOF)
	{
		while(ch=='#')ch=getchar();
		if(ch==EOF)break;
		getTAG();m.clear();
		tot=0;mtot=0;
		x=&b[tot++];
		x->left=NULL;x->right=NULL;
		getNode(x);
		h=1<<mtot;
		ss=0;
		for(i=0;i<h;i++)
		{
			t=1;
			for(j=0;j<mtot;j++)
				if(i&1<<j)
					t*=pp[j];
				else
					t*=1-pp[j];
			if(getP(b))
				ss+=t;
		}
		printf("%.3f\n",ss);
		scanf(" ");
	}
	return 0;
}