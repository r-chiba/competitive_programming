#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000;
int n, m;
int cow[300], deg[300][300];

int main()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      deg[i][j] = i==j ? 0 : INF;
    }
  }
  for(int i = 0; i < m; i++){
    int ncow, idx[300];
    scanf("%d", &ncow);
    for(int j = 0; j < ncow; j++){
      scanf("%d", &(idx[j]));
      idx[j]--;
    }
    for(int j = 0; j < ncow; j++){
      for(int k = j+1; k < ncow; k++){
        deg[idx[j]][idx[k]] = deg[idx[k]][idx[j]] = 1;
      }
    }
  }
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        deg[i][j] = min(deg[i][j], deg[i][k]+deg[k][j]);
      }
    }
  }
  int ans = -1;
  for(int i = 0; i < n; i++){
    int tmp = 0;
    for(int j = 0; j < n; j++){
      tmp += deg[i][j];
    }
    if(ans == -1 || ans > tmp) ans = tmp;
  }
  printf("%d\n", 100*ans/(n-1));
}
