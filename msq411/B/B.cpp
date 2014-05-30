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

class Mod{
public:
    Mod(ll x) { set(x); }
    void operator+= (ll x) { set((ll)mod_ + x % kMod); }
    void operator*= (ll x) { set((ll)mod_ * (x % kMod)); }
    int get() const { return mod_; }

private:
    void set(ll x) { mod_ = x % kMod; if (mod_ < 0)mod_ += kMod; }
    static const int kMod = 1000000007;
    int mod_;
};

void run()
{
    ll n;
    scanf("%lld", &n);
    ll n0 = n;
    ll n1 = n + 1;
    ll n3 = n - 3;
    if (n % 2 == 0)n0 /= 2;
    else n1 /= 2, n3 /= 2;
    Mod na(n0);
    na *= n1;
    Mod t(n0);
    t *= n3;
    t += 2;
    na *= na.get();
    na *= t.get();
    printf("%d\n", na.get());
}

int main()
{
    string s;
    string t(s.begin(), s.begin());
    int T, TC = 0;
    scanf("%d", &T);
    while (++TC <= T)
    {
        printf("Case %d: ", TC);
        run();
    }
    return 0;
}
