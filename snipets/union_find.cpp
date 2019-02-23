// {{{
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#if __cplusplus >= 201103
#include <numeric>
#endif
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

#if __cplusplus >= 201103
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

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
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}

// vim:set foldmethod=marker:
