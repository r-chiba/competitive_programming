#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;
int c, l;
priority_queue<P> cow;
priority_queue<P> lot;
int ans = 0;

void solve()
{
  while(!lot.empty()){
    P lo = lot.top(); lot.pop();
    //cout << "{" << lo.first << "," << lo.second << "}" << endl;
    while(!cow.empty()){
      P co = cow.top(); cow.pop();
      //cout << "[" << co.first << "," << co.second << "]" << endl;
      if(lo.first >= co.first){
        ans++;
        if(lo.second > 1){
          lot.push(P(lo.first, lo.second-1));
        }
      }
    }
  }
}

int main()
{
  cin >> c >> l;
  for(int i = 0; i < c; i++){
    int mi, ma;
    cin >> mi >> ma;
    cow.push(P(ma, mi));
  }
  for(int i = 0; i < l; i++){
    int s, cov;
    cin >> s >> cov;
    lot.push(P(s, cov));
  }
  solve();
  cout << ans << endl;;
}
