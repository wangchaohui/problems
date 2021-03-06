﻿#define _CRT_SECURE_NO_WARNINGS
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

int d[100];
int n;

int count()
{
    int c = 0;
    for (int i = 1; i < n; i++)for0(j, i)
    {
        if (d[i] < d[j])c++;
    }
    return c;
}

void solve()
{
    int oc = count();
    for0(i, n)for (int j = i + 1; j < n; j++)
    {
        swap(d[i], d[j]);
        int t = count();
        checkmin(oc, t);
        swap(d[i], d[j]);
    }
    printf("%d\n", oc);
}

int main()
{
    freopen("in.txt", "r", stdin);
    while (true)
    {
        if (scanf("%d", &d[n++]) != 1)break;
        int ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            solve();
            n = 0;
        }
        if (ch == EOF)break;
    }
    return 0;
}
