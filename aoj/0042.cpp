#include <cstdio>
#include <algorithm>
using namespace std;

int ww, n;
int v[1000], w[1000];
// dp[i][j]は0~i-1までのアイテムを使って容量j以下での最大価値
int dp[1000][1001];

void solve()
{
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= ww; j++){
      dp[i][j] = (i == 0 || j == 0) ? 0 :
                  (w[i-1] > j) ? dp[i-1][j] :
                    max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
    }
  }
  while(ww--){
    if(ww-1 < 0 || dp[n][ww] > dp[n][ww-1]) break;
  }
  printf("%d\n%d\n", dp[n][ww], ww);
}

int main()
{
  int ca = 1;
  while(true){
    scanf("%d", &ww);
    if(ww == 0) break;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d,%d", &v[i], &w[i]);
    }
    printf("Case %d:\n", ca++);
    solve();
  }
  return 0;
}
