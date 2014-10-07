#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef long long I;

struct bn {
	I key;
	int n;
	char o;
	bool operator < ( const bn &bj) const{
		return key<bj.key;
	}
};

const int maxn = 20000;

bn b[maxn*2+5];
int tot, u[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}, z[maxn+5][2];
I l;
char d[maxn+5][2], lx[maxn+5];

int ulargee( int first, int last, I val ){
	int it, step, cnt = last-first;
	while( cnt > 0 ){          // cnt > eps
		it = first; step=cnt>>1; it+=step;   // step=cnt/2;
		if( b[it].key < val )
		{ first=++it;  cnt -=(step+1);}   // first=it+eps;  cnt -=(step+eps);
		else cnt=step;
	}
	return first;
}

bn* tree_serch( I k) {
	int ans = ulargee( 1, tot+1, k );
	if(ans==tot+1 || b[ans].key!=k)return NULL;
	return &b[ans];
}

int dfs(int i) {
	int j, k, x, y, g;
	I t;
	int x0[2], y0[2];
	bn *xx;
	x0[0] = z[i][0];
	y0[0] = z[i][1];
	if (lx[i] == 'x') {
		x0[1] = x0[0] + 1;
		y0[1] = y0[0];
	} else {
		x0[1] = x0[0];
		y0[1] = y0[0] + 1;
	}
	for (j = 0; j <= 1; j++)
		for (k = 0; k < 4; k++) {
			x = x0[j] + u[k][0];
			y = y0[j] + u[k][1];
			if (x == x0[1 - j] && y == y0[1 - j])continue;
			t = x * l + y;
			xx = tree_serch( t);
			if (xx == NULL)continue;
			if (d[xx->n][0] == -1) {
				d[xx->n][xx->o] = d[i][j];
				d[xx->n][1 - xx->o] = 1 - d[i][j];
				g = dfs(xx->n);
				if (g == -1)return -1;
			} else {
				if (d[xx->n][xx->o] != d[i][j])return -1;
			}
		}
		return 0;
}

int main() {
	//freopen("g: \\in.txt","r",stdin);
	int n, m, i, x0, y0, x1, y1, g;
	I t;
	bn *x;
	char ch;
	l = 2000000000;
	while (scanf("%d", &n) == 1 && n) {
		//        memset(d, -1, sizeof (d));
		for( i=0; i<=n; ++i ) d[i][0]=d[i][1]=-1;
		tot = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d %d %c", &x0, &y0, &ch);
			z[i][0] = x0;
			z[i][1] = y0;
			lx[i] = ch;
			t = x0 * l + y0;
			x = &b[++tot];
			x->key = t;
			x->n = i;
			x->o = 0;
			if (ch == 'x') {
				x1 = x0 + 1;
				y1 = y0;
			} else {
				x1 = x0;
				y1 = y0 + 1;
			}
			t = x1 * l + y1;
			x = &b[++tot];
			x->key = t;
			x->n = i;
			x->o = 1;
		}
		sort( &b[1], &b[tot+1]);
		for (i = 1; i <= n; i++) {
			if (d[i][0] == -1) {
				d[i][0] = 0;
				d[i][1] = 1;
				g = dfs(i);
				if (g == -1)break;
			}
		}
		if (i == n + 1)puts("Yes");
		else puts("No");
	}
	return 0;
}
