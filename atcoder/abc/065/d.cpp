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
typedef pair<ll, LP> LLP;

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

ll V, E;
LLP vs[100010];
struct edge {
    ll u, v, cost;
    edge(): u(0), v(0), cost(0) {};
    edge(ll u_, ll v_): u(u_), v(v_) {
        cost = min(abs(vs[u].se.fi - vs[v].se.fi), abs(vs[u].se.se - vs[v].se.se));
        //cout << "[" << u << ", " << v << "] " << cost << endl;
    };
};
edge es[400040];
bool comp(const edge &lhs, const edge &rhs)
{
    return lhs.cost < rhs.cost;
}
bool xcomp(const LLP &lhs, const LLP &rhs)
{
    return lhs.se.fi < rhs.se.fi;
}

bool ycomp(const LLP &lhs, const LLP &rhs)
{
    return lhs.se.se < rhs.se.se;
}

ll kruskal()
{
    sort(es, es+E, comp);
    UnionFind uf(V);
    ll ret = 0;
    REP(i, E){
        edge e = es[i];
        //cout << "(" << e.cost << ")" << endl;
        if(!uf.isSame(e.u, e.v)){
            uf.unite(e.u, e.v);
            //cout << e.cost << endl;
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
    vector<LLP> xvs, yvs;
    REP(i, V){
        xvs.pb(vs[i]);
        yvs.pb(vs[i]);
    }
    sort(xvs.begin(), xvs.end(), xcomp);
    sort(yvs.begin(), yvs.end(), ycomp);
    E = 4*(V-1);
    REP(i, V-1){
        es[4*i] = edge(xvs[i].fi, xvs[i+1].fi);
        es[4*i+1] = edge(xvs[i+1].fi, xvs[i].fi);
        es[4*i+2] = edge(yvs[i].fi, yvs[i+1].fi);
        es[4*i+3] = edge(yvs[i+1].fi, yvs[i].fi);
    }
    cout << kruskal() << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V;
    REP(i, V){
        ll x, y;
        cin >> x >> y;
        vs[i] = LLP(i, LP(x, y));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
