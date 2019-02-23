#include <iostream>
using namespace std;

typedef long long int ll;
int n;
ll memo[1000000];

bool power_of_two(int n)
{
  int i = 1;
  while(i < n) i *= 2;
  return i == n;
}

void solve()
{
  for(int i = 2; i <= n; i++){
    memo[i] = memo[i-1];
    //if(power_of_two(i)) memo[i]++;
    if(i%2 == 0) memo[i] += memo[i/2];
    cout << memo[i] << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; i++){
    memo[i] = i == 1 ? 1 : 0;
  }
  solve();
  cout << memo[n-1]%1000000000 << endl;
}
