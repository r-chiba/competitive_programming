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
#define FOR(i, a, b) for(size_t i = static_cast<size_t>(a); i < static_cast<size_t>(b); i++)
#define FORR(i, a, b) for(size_t i = static_cast<size_t>(a); i >= static_cast<size_t>(b); i--)
#define REP(i, n) for(size_t i = 0; i < static_cast<size_t>(n); i++)
#define REPR(i, n) for(size_t i = static_cast<size_t>(n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> IP;
typedef pair<ll, LP> LIP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;
// }}}

class UnionFind{
    vector<size_t> m_parents;
    vector<ll> m_ranks;

public:
    UnionFind(size_t n){
        m_parents.resize(n);
        m_ranks.resize(n);
        for(size_t i = 0; i < n; i++){
            m_parents[i] = i;
            m_ranks[i] = 0;
        }
    }

    size_t root(size_t x){
        if(m_parents[x] == x) return x;
        size_t r = root(m_parents[x]);
        m_parents[x] = r;
        return r;
    }

    bool isSame(size_t x, size_t y){
        return root(x) == root(y);
    }

    void unite(size_t x, size_t y){
        size_t rx = root(x);
        size_t ry = root(y);
        if(rx != ry){
            if(m_ranks[rx] < m_ranks[ry]) swap(rx, ry);
            if(m_ranks[rx] == m_ranks[ry]) m_ranks[rx]++;
            m_parents[ry] = rx;
        }
    }
};

int V, E;

struct edge {
    int u, v, cost;
    edge(): u(0), v(0), cost(0) {};
    edge(int u_, int v_, int c): u(u_), v(v_), cost(c) {};
};
edge es[100010*2];
bool comp(const edge &lhs, const edge &rhs)
{
    return lhs.cost < rhs.cost;
}
int kruskal()
{
    sort(es, es+E, comp);
    UnionFind uf(V);
    int ret = 0;
    REP(i, E){
        edge e = es[i];
        if(!uf.isSame(e.u, e.v)){
            uf.unite(e.u, e.v);
            ret += e.cost;
        }
    }
    return ret;
}

void init()
{
}

void solve()
{
    cout << kruskal() << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V >> E;
    REP(i, E){
        int u, v, w;
        cin >> u >> v >> w;
        es[i] = edge(u, v, w);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
