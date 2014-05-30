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

int d[310];
int n;

class KMP
{
    int t_[1005];
    int word_lenth_;
    const int* word_;

public:
    KMP(int word_lenth, const int *word);
    int match(const int *s) const;
};

KMP::KMP(int word_lenth, const int *word) : word_(word), word_lenth_(word_lenth)
{
    t_[0] = t_[1] = 0;
    int j = 0;
    for (int i = 2; i <= word_lenth_; i++)
    {
        while (j > 0 && word[j] != t_[i - 1]) j = t_[j];
        if (word[j] == word[i - 1]) j++;
        t_[i] = j;
    }
}

int KMP::match(const int *s) const
{
    int j = 0;
    int mm = 0;
    for (int i = 0; i < word_lenth_; i++)
    {
        while (j > 0 && word_[j] != s[i]) j = t_[j];
        if (word_[j] == s[i]) j++;
        if (j > (i + 1) / 2)
        {
            j = t_[j];
        }
        if (j > mm)mm = j;
    }
    return mm;
}

int main()
{
    scanf("%d", &n);
    for0(i, n)scanf("%d", &d[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        KMP kmp(n - i, d + i);
        int t = kmp.match(d + i);
        if (t > ans)ans = t;
    }
    printf("%d\n", ans);
    return 0;
}
