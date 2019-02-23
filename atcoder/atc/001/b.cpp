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

void init()
{
}

void solve()
{
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    REP(i, Q){
        int p, a, b;
        cin >> p >> a >> b;
        if(p == 0) uf.unite(a, b);
        if(p == 1) cout << (uf.isSame(a, b) ? "Yes" : "No") << endl;
    }
    return 0;
}

// vim:set foldmethod=marker:
