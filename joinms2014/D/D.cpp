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

int f[300][300];
string s[20020];
int c[20020];
int tot;

void Init()
{
    for0(i, 6)f[i][0] = f[0][i] = i;
}

int Dist(int x, int y)
{
    return abs(x - y);
}

int EditDistance(const string &a, const string &b)
{
    int n_a = a.size();
    int n_b = b.size();
    if (Dist(n_a, n_b) > 5)return 6;
    for1(i, n_a)for (int j = max(1, i - 5); j <= min(n_b, i + 5); j++)
    {
        f[i][j] = f[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
        if (Dist(i - 1, j) <= 5)checkmin(f[i][j], f[i - 1][j] + 1);
        if (Dist(i, j - 1) <= 5)checkmin(f[i][j], f[i][j - 1] + 1);
    }
    return f[n_a][n_b];
}

char st[300];

int main()
{
    freopen("in.txt", "r", stdin);
    Init();
    while (gets(st))
    {
        string ss(st);
        int i;
        for (i = 0; i < tot; i++)
        {
            if (EditDistance(ss, s[i]) <= 5)
            {
                c[i]++;
                break;
            }
        }
        if (i == tot)
        {
            s[i] = ss;
            c[i] = 1;
            tot++;
        }
    }
    int ans = 0;
    for0(i, tot)checkmax(ans, c[i]);
    printf("%d\n", ans);
    return 0;
}
