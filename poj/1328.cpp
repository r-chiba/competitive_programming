#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

typedef pair<double, double> P;
vector<P> v;
bool f[1000];
int n, d;

bool contain(const P &cp, const P &ip)
{
  double dx = cp.first-ip.first, dy = cp.second-ip.second;
  return sqrt(dx*dx+dy*dy) <= d;
}

P get_point(const P &ip)
{
  double x = ip.first, y = ip.second;
  double dx = sqrt(d*d-y*y);
  return P(x+dx, 0);
}

int solve()
{
  int ans = 0, nc = 0;
  for(int i = 0; i < n; i++) f[i] = false;
  while(true){
    if(nc == n) break;
    int idx = 0;
    for(int i = idx; i < n; i++){
      if(f[i] == false){
        idx = i;
        break;
      }
    }
    P cp = get_point(v[idx]);
    ans++;
    cout << cp.first << " " << cp.second << endl;
    for(int i = 0; i < n; i++){
      if(f[i] == false && contain(cp, v[i])){
        f[i] = true;
        nc++;
      }
    }
  }
  return ans;
}

int main()
{
  int c = 1;
  while(true){
    cin >> n >> d;
    if(n == 0 && d == 0) break;
    for(int i = 0; i < n; i++){
      int x, y;
      cin >> x >> y;
      if(y > d){
        cout << -1 << endl;
        return 0;
      }
      v.push_back(P(x, y));
    }
    sort(v.begin(), v.end());
    int ans = solve();
    cout << "Case " << c << ": " << ans << endl;
    c++;
  }
}
