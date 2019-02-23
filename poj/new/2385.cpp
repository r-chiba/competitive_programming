#include <cstdio>
#include <algorithm>
using namespace std;

int t, w;
int drop[1000];
int ans[2][1000][31];

void solve(){
  for(int i = t-1; i >= 0; i--){
    for(int j = 0; j <= w; j++){
      ans[0][i][j] = drop[i]^1;
      ans[0][i][j] += (i == t-1) ? 0 :
                      (j == 0) ? ans[0][i+1][j]:
                        max(ans[0][i+1][j], ans[1][i+1][j-1]);
      ans[1][i][j] = drop[i]&1;
      ans[1][i][j] += (i == t-1) ? 0 :
                        (j == 0) ? ans[1][i+1][j]:
                          max(ans[1][i+1][j], ans[0][i+1][j-1]);
    }
  }
}

int main()
{
  scanf("%d %d", &t, &w);
  for(int i = 0; i < t; i++){
    scanf("%d", &drop[i]);
    drop[i]--;
  }
  solve();
  printf("%d\n", max(ans[0][0][w], ans[1][0][w]));
  //for(int i = 0; i < t; i++){
  //  printf("[%d %d]\n", ans[0][i][w], ans[1][i][w]);
  //}
  return 0;
}
