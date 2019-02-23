#include <cstdio>
using namespace std;

int t, n, m;
int parent[100000*2], rank_[100000*2];

void init()
{
  for(int i = 0; i < 100000*2; i++){
    parent[i] = -1;
    rank_[i] = 1;
  }
}

int find(int c)
{
  if(parent[c] == -1) return c;
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

int main()
{
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d %d", &n, &m);
    init();
    char q[8];
    int c1, c2;
    while(scanf("%s %d %d", q, &c1, &c2) != EOF){
      c1--; c2--;
      if(*q == 'D'){
        unite(c1, c2+n);
        unite(c2, c1+n);
      }else{
        if(same(c1, c2)) printf("In the same gang.\n");
        else if(same(c1, c2+n)) printf("In different gangs.\n");
        else printf("Not sure yet.\n");
      }
    }
  }
}
