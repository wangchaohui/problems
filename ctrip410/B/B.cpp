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

char s[200];
int f[200][200];

bool match(char a, char b)
{
    return a == '(' && b == ')' || a == '[' && b == ']';
}

int main()
{
    int T;
    scanf("%d ", &T);
    while (T--)
    {
        gets(s);
        int n = strlen(s);
        for (int i = 0; i < n; i++)f[i][i] = 1;
        for (int k = 1; k < n; k++)
        {
            for (int i = 0; i < n - k; i++)
            {
                int j = i + k;
                f[i][j] = 200000000;
                for (int a = i; a < j; a++)
                {
                    checkmin(f[i][j], f[i][a] + f[a + 1][j]);
                }
                if (match(s[i], s[j]))checkmin(f[i][j], f[i + 1][j - 1]);
            }
        }
        printf("%d\n", f[0][n - 1]);
    }
    return 0;
}
