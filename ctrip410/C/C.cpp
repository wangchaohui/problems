#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib> 
#include <cctype> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <fstream> 
#include <numeric> 
#include <iomanip> 
#include <bitset> 
#include <list> 
#include <stdexcept> 
#include <functional> 
#include <utility> 
#include <ctime> 
using namespace std;
template<class T> inline void checkmin(T &a, T b){ if (b<a) a = b; }//NOTES:checkmin( 
template<class T> inline void checkmax(T &a, T b){ if (b>a) a = b; }//NOTES:checkmax( 
#define SIZE(x) ((int)(x).size()) 
#define for0(i,n) for(int i=0;i<(n);i++) 
#define for1(i,n) for(int i=1;i<=(n);i++) 
#define for0r(i,n) for(int i=(n)-1;i>=0;i--) 
#define for1r(i,n) for(int i=(n);i>=1;i--) 
typedef long long ll;

#define PI 3.14159265358979323846

double distbtp(double lat1, double lng1, double lat2, double lng2, double r)
{
    double a = lat1 - lat2;
    double b = lng1 - lng2;
    double s = 2 * asin(sqrt(pow(sin(a / 2), 2) + cos(lat1)*cos(lat2)*pow(sin(b / 2), 2)));
    s = s*r;
    return s;
}

double lat[200];
double lng[200];
double l[200][200];

#define maxn 200
#define maxw 1e100

typedef double W;
typedef pair<W, int> PWI;

const double eps = 1e-6;

int C;
int m, f[maxn + 1], visited[maxn + 1];
double ans;
W cost[maxn + 1];

void Prim()
{
    int i, j, mn;
    priority_queue< PWI, vector<PWI>, greater<PWI> > Q;
    PWI p;
    cost[0] = 0;
    Q.push(make_pair(0, 0));
    for (i = 1; i < C; i++)
    {
        cost[i] = maxw;
        Q.push(make_pair(maxw, i));
    }
    ans = 0;
    memset(f, 0, sizeof(f));
    memset(visited, 0, sizeof(visited));
    while (!Q.empty())
    {
        p = Q.top(); Q.pop();
        mn = p.second;
        if (visited[mn])continue;
        visited[mn] = 1;
        ans += cost[mn];
        for (j = 0; j < C; j++)
            if (!visited[j] && l[mn][j] < cost[j])
            {
                cost[j] = l[mn][j]; f[j] = mn;
                Q.push(make_pair(cost[j], j));
            }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        double D, L;
        scanf("%lf %lf %d", &D, &L, &C);
        D /= 2;
        for (int i = 0; i < C; i++)
        {
            scanf("%lf %lf", &lat[i], &lng[i]);
            lat[i] *= PI / 180;
            lng[i] *= PI / 180;
        }
        for0(i, C)for0(j, C)l[i][j] = distbtp(lat[i], lng[i], lat[j], lng[j], D);
        Prim();
        puts(ans < L + eps ? "Y" : "N");
    }
    return 0;
}

