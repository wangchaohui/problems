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

int d[20];
int a[30];
bool valid;

void GetResult()
{
    if (!valid)
    {
        puts("<invalid input string>");
        return;
    }
    bool flag = true;
    while (flag)
    {
        flag = false;
        for0(i, 10)if (d[i])
        {
            d[i]--;
            putchar('0' + i);
            flag = true;
        }
        for0(i, 26)if (a[i])
        {
            a[i]--;
            putchar('a' + i);
            flag = true;
        }
    }
    putchar('\n');
}

int main()
{
    freopen("in.txt", "r", stdin);
    int ch;
    bool flag = false;
    valid = true;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            GetResult();
            memset(d, 0, sizeof(d));
            memset(a, 0, sizeof(a));
            valid = true;
            flag = false;
        }
        else
        {
            if (isdigit(ch))d[ch - '0']++;
            else if (islower(ch))a[ch - 'a']++;
            else valid = false;
            flag = true;
        }
    }
    if (flag)GetResult();
    return 0;
}
