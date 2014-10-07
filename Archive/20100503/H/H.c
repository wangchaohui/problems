#include <stdio.h>
#include <memory.h>

char d[40][40],v[40][40],va[40][40];
int p[900000],op,cl,z,w,h,u[5][2]={{0,-1},{0,1},{1,0},{-1,0},{0,0}},CATCH;
char s[900000];

void dfs(int top,int nnn)
{
	int qx,qy,ax,ay,q,a,i,j;
	int nqx,nqy,nax,nay,nq,na,k,e2,e3,e4,nc,a4,a1;
	s[top]=1;
	q=top/z;a=top%z;
	qx=q/w;qy=q%w;
	ax=a/w;ay=a%w;
	if(q==a)
	{
		s[top]=3;
		return;
	}
	if(d[qx][qy]=='E')
	{
		s[top]=2;
		return;
	}
	a4=0;a1=0;
	for(i=0;i<5;i++)
	{
		nqx=qx+u[i][0];nqy=qy+u[i][1];
		if(nqx<0 || nqx>=h || nqy<0 || nqy>=w || d[nqx][nqy]=='#')continue;
		//if((nqx!=qx || nqy!=qy) && v[nqx][nqy]==1)continue;
		if(nnn==0 && (nqx!=qx || nqy!=qy))continue;
		v[nqx][nqy]=1;
		nq=nqx*w+nqy;
		e2=e3=e4=0;nc=0;
		for(j=0;j<5;j++)
		{
			nax=ax+u[j][0];nay=ay+u[j][1];
			if(nax<0 || nax>=h || nay<0 || nay>=w || d[nax][nay]=='#')continue;
			na=nax*w+nay;
			k=nq*z+na;
			if(k==nnn)continue;
			if(k==top){e4=1;continue;}
			if(s[k]==0)
				if(nqx!=qx || nqy!=qy || nax!=ax || nay!=ay)
					dfs(k,1);
				else
					dfs(k,0);
			//printf("%d %d %d %d %d\n",nqx,nqy,nax,nay,s[k]);
			if(s[k]==1)
				nc=1;
			if(s[k]==2)e2=1;
			if(s[k]==3){e3=1;break;}
			if(s[k]==4)e4=1;
		}
		if(nqx!=qx || nqy!=qy)v[nqx][nqy]=0;
		if(e2 && !e3 && !e4 && !nc)
		{
			s[top]=2;
			return;
		}
		if(!e3 && !nc)
		{
			a4=1;
		}
		if(!e3 && nc)
		{
			a1=1;
		}
	}
	if(a1==1)
	{
		s[top]=1;
		return;
	}
	if(a4==1)
	{
		s[top]=4;
		return;
	}
	s[top]=3;
	return;
}

int main()
{
	int i,j,qx,qy,ax,ay,q,a,k,t;
	while(scanf("%d %d",&w,&h)==2)
	{
	z=w*h;
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
		{
			scanf(" %c",&d[i][j]);
			if(d[i][j]=='Q')
			{
				qx=i;qy=j;
			}
			if(d[i][j]=='A')
			{
				ax=i;ay=j;
			}
		}
	q=qx*w+qy;a=ax*w+ay;
	k=q*z+a;
	op=1;cl=0;
	memset(s,0,sizeof(s));
	memset(v,0,sizeof(v));
	memset(va,0,sizeof(va));
	v[qx][qy]=1;
	s[k]=1;
	dfs(k,1);
	t=s[k];
	if(s[k]==2)puts("Queen can escape.");
	if(s[k]==3)puts("Army can catch Queen.");
	if(s[k]==1 || s[k]==4)puts("Queen can not escape and Army can not catch Queen.");
	}
	return 0;
}