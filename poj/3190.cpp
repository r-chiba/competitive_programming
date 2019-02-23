#include <iostream>
using namespace std;

typedef pair<int, int> P;
int n;
vector<P> v;
int stall[50000];
int nstall = 1;

void solve()
{
  int m = 0;
  while(m < n){
    P &p = v[m];
    for(int i = 0; i < n; i++){
      if(p.second > v[i].second) p = v[i];
      else break;
    }
  }
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++){
    int s, e;
    cin >> s >> e;
    v.push_back(P(s, e));
  }
  v.sort(v.begin(), v.end());
  solve();
  cout << nstall << endl;
  for(int i = 0; i < n; i++){
    cout << stall[i] << endl;
  }
}
