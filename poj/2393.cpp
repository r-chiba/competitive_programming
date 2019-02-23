#include <iostream>
using namespace std;

typedef long long int ll;
int n, s;
int c[10000], y[10000];
ll ans = 0;

void solve()
{
  int mincost = 10000;
  for(int i = 0; i < n; i++){
    mincost = min(mincost+s, c[i]);
    ans += mincost*y[i];
  }
}

int main()
{
  cin >> n >> s;
  for(int i = 0; i < n; i++){
    cin >> c[i] >> y[i];
  }
  solve();
  cout << ans << endl;
}
