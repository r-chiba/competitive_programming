// {{{
#include <iostream>
#include <cmath>
#include <cstdio>
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
#include <numeric>
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

//#if __cplusplus >= 201103
typedef long long ll;
//#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
//#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
//#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

bool bipartite_coloring(int v, int c)
{
    color[v] = c;
    for(auto next: g[v]){
        if(color[next] == c) return false;
        if(color[next] == 0 && !dfs(next, -c)) return false;
    }
    return true;
}

int N, M;
vector<int> g[2010];
int color[2010];
map<P, int> m;

void init()
{
}

void solve()
{
    bool bipartite = bipartite_coloring(0, 1);
    if(bipartite){
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, M){
        int a, b;
        char c;
        cin >> a >> b >> c;
        g[a].pb(b);
        g[b].pb(a);
        m[mp(a, b)] = (c == 'r' ? 1 : -1);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
