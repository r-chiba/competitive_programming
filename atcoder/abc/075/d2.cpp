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
constexpr ll LINF = 9000000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

// }}}

int N, K;
LP p[50];

#if 0
bool comp1(LP &lhs, LP &rhs){
    if(lhs.fi < rhs.fi) return true;
    else if(lhs.fi == rhs.fi){
        return lhs.se < rhs.se;
    }
    return false;
}

bool comp2(LP &lhs, LP &rhs){
    if(lhs.se < rhs.se) return true;
    else if(lhs.se == rhs.se){
        return lhs.fi < rhs.fi;
    }
    return false;
}

void solve()
{
    ll ans = LINF;
    sort(p, p+N, comp1);
    REP(i, max(1, N-K)){
        ll x1 = LINF, x2 = -LINF, y1 = LINF, y2 = -LINF;
        REP(j, K){
            x1 = min(x1, p[i+j].fi);
            x2 = max(x2, p[i+j].fi);
            y1 = min(y1, p[i+j].se);
            y2 = max(y2, p[i+j].se);
        }
        ans = min(ans, (x2-x1)*(y2-y1));
    }
    sort(p, p+N, comp2);
    REP(i, max(1, N-K)){
        ll x1 = LINF, x2 = -LINF, y1 = LINF, y2 = -LINF;
        REP(j, K){
            x1 = min(x1, p[i+j].fi);
            x2 = max(x2, p[i+j].fi);
            y1 = min(y1, p[i+j].se);
            y2 = max(y2, p[i+j].se);
        }
        ans = min(ans, (x2-x1)*(y2-y1));
    }
    cout << ans << endl;
}
#else
void solve()
{
    ll ans = -1;
    int comb = (1 << K) - 1;
    while(comb < (1 << N)){
        int c = comb;
        int i = 0;
        ll x1 = LINF, x2 = -LINF, y1 = LINF, y2 = -LINF;
        while(c > 0){
            if(c & 1){
                x1 = min(x1, p[i].fi);
                x2 = max(x2, p[i].fi);
                y1 = min(y1, p[i].se);
                y2 = max(y2, p[i].se);
            }
            c >>= 1;
            i++;
        }
        if(ans == -1) ans = (x2-x1)*(y2-y1);
        else ans = min(ans, (x2-x1)*(y2-y1));

        int x = comb & -comb, y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
    }
    cout << ans << endl;
}
#endif

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) cin >> p[i].fi >> p[i].se;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
