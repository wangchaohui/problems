/* 
 * 线段基本操作
 *
 * Author: snowingsea
 * Created on 2010年4月20日, 下午2:38
 */

#include <stdlib.h>
#include <stdio.h>
#include <cmath>

#define MAXN 100

#define eps 1e-8
#define zero(x) ((fabs(x))<eps)

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

///////////////////////////////////////////////////////////////////////////////
struct point{   //点p : (x,y)
    double x;
    double y;
    point() {}
    point(double x,double y) : x(x) , y(y) {}
    point(const point& p) : x(p.x) , y(p.y) {}

	bool operator == (const point& p)const{
		return fabs(x-p.x)<eps && fabs(y-p.y)<eps;
	}
    point operator - (const point& p) const { return point(x-p.x,y-p.y); }
};
//点积
double dot(point a,point b){ return a.x*b.x+a.y*b.y; }
//叉积
double cross(point a,point b){ return a.x*b.y-a.y*b.x; }
//叉积P0P1xP0P2
double cross(point& p1,point& p2,point& p0){ return cross(p1-p0,p2-p0); }
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
struct line{    //线l : ax+by+c=0;
    double a;
    double b;
    double c;
    line() {}
    line(const line& l) : a(l.a) , b(l.b) , c(l.c) {}
    line(double a,double b,double c) : a(a) , b(b) , c(c) {}
};
///////////////////////////////////////////////////////////////////////////////

struct segment{ //线段AB
    point a;
    point b;
    segment() {}
    segment(double ax,double ay,double bx,double by) : a(ax,ay) , b(bx,by) {}
    segment(const point& a,const point& b): a(a) ,b(b) {}
    segment(const segment& s): a(s.a) ,b(s.b) {}
};
//*******************************************************************
//计算线段中垂线方程
line perp_bisector(segment& s){
    return line(2*(s.b.x-s.a.x),2*(s.b.y-s.a.y),s.a.x*s.a.x+s.a.y*s.a.y-s.b.x*s.b.x-s.b.y*s.b.y);
}

 
struct polygon{
	point p[MAXN];
	int n;
};
 
 
//*******************************************************************
//叉积P0P1xP0P2 
double multi(const point& p1,const point& p2,const point& p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
 
point intersect (const point& u1,const point& u2,const point& v1,const point& v2){
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
		/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;;
}
double area_polygon(polygon& poly){
	if(poly.n < 3)
		return 0;
	double area = 0;
	poly.p[poly.n] = poly.p[0];
	point origin;
	origin.x = origin.y = 0;
	for(int i = 0;i < poly.n;++i)
		area += multi(poly.p[i+1],poly.p[i],origin);
	area /= 2;
	return fabs(area);
}
 
// 顺时针
polygon poly_cut(point& p1,point& p2,const polygon& poly){
	int i,n;
	double t1,t2;
	polygon ret;
	point p;
	ret.n = 0;
	for (i = 0;i < poly.n;++i)
	{
		t1 = multi(p2,poly.p[i],p1);
		t2 = multi(p2,poly.p[i+1],p1);
		if(t1 < eps && t2 < eps){
			ret.p[ret.n++] = poly.p[i];
			ret.p[ret.n++] = poly.p[i+1];
		}
		else if(t1 > eps && t2 > eps)
			continue;
		else{
			p = intersect(p1,p2,poly.p[i],poly.p[i+1]);
			if(t1 < eps){
				ret.p[ret.n++] = poly.p[i];
				ret.p[ret.n++] = p;
			}
			else{
				ret.p[ret.n++] = p;
				ret.p[ret.n++] = poly.p[i+1];
			}
		}
	}
	if(ret.n == 0)
		return ret;
	for(i=n=1;i < ret.n;i++)
		if(!(ret.p[i] == ret.p[i-1]))
			ret.p[n++] = ret.p[i];
	ret.n = n;
	if( ret.n!=1 && ret.p[ret.n-1] == ret.p[0]) ret.n--;
	ret.p[ret.n] = ret.p[0];	
	return ret;
}
void change(polygon& p){
	int n = p.n;
	point temp;
	int i;
	for (i = 0;i < (n+1)/2;i++)
	{
		temp = p.p[i];
		p.p[i] = p.p[n-i-1];
		p.p[n-i-1] = temp;
	}
}
polygon poly1,poly2;
point p[15];
int main(){
	freopen("in.txt","r",stdin);
	int i,j,m;
	double area;
	line l;
	segment s;
	point p1,p2,p_temp;
	scanf("%d%d",&poly1.n,&m);
	for(i = 0;i < poly1.n;++i)
		scanf("%lf%lf",&poly1.p[i].x,&poly1.p[i].y);
	change(poly1);
	poly1.p[poly1.n] = poly1.p[0];
	for(i = 0;i < m;++i)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	for(i = 0;i < m;++i){
		poly2 = poly1;
		for (j = 0;j < m;++j)
		{
			if(i == j)
				continue;
			s = segment(p[i],p[j]);
			l = perp_bisector(s);
			if(zero(l.b)){
				p1 = point(-l.c/l.a,200);
				p2 = point(-l.c/l.a,-200);
			}
			else{
				p1 = point(-200,-(l.c-200*l.a)/l.b);
				p2 = point(200,-(l.c+200*l.a)/l.b);
			}
			if(multi(p1,p2,p[i]) > 0){
				p_temp = p1;
				p1 = p2;
				p2 = p_temp;
			}
			poly2 = poly_cut(p1,p2,poly2);
		}
		area = area_polygon(poly2);
		printf("%.5lf\n",area);
	}
	return 0;
}