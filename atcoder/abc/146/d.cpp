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
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
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

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

// }}}

struct Edge {
    int to_, rev_, col_;
    Edge(int to, int rev): to_(to), rev_(rev), col_(-1) {};
};

int N;
vector<Edge *> g[100010];
vector<Edge *> e;
vector<int> ans;

void clearEdge()
{
    REP (i, N) {
        REP (j, g[i].size()) {
            g[i][j]->col_ = -1;
        }
    }
}

bool colorable(int c)
{
    REP (i, N) {
        bool ok = true;
        unordered_set<int> used;
        REP (j, g[i].size()) {
            if (g[i][j]->col_ != -1)
                used.insert(g[i][j]->col_);
            else
                ok = false;
        }
        if (ok) continue;
        int unused = 0;
        REP (j, g[i].size()) {
            if (g[i][j]->col_ == -1) {
                while (used.find(unused) != used.end() && unused < c)
                    unused++;
                if (unused >= c) return false;
                g[i][j]->col_ = unused;
                g[g[i][j]->to_][g[i][j]->rev_]->col_ = unused;
                used.insert(unused);
            }
        }
    }
    return true;
}

void solve()
{
    int l = 0, u = N-1;
    while (u - l > 1) {
        clearEdge();
        int mid = (l + u) / 2;
        if (colorable(mid)) {
            u = mid;
            ans.clear();
            REP (i, N-1) {
                ans.pb(e[i]->col_);
            }
        } else {
            l = mid;
        }
    }
    if (u == N-1) {
        clearEdge();
        colorable(u);
        ans.clear();
        REP (i, N-1) {
            ans.pb(e[i]->col_);
        }
    }
    cout << u << endl;
    REP (i, N-1) {
        cout << ans[i]+1 << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP (i, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        auto p1 = new Edge(b, g[b].size()), p2 = new Edge(a, g[a].size());
        g[a].pb(p1);
        g[b].pb(p2);
        e.pb(p1);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
