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

int f[34][34];

string dfs(int n, int m, int k)
{
    if (n == 0 && m == 0)return "";
    else if (n == 0)return string(m, '1');
    else if (m == 0) return string(n, '0');
    if (k <= f[n - 1][m])return '0' + dfs(n - 1, m, k);
    return '1' + dfs(n, m - 1, k - f[n - 1][m]);
}

void solve()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    if (K > f[N][M])
    {
        puts("Impossible");
        return;
    }
    printf("%s\n", dfs(N, M, K).c_str());
}

const int kMax = 1000000000;

int main()
{
    for0(i, 34)f[i][0] = f[0][i] = 1;
    for1(i, 33)for1(j, 33)
    {
        f[i][j] = f[i - 1][j] + f[i][j - 1];
        if (f[i][j] > kMax)f[i][j] = kMax;
    }
    freopen("in.txt", "r", stdin);
    int T, TC = 0;
    scanf("%d", &T);
    while (++TC <= T)
    {
        solve();
    }
    return 0;
}
