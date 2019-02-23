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

int H, W;
int V = 10000;
P s, g;
int sum;
int m[101][101];
struct edge {
    int u, v, cost;
    edge(): u(0), v(0), cost(0) {};
    edge(int u_, int v_): u(u_), v(v_) {
        int ux = u / 100;
        int uy = u % 100;
        int vx = v / 100;
        int vy = v % 100;
        cost = m[ux][uy] * m[vx][vy];
    };

    friend ostream& operator<<(ostream &os, const edge &e){
        int ux = e.u / 100;
        int uy = e.u % 100;
        int vx = e.v / 100;
        int vy = e.v % 100;
        os << "(" << ux << ", " << uy << ") "
           << "(" << vx << ", " << vy << ") "
           << e.cost;
        return os;
    };
};
vector<edge> es;

void init()
{
}

bool comp(const edge &lhs, const edge &rhs)
{
    return lhs.cost > rhs.cost;
}
ll kruskal()
{
    sort(es.begin(), es.end(), comp);
    UnionFind uf(V);
    ll ret = 0;
    size_t E = es.size();
    REP(i, E){
        edge e = es[i];
        if(!uf.isSame(e.u, e.v)){
            uf.unite(e.u, e.v);
            ret += e.cost;
        }
    }
    return ret;
}

void solve()
{
    ll val = kruskal();
    cout << sum + val << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    cin >> s.fi >> s.se;
    cin >> g.fi >> g.se;
    s.fi--; s.se--;
    g.fi--; g.se--;
    REP(i, W){
        REP(j, H){
            cin >> m[i][j];
            sum += m[i][j];
            REP(k, 4){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || W <= nx || ny < 0 || H <= ny) continue;
                edge e = edge(i*100+j, nx*100+ny);
                es.pb(e);
            }
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
