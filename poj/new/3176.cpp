#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int tri[350][350];
int ans[350][350];

void solve(){
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < n; j++){
      ans[i][j] = (i == n-1) ? tri[i][j] :
                    tri[i][j] + max(ans[i+1][j], ans[i+1][j+1]);
    }
  }
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      scanf("%d", &tri[i][j]);
    }
  }
  solve();
  printf("%d\n", ans[0][0]);
  return 0;
}
