#include <stdio.h>
#include <math.h>

int main()
{
	double ax,ay,bx,by,cx,cy,dx,dy;
	double r1,r2,w1,w2,a1x,a1y,a2x,a2y,c1x,c1y,c2x,c2y;
	double p,q,r,a1,a2,dis,d1,d2,hc,lc,ha,la;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf %lf %lf %lf",&ax,&ay,&bx,&by);
		scanf("%lf %lf %lf %lf",&cx,&cy,&dx,&dy);
		scanf("%lf %lf %lf",&p,&q,&r);
		ha=1;la=0;
		r1=la+(ha-la)/3;r2=r1+(ha-la)/3;
		while(r1+1e-8<r2)
		{
			r1=la+(ha-la)/3;r2=r1+(ha-la)/3;
			a1x=(ax+(bx-ax)*r1);
			a1y=(ay+(by-ay)*r1);
			dis=(a1x-ax)*(a1x-ax)+(a1y-ay)*(a1y-ay);
			a2x=(ax+(bx-ax)*r2);
			a2y=(ay+(by-ay)*r2);
			hc=1;lc=0;
			w1=lc+(hc-lc)/3;w2=w1+(hc-lc)/3;
			while(w1+1e-6<w2)
			{
				w1=lc+(hc-lc)/3;w2=w1+(hc-lc)/3;
				c1x=(cx+(dx-cx)*w1);
				c1y=(cy+(dy-cy)*w1);
				c2x=(cx+(dx-cx)*w2);
				c2y=(cy+(dy-cy)*w2);
				d1=sqrt((c1x-dx)*(c1x-dx)+(c1y-dy)*(c1y-dy))/q+sqrt((c1x-a1x)*(c1x-a1x)+(c1y-a1y)*(c1y-a1y))/r;
				d2=sqrt((c2x-dx)*(c2x-dx)+(c2y-dy)*(c2y-dy))/q+sqrt((c2x-a1x)*(c2x-a1x)+(c2y-a1y)*(c2y-a1y))/r;
				if(d1<d2)
					hc=w2;
				else
					lc=w1;
			}
			a1=d1+sqrt((a1x-ax)*(a1x-ax)+(a1y-ay)*(a1y-ay))/p;
			hc=1;lc=0;
			w1=lc+(hc-lc)/3;w2=w1+(hc-lc)/3;
			while(w1+1e-8<w2)
			{
				w1=lc+(hc-lc)/3;w2=w1+(hc-lc)/3;
				c1x=(cx+(dx-cx)*w1);
				c1y=(cy+(dy-cy)*w1);
				c2x=(cx+(dx-cx)*w2);
				c2y=(cy+(dy-cy)*w2);
				d1=sqrt((c1x-dx)*(c1x-dx)+(c1y-dy)*(c1y-dy))/q+sqrt((c1x-a2x)*(c1x-a2x)+(c1y-a2y)*(c1y-a2y))/r;
				d2=sqrt((c2x-dx)*(c2x-dx)+(c2y-dy)*(c2y-dy))/q+sqrt((c2x-a2x)*(c2x-a2x)+(c2y-a2y)*(c2y-a2y))/r;
				if(d1<d2)
					hc=w2;
				else
					lc=w1;
			}
			a2=d1+sqrt((a2x-ax)*(a2x-ax)+(a2y-ay)*(a2y-ay))/p;
			if(a1<a2)
				ha=r2;
			else
				la=r1;
		}
		printf("%.2lf\n",a1);
	}
	return 0;
}