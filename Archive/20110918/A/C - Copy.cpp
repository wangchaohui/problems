#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct Star{
	string Name;
	string Rise;
	string Fall;
	string Exalt;
	string Debilitate;
};

Star stars[10]={
	{"Sun","Leo","Aquarius","Aries","Libra"},
	{"Moon","Cancer","Capricorn","Taurus","Scorpio"},
	{"Mercury","Gemini Virgo","Sagittarius Pisces","Aquarius","Leo"},
	{"Venus","Taurus Libra","Scorpio Aries","Pisces","Virgo"},
	{"Mars","Aries Scorpio","Libra Taurus","Capricorn","Cancer"},
	{"Jupiter","Sagittarius Pisces","Gemini Virgo","Cancer","Capricorn"},
	{"Saturn","Capricorn Aquarius","Cancer Leo","Libra","Aries"},
	{"Uranus","Aquarius","Leo","Scorpio","Taurus"},
	{"Neptune","Pisces","Virgo","Sagittarius","Gemini"},
	{"Pluto","Scorpio","Taurus","Virgo","Pisces"}};

string constellations[12]={"Aries","Taurus","Gemini","Cancer","Leo","Virgo",
	"Libra","Scorpio","Sagittarius","Capricorn","Aquarius","Pisces"};

int d[10];
int energy[10];
int capacity[10];

int faculty[10][10];

int findStar(string star,string constellation)
{
	int i;
	for(i=0;stars[i].Name!=star;i++);
	energy[i]=5;
	capacity[i]=3;
	if(stars[i].Rise.find(constellation)!=string::npos)energy[i]+=3;
	if(stars[i].Fall.find(constellation)!=string::npos)energy[i]-=3;
	if(stars[i].Exalt.find(constellation)!=string::npos)capacity[i]+=2;
	if(stars[i].Debilitate.find(constellation)!=string::npos)capacity[i]-=2;
	return i;
}

int findConstellation(string constellation)
{
	int i;
	for(i=0;constellations[i]!=constellation;i++);
	return i;
}

struct Aspect{
	int degree;
	int deviation;
	int alterEnergy;
	int alterCapacity;
};

Aspect aspects[5]={{0,5},{60,3,0,1},{90,4,-3,2},{120,4,3,-2},{180,3,-1}};

struct P{
	int p,q,f;
	int r;
	bool operator<(const P &b)const{
		return r<b.r;
	}
};

int main()
{
	int T;
	char star[20];
	char constellation[20];
	int degree;
	scanf("%d",&T);
	while(T--)
	{
		int i,j,k;
		for(i=0;i<10;i++)
		{
			scanf("%s %s %d",star,constellation,&degree);
			d[findStar(star,constellation)]=findConstellation(constellation)*30+degree;
		}
		memset(faculty,0,sizeof(faculty));
		for(i=0;i<10;i++)
		{
			for(j=i+1;j<10;j++)
			{
				for(k=0;k<5;k++)
				{
					if(abs(abs(d[i]-d[j])-aspects[k].degree)<=aspects[k].deviation
					|| abs(360-abs(d[i]-d[j])-aspects[k].degree)<=aspects[k].deviation)
					{
						energy[i]+=aspects[k].alterEnergy;
						energy[j]+=aspects[k].alterEnergy;
						capacity[i]+=aspects[k].alterCapacity;
						capacity[j]+=aspects[k].alterCapacity;
					}
				}
			}
		}
		for(i=0;i<10;i++)
		{
			for(j=i+1;j<10;j++)
			{
				for(k=0;k<5;k++)
				{
					if(abs(abs(d[i]-d[j])-aspects[k].degree)<=aspects[k].deviation
						|| abs(360-abs(d[i]-d[j])-aspects[k].degree)<=aspects[k].deviation)
					{
						faculty[i][j]=faculty[j][i]=max(0,capacity[i]+capacity[j]+2);
						if(k==0)faculty[i][j]=faculty[j][i]=2000000000;
					}
				}
			}
		}
		P p[100];
		int ans=0;
		for(int aa=0;aa<10000;aa++)
		{
			int tot=0,tt=0;
			for(i=0;i<10;i++)
			{
				for(j=i+1;j<10;j++)
				{
					if(faculty[i][j]>0 && energy[i]>0 && energy[j]>0)
					{
						p[tot].p=i;
						p[tot].q=j;
						p[tot].f=faculty[i][j];
						p[tot].r=rand();
						tot++;
					}
				}
			}
			sort(p,p+tot);
			int energy2[10];
			memcpy(energy2,energy,sizeof(energy));
			for(i=0;i<tot;i++)
			{
				int t=min(p[i].f,min(energy2[p[i].p],energy2[p[i].q]));
				if(t==0)continue;
				t=rand()%t+1;
				energy2[p[i].p]-=t;
				energy2[p[i].q]-=t;
				tt+=t*2;
			}
			if(ans<tt)ans=tt;
		}
		printf("%d\n",ans);
	}
	return 0;
}