#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

#define DIGITS 4
#define BASE 10000

typedef long long I;
typedef int BG[300];


int isone(int *x)
{
	return x[0]==1 && x[1]==1;
}

int iszero(int *x)
{
	return x[0]==1 && x[1]==0;
}

int* toone(int *x)
{
	x[0]=1;x[1]=1;
	return x;
}

int* tozero(int *x)
{
	x[0]=1;x[1]=0;
	return x;
}

void prbig(int *x)
{
	int a;
	printf("%d",x[x[0]]);
	for(a=x[0]-1;a>=1;a--)
		printf("%0*d",DIGITS,x[a]);
}

int* mulint(int *x,int n)
{
	int a,c=0;
	I t;
	if(n==0)return tozero(x);
	for(a=1;a<=x[0];a++){t=(I)x[a]*n+c;c=t/BASE;x[a]=t%BASE;}
	for(;c;c/=BASE)x[++x[0]]=c%BASE;
	return x;
}

int* incint(int *x,int c)
{
	int a;
	I t;
	for(a=1;c && a<=x[0];a++){t=(I)x[a]+c;c=t/BASE;x[a]=t%BASE;}
	for(;c;c/=BASE)x[++x[0]]=c%BASE;
	return x;
}

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

void incbig(int *x,int *n)
{
	int a,l;
	if(n[0]==1 && n[1]==0)return;
	l=x[0]>n[0]?x[0]+1:n[0]+1;
	for(a=x[0]+1;a<=l;a++)x[a]=0;
	for(a=1;a<=n[0];a++)x[a]+=n[a];
	for(a=1;a<l;a++)
		if(x[a]>=BASE){x[a]-=BASE;x[a+1]++;}
	x[0]=x[l]?l:l-1;
}

void decbig(int *x,int *y)
{
	int a;
	for(a=1;a<=y[0];a++)x[a]-=y[a];
	for(a=1;a<x[0];a++)
		if(x[a]<0){x[a]+=BASE;x[a+1]--;}
	for(;x[0]>1 && x[x[0]]==0;x[0]--);
}

void addbig(int *x,int *y,int *z)
{
	int a,l;
	l=x[0]>y[0]?x[0]+1:y[0]+1;
	for(a=x[0]+1;a<=l;a++)z[a]=0;
	for(a=1;a<=x[0];a++)z[a]=x[a];
	for(a=1;a<=y[0];a++)z[a]+=y[a];
	for(a=1;a<l;a++)
		if(z[a]>=BASE){z[a]-=BASE;z[a+1]++;}
	z[0]=z[l]?l:l-1;
}

void subbig(int *x,int *y,int *z)
{
	int a;
	for(a=1;a<=x[0];a++)z[a]=x[a];
	for(a=1;a<=y[0];a++)z[a]-=y[a];
	for(a=1;a<x[0];a++)
		if(z[a]<0){z[a]+=BASE;z[a+1]--;}
	for(z[0]=x[0];z[0]>1 && z[z[0]]==0;z[0]--);
}

int cmpbig(const int *x,const int *y)
{
	int a;
	if(x[0]!=y[0])return x[0]-y[0];
	for(a=x[0];a>=1;a--)
		if(x[a]!=y[a])return x[a]-y[a];
	return 0;
}

void inttobig(int n,int *d)
{
	int i=0;
	for(;!i || n;d[++i]=n%BASE,n/=BASE);
	d[0]=i;
}

int bigtoint(int *d)
{
	int i,r=0;
	for(i=d[0];i>=1;r=r*BASE+d[i],i--);
	return r;
}

void mulbig(int *x,int *y,int *z)
{
	int a,b,l;
	l=x[0]+y[0];
	for(a=0;a<=l;a++)z[a]=0;
	for(a=1;a<=x[0];a++)
	{
		for(b=1;b<=y[0];b++)
		{
			z[a+b-1]+=x[a]*y[b]; 
			if(z[a+b-1]>=BASE){z[a+b]+=z[a+b-1]/BASE;z[a+b-1]%=BASE;}
			/* carefully */
		}
	}
	//for(b=1;b<l;b++)
	//	if(z[b]>=BASE){z[b+1]+=z[b]/BASE;z[b]%=BASE;}
	for(z[0]=l;z[0]>1 && z[z[0]]==0;z[0]--);
}

void cpybig(int *x,int *y)
{
	int i;
	for(i=0;i<=y[0];i++)x[i]=y[i];
}

struct B{
	BG d;
	bool operator<(const B &b)const{
		return cmpbig(d,b.d)<0;
	}
	bool operator>(const B &b)const{
		return cmpbig(d,b.d)>0;
	}
};

priority_queue<B,vector<B>,greater<B> > Q;

B d[110];

int main()
{
	int n,k,i,t,cc;
	B a,b,c;
	BG x,y;
	while(scanf("%d %d",&n,&k)==2)
	{
		while(!Q.empty())Q.pop();
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			inttobig(t,d[i].d);
			Q.push(d[i]);
		}
		while(Q.size()>1)
		{
			a=Q.top();Q.pop();
			b=Q.top();Q.pop();
			mulbig(a.d,b.d,c.d);
			incint(c.d,1);
			Q.push(c);
		}
		sort(d,d+n);
		cc=0;toone(x);
		for(i=n-1;i>=0;i--)
		{
			mulbig(x,d[i].d,y);
			cpybig(x,y);
			if(++cc==k)
			{
				cc=1;
				incint(x,1);
			}
		}
		if(cc!=1)incint(x,1);
		a=Q.top();
		cpybig(y,a.d);
		decbig(y,x);
		prbig(y);putchar('\n');
	}
	return 0;
}
