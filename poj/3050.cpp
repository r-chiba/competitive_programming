#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int m[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
set<int> s;

void dfs(int x, int y, int n, int step)
{
  if(step == 5) s.insert(n);
  else{
    for(int i = 0; i < 4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(0 <= nx && nx < 5 && 0 <= ny && ny < 5){
        dfs(nx, ny, n*10+m[nx][ny], step+1);
      }
    }
  }
}

int solve()
{
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      dfs(i, j, m[i][j], 0);
    }
  }
  return s.size();
}

int main()
{
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> m[i][j];
    }
  }
  cout << solve() << endl;
}
