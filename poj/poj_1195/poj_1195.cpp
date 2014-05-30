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

class BinaryIndexedTree2 {
public:
    BinaryIndexedTree2(int n) : n_(n) { Check(n < kMax); memset(c_, 0, sizeof(c_)); }
    void Update(int x, int y, int val);
    int GetSum(int x, int y);

private:
    static const int kMax = 2000;
    int LowBit(int n) { return n & -n; }
    void Check(bool b) { while (!b)puts("error"); }
    int n_;
    int c_[kMax][kMax];
};

void BinaryIndexedTree2::Update(int x, int y, int val)
{
    Check(x > 0); Check(y > 0);
    for (int i = x; i <= n_; i += LowBit(i))
        for (int j = y; j <= n_; j += LowBit(j))
            c_[i][j] += val;
}

int BinaryIndexedTree2::GetSum(int x, int y)
{
    Check(x <= n_); Check(y <= n_);
    int sum = 0;
    for (int i = x; i > 0; i -= LowBit(i))
        for (int j = y; j > 0; j -= LowBit(j))
            sum += c_[i][j];
    return sum;
}

int main()
{
    int n;
    scanf("%*d %d", &n);
    static BinaryIndexedTree2 *bit = new BinaryIndexedTree2(n);
    int t;
    while (scanf("%d", &t) == 1 && t != 3)
    {
        if (t == 1)
        {
            int x, y, a;
            scanf("%d %d %d", &x, &y, &a);
            bit->Update(x + 1, y + 1, a);
        }
        else
        {
            int l, b, r, t;
            scanf("%d %d %d %d", &l, &b, &r, &t);
            r++; t++;
            int sum = bit->GetSum(r, t);
            sum -= bit->GetSum(l, t);
            sum -= bit->GetSum(r, b);
            sum += bit->GetSum(l, b);
            printf("%d\n", sum);
        }
    }
    return 0;
}