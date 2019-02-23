#include <utility>
#include <cstdio>
using namespace std;

typedef pair<int, int> P;
int n, d;
P com[1001];
int repaired[1001], parent[1001], rank_[1001];

void init()
{
  for(int i = 0; i < n; i++){
    repaired[i] = false;
    parent[i] = i;
    rank_[i] = 1;
  }
}

int find(int c)
{
  if(parent[c] == c) return c;
  else{
    return parent[c] = find(parent[c]);
  }
}

void unite(int c1, int c2)
{
  c1 = find(c1);
  c2 = find(c2);
  if(c1 != c2){
    if(rank_[c1] > rank_[c2]) parent[c2] = c1;
    else{
      parent[c1] = c2;
      if(rank_[c1] == rank_[c2]) rank_[c2]++;
    }
  }
}

bool same(int c1, int c2)
{
  return find(c1) == find(c2);
}

bool communicate(int c1, int c2)
{
  int dx = com[c1].first - com[c2].first;
  int dy = com[c1].second - com[c2].second;
  return dx*dx+dy*dy <= d*d;
}

int main()
{
  scanf("%d %d", &n, &d);
  init();
  for(int i = 0; i < n; i++){
    scanf("%d %d", &(com[i].first), &(com[i].second));
  }
  char q[8];
  int c1, c2;
  while(scanf("%s %d", q, &c1) != EOF){
    c1--;
    if(*q == 'S'){
      scanf("%d", &c2);
      c2--;
      printf("%s\n", same(c1, c2) ? "SUCCESS" : "FAIL");
    }else{
      repaired[c1] = true;
      for(int i = 0; i < n; i++){
        if(repaired[i] == true && communicate(c1, i) == true){
          unite(c1, i);
        }
      }
    }
  }
}
