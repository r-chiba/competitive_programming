#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long int ans[1<<20];

void solve(){
  for(int i = 1; i <= n; i++){
    ans[i] = (i == 1) ? 1 :
              (i % 2 == 0) ? ans[i-1] + ans[i/2] : ans[i-1];
    ans[i] %= 1000000000;
  }
}

int main()
{
  scanf("%d", &n);
  solve();
  printf("%lld\n", ans[n]);
  return 0;
}
