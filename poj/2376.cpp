#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;
//vector<P> v;
P ps[25000];
int n, t;

int solve()
{
  int ans = 0, cur = 0, e = -1;
  //sort(v.begin(), v.end());
  sort(ps, ps+n);
  while(true){
    //for(int i = 0; i < v.size(); i++){
    for(int i = 0; i < n; i++){
      //P &p = v[i];
      P &p = ps[i];
      if(p.first <= cur){
        e = max(e, p.second);
      }else{
        break;
      }
    }
    if(e == -1 || cur == t-1) break;
    else{
      ans++;
      cur = e;
      e = -1;
    }
  }
  if(cur == t-1) return ans;
  else return -1;
}

int main()
{
  scanf("%d %d", &n, &t);
  for(int i = 0; i < n; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    ps[i] = P(x-1, y-1);
    //v.push_back(P(x-1, y-1));
  }
  printf("%d\n", solve());
  return 0;
}
