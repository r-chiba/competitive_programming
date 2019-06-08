// {{{
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <complex>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(ll i = static_cast<ll>(a); i < static_cast<ll>(b); i++)
#define FORR(i, a, b) for(ll i = static_cast<ll>(a); i >= static_cast<ll>(b); i--)
#define REP(i, n) for(ll i = 0ll; i < static_cast<ll>(n); i++)
#define REPR(i, n) for(ll i = static_cast<ll>(n); i >= 0ll; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> IP;
typedef pair<ll, LP> LLP;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;
// }}}

int N;
vector<LP> v[100000];

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

void rec(int cur)
{
    for(auto &p: v[cur]){
        if(p.se % 2 == 0) unite(cur, p.fi);
        rec(p.fi);
    }
}

void solve()
{
    init();

    REP(i, N) rec(i);
    //REP(i, N) cout << (int)same(0, i) << " " << find(i) << endl;
    REP(i, N) cout << (int)same(0, i) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N){
        ll p, q, r;
        cin >> p >> q >> r;
        p--; q--;
        v[p].pb(mp(q, r));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
