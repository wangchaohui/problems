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
typedef unsigned long long ll;

ll f[100];
int d[100];
int N;

ll get()
{
    ll r = 0;
    for0r(i, N)r = r * 2 + d[i];
    return r;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll M;
        scanf("%I64u %d", &M, &N);
        for0(i, N)
        {
            d[i] = M % 2;
            M /= 2;
        }
        f[0] = get();
        for1(i, N - 1)
        {
            int t = d[N - 1];
            for (int j = N - 1; j > 0; j--)d[j] = d[j - 1];
            d[0] = t;
            f[i] = get();
        }
        sort(f, f + N);
        for0(i, N)putchar((f[i] % 2) + '0');
        putchar('\n');
    }
    return 0;
}

