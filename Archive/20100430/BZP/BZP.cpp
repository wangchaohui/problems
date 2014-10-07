#include <iostream>
#include "algorithm"
using namespace std;

const int maxn = 100+5;
const double eps = 1e-9;
struct Point{
	int x, y;
	void read(){
		scanf("%d%d", &x, &y);
	}
};
int N, M;
double spd[maxn];
Point troop[maxn], base[maxn];
double dis[maxn][maxn];

void read(){
	int i, j;
	scanf("%d%d", &N, &M);
	for( i=0; i<N; ++i ){
		troop[i].read();
		scanf("%lf", &spd[i]);
	}
	for( i=0; i<M; ++i )
		base[i].read();
}

inline double pf( const double &x){return x*x;}
double getd( const Point &a, const Point &b){
	return pf(double(a.x-b.x))+pf(double(a.y-b.y));
}

void init(){
	int i, j;
	for( i=0; i<N; ++i){
		for( j=0; j<M; ++j ){
			dis[i][j]=getd(troop[i], base[j]);
		}
	}
}

// �ʺϳ���ͼ������洢��dfs�� ÿ�δ�Xһ�ڵ���չ���������ж��Ƿ��������·��
int nx, ny, cx[maxn], cy[maxn], mk[maxn]; // ���nx�����㣬�ұ�ny�����㡣 ���ڽӾ���ʱ����0��ʼ���õ�����ʱ��0��nx+ny-1. Ϊ�˽�Լʱ�䣬nx<ny�� cx[i] ��ʾ��xiƥ���y�����š�
bool g[maxn][maxn]; // g[i][j]=true��ʾ�����(i,j). ��ʱg[j][i] ��û������ġ�
int path( int u ) {
	int v;
	for( v=0; v<ny; ++v ) {
		if( g[u][v] && !mk[v] ) {
			mk[v]=1;
			if( cy[v]==-1 || path( cy[v] ) ) {
				cx[u]=v; cy[v]=u; return 1;
			}
		}
	}
	return 0;
}

int MaxMatch() {
	int res = 0, i, j ;
	for( i=0; i<nx; ++i ) cx[i]=-1; for( i=0; i<ny; ++i ) cy[i]=-1;
	for( i=0; i<nx; ++i ) {
		if( cx[i]==-1 ) {
			for( j=0; j<ny; ++j ) mk[j]=0; res +=path( i );
		}
	}
	return res;    
}

inline int sign( double x, double y){
	if( x-y>eps ) return 1;
	if( y-x>eps ) return -1;
	return 0;
}

bool ok( int i, double x, double y){
	return sign( pf(spd[i])*pf(x), y )>=0;
}

int getM( double x){
	int i, j;
	for( i=0; i<N; ++i)
		for( j=0; j<M; ++j)
			g[i][j]=false;

	for( i=0; i<N; ++i){
		for( j=0; j<M; ++j){
			if( ok( i, x, dis[i][j]) )
				g[i][j]=true;
		}
	}
	nx=N; ny=M;
	return MaxMatch();
}

// [first, last) �������򣬻������ a[j] >= val��ֵ��Сj�����a[last-1]<val, ����last
double ulargee( double first, double last){
	double it, step, cnt = last-first;
	while( cnt > eps ){
		it = first; step=cnt/2; it+=step;
		if( getM(it)<M ) 
		{ first=it+eps;  cnt -=(step+eps);}
		else cnt=step;
	}
	return first;
}


void solve(){
	int i, j;
	init();

//	for( i=0; i<N; ++i)
//		for( j=0; j<M; ++j )
//			printf("%lf\n", dis[i][j]);
//
////printf("%d\n", getM(15) );
//printf("%d\n", getM(14) );


	double ans;
	ans = ulargee( 0, 20010 );
	printf("%.8lf\n", ans);
}

int main(){
	freopen("e:\\in.txt", "r", stdin);
	read();
	solve();
	return 0;
}
