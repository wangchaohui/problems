#include <stdio.h>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

int z[10],zz[10],xx;

int dfs(int n,int m)
{
	int i;
	if(m==0)return 1;
	if(n==0)return 0;
	for(i=1;i<=xx;i++)
	{
		if(zz[i])
		{
			zz[i]--;
			if(dfs(n-1,(m+9-i)%9))return 1;
			zz[i]++;
		}
	}
	return 0;
}

string y,m;

int main()
{
	int T,C=0,i,j,f,t,h,x;
	int a,b;
	char s[2000];
	scanf("%d",&T);
	while(T--)
	{
		m="";
		printf("Case %d: ",++C);
		scanf("%s",s);
		for(i=0;i<10;i++)z[i]=0;
		h=0;
		for(i=0;s[i];i++)
		{
			t=s[i]-'0';
			z[t]++;
			h=(h+t)%9;
		}
		f=0;
		if(z[0]==0)
		{
			for(a=1;a<=9;a++)
				for(b=1;b<=a;b++)
				{
					if((a*10+b)%4==0)
					{
						if(a==b && z[a]>=2 || a!=b && z[a]>=1 && z[b]>=1)
						{
							z[a]--;z[b]--;
							// printf("a %d b %d v %d\n",a,b,h);
							memcpy(zz,z,sizeof(z));
							for(i=0;i<=9;i++)
							{
								for(xx=1;xx<=9;xx++)
									if(dfs(i,h))break;
								if(xx!=10)break;
							}
							if(i==10)
							{
								z[a]++;z[b]++;
								continue;
							}
							y = "";
							for(i=9;i>=1;i--)
								for(j=1;j<=zz[i];j++)y+=i+'0';
							y+=a+'0';
							y+=b+'0';
							if(y.size() > m.size() || y.size() ==
								m.size() && y>m)
								m=y;
							//printf("%d%d\n",a,b);
							f=1;
							z[a]++;z[b]++;
						}
					}
					if((a+b*10)%4==0)
					{
						if(a==b && z[a]>=2 || a!=b && z[a]>=1 && z[b]>=1)
						{
							z[a]--;z[b]--;
							//printf("a %d b %d v %d\n",a,b,h);
							memcpy(zz,z,sizeof(z));
							for(i=0;i<=9;i++)
							{
								for(xx=1;xx<=9;xx++)
									if(dfs(i,h))break;
								if(xx!=10)break;
							}
							if(i==10)
							{
								z[a]++;z[b]++;
								continue;
							}
							y = "";
							for(i=9;i>=1;i--)
								for(j=1;j<=zz[i];j++)y+=i+'0';
							y+=b+'0';
							y+=a+'0';
							if(y.size() > m.size() || y.size() ==
								m.size() && y>m)
								m=y;
							f=1;
							z[a]++;z[b]++;
						}
					}
				}
		}
		else if(z[0]==1)
		{
			for(a=1;a<=9;a++)
			{
				if((a)%2==0)
				{
					if(z[a]>=1)
					{
						z[a]--;z[0]--;
						//printf("a %d b %d v %d\n",a,0,h);
						memcpy(zz,z,sizeof(z));
						for(i=0;i<=9;i++)
						{
							for(xx=1;xx<=9;xx++)
								if(dfs(i,h))break;
							if(xx!=10)break;
						}
						if(i==10)
						{
							z[a]++;z[0]++;
							continue;
						}
						y = "";
						for(i=9;i>=1;i--)
							for(j=1;j<=zz[i];j++)y+=i+'0';
						y+=a+'0';
						y+='0';
						if(y.size()>m.size() || y.size()==m.size() && y>m)
							m=y;
						f=1;
						z[a]++;z[0]++;
					}
				}
			}
			y="0";
			if(y.size() > m.size() || y.size() == m.size() && y>m)
				m=y;
			f=1;
		}
		else if(z[0]>=2)
		{
			z[0]--;z[0]--;
			//printf("a %d b %d v %d\n",0,0,h);
			memcpy(zz,z,sizeof(z));
			for(i=0;i<=9;i++)
			{
				for(xx=1;xx<=9;xx++)
					if(dfs(i,h))break;
				if(xx!=10)break;
			}
			if(i==10)while(1);
			x=0; y = "";
			for(i=9;i>=1;i--)
				for(j=1;j<=zz[i];j++)x=1,y+=i+'0';
			if(x)
			{
				for(j=1;j<=zz[0];j++)y+='0';
				y+='0';y+='0';
			}
			else
				y+='0';
			if(y.size() > m.size() || y.size() == m.size() && y>m)
				m=y;
			f=1;
		}
		if(f==0)puts("impossible");
		else printf("%s\n",m.c_str());
	}
	return 0;
}