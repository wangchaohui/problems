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

int main()
{
    int N;
    scanf("%d", &N);
    int index = 0;
    double mm = 100000001;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        char op;
        scanf("%d %c %d", &a, &op, &b);
        double t;
        switch (op)
        {
        case '+':
            t = a + b;
            break;
        case '-':
            t = a - b;
            break;
        case '*':
            t = a * b;
            break;
        case '/':
            t = (double)a / b;
            break;
        }
        double diff = fabs(t - 9);
        if (diff < mm)
        {
            mm = diff;
            index = i;
        }
    }
    printf("%d\n", index);
    return 0;
}
