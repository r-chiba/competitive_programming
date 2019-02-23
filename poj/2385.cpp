#include <iostream>
using namespace std;

int t, w;
int arr[1000];
int memo[2][1000][30];

void solve()
{
  for(int i = t-1; i >= 0; i--){
    for(int j = 1; j <= w; j++){
      memo[0][i][j] = max(memo[0][i+1][j], memo[1][i+1][j-1]);
      memo[1][i][j] = max(memo[1][i+1][j], memo[0][i+1][j-1]);
      if(arr[i] == 1) memo[0][i][j]++;
      else memo[1][i][j]++;
    }
  }
}

int main()
{
  int n1 = 0, n2 = 0;
  cin >> t >> w;
  for(int i = 0; i < t; i++){
    cin >> arr[i];
  }
  if(arr[t-1] == 1){
    memo[0][t-1][0] = 1;
    memo[1][t-1][0] = 0;
  }else{
    memo[0][t-1][0] = 0;
    memo[1][t-1][0] = 1;
  }
  for(int i = t-1; i >= 0; i--){
    if(arr[i] == 1){
      memo[0][i][0] = memo[0][i+1][0] + 1;
      memo[1][i][0] = memo[0][i+1][0];
    }else{
      memo[0][i][0] = memo[0][i+1][0];
      memo[1][i][0] = memo[1][i+1][0] + 1;
    }
  }
  solve();
  cout << max(memo[0][0][w], memo[1][0][w]) << endl;
}
