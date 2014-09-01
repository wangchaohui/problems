#include <cstdio>
#include <algorithm>

using namespace std;

int a[1010];
int b[1010];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  sort(a, a + n);
  sort(b, b + n);
  int ans = 0;
  for (int i = 0; i < n; i++) ans += a[i] * b[n - 1 - i];
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int TC = 0; TC < T; TC++) {
    printf("case #%d:\n", TC);
    solve();
  }
  return 0;
}

