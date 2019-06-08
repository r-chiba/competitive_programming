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

int N, K;
vector<ll> x, y;
map<ll, ll> xx, yy;

void init()
{
}

void solve()
{
    sort(ALL(x));
    sort(ALL(y));
    ll ans = -1;
    REP(i, N-K+1){
        ll dx = abs(x[i+K-1] - x[i]);
        ll maxy = -LINF, miny = LINF;
        REP(j, K){
            if(yy[x[i+j]] > maxy) maxy = yy[x[i+j]];
            if(yy[x[i+j]] < miny) miny = yy[x[i+j]];
        }
        if(ans == -1 || ans < dx*(maxy-miny)) ans = dx*(maxy-miny);
        ll dy = abs(y[i+K-1] - y[i]);
        ll maxx = -LINF, minx = LINF;
        REP(j, K){
            if(xx[y[i+j]] > maxx) maxx = xx[y[i+j]];
            if(xx[y[i+j]] < minx) minx = xx[y[i+j]];
        }
        if(ans == -1 || ans < dy*(maxx-minx)) ans = dy*(maxx-minx);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    x.resize(N);
    y.resize(N);
    REP(i, N){
        ll xxx, yyy;
        cin >> xxx >> yyy;
        x[i] = xxx;
        y[i] = yyy;
        xx[yyy] = xxx;
        yy[xxx] = yyy;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
