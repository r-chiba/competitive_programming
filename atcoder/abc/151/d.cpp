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

#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (auto e: v) os << e << ",";
    os << "]";
    return os;
}

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

// print floating-point number
// cout << fixed << setprecision(12) <<

// }}}

int H, W;
char s[20][20];
bool visited[20][20];

int bfs(P start, P destination)
{
    REP (i, H) REP (j, W) visited[i][j] = false;
    queue<pair<P, int> > q;
    q.emplace(start, 0);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (visited[p.fi.fi][p.fi.se]) continue;
        visited[p.fi.fi][p.fi.se] = true;
        if (s[p.fi.fi][p.fi.se] == '#') continue;
        if (p.fi == destination) return p.se;
        REP (i, 4) {
            int ni = p.fi.fi + dx[i];
            int nj = p.fi.se + dy[i];
            if (ni < 0 || H <= ni || nj < 0 || W <= nj) continue;
            if (s[ni][nj] == '#' || visited[ni][nj]) continue;
            P np = mp(ni, nj);
            q.emplace(np, p.se+1);
        }
    }
    return -1;
}

void solve()
{
    int ans = 0;
    REP (si, H) {
        REP (sj, W) {
            if (s[si][sj] == '#') continue;
            REP (ti, H) {
                REP (tj, W) {
                    if (s[ti][tj] == '#') continue;
                    if (si == ti && sj == tj)
                        ans = max(ans, 0);
                    else
                        ans = max(ans, bfs(mp(si, sj), mp(ti, tj)));
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP (i, H) REP (j, W) cin >> s[i][j];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
