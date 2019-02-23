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
vector<ll> a;
ll m[3000][3000][2];

void init()
{
}

ll rec(int l, int r, int turn)
{
    if(l > r) return 0;
    if(m[l][r][turn] != -1) return m[l][r][turn];
    ll ret = 0;
    if(turn == 0){
        ret = max(rec(l+1, r, 1) + a[l], rec(l, r-1, 1) + a[r]);
    }else{
        ret = min(rec(l+1, r, 0) - a[l], rec(l, r-1, 0) - a[r]);
    }
    return m[l][r][turn] = ret;
}

void solve()
{
    REP(i, N) REP(j, N) REP(k, 2) m[i][j][k] = -1;
    cout << rec(0, N-1, 0) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N){
        ll v;
        cin >> v;
        a.pb(v);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
