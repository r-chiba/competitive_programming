#include <iostream>
using namespace std;

int n;
int tri[350][350];
int memo[350][350];

void solve()
{
  for(int i = n-2; i >= 0; i--){
    for(int j = 0; j < i+1; j++){
      memo[i][j] = tri[i][j] + max(memo[i+1][j], memo[i+1][j+1]);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i+1; j++){
      cin >> tri[i][j];
      memo[i][j] = i == n-1 ? tri[i][j] : -1;
    }
  }
  solve();
  cout << memo[0][0] << endl;
}
