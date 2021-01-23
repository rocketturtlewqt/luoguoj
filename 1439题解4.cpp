#include <cstdio>
#include <algorithm>
#define MAX_N 1000001
#define INF 2147483647
using namespace std;
int N, s[MAX_N], t[MAX_N];
int dp[MAX_N], top = 0;
int q;
void solve () {
  fill(dp, dp + top, INF);
  for (int i = 0;i < top; i++) {
    *lower_bound(dp, dp + top, t[i]) = t[i];
  }
  printf("%d\n", lower_bound(dp, dp + top, INF) - dp);
}
int main() {
  scanf("%d", &N);
  for(int i = 1;i <= N; i++) {scanf("%d", &q); s[q] = i;}
  for(int i = 1;i <= N; i++) {scanf("%d", &q); if(s[q] > 0) t[top++] = s[q];}
  solve();
  return 0;
}
