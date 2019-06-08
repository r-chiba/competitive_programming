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

int N, M;
ll a[100000];
LP p[100000];
ll s[100000];

void solve()
{
    sort(a, a+N);
    sort(p, p+M, greater<P>());
    s[0] = a[0];
    FOR(i, 1, N) s[i] = s[i-1] + a[i];
    ll ret = s[N-1];
    ll cur = 0;
    REP(i, M){
        auto c = lower_bound(a+cur, a+N, p[i].fi);
        ll num = min(p[i].se, (ll)(c - (a+cur)));
        ret += max(p[i].fi * num - (s[cur+num-1] - (cur == 0 ? 0 : s[cur-1])), 0ll);
        cur = cur + num;
    }
    cout << ret << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N) cin >> a[i];
    REP(i, M){
        cin >> p[i].se >> p[i].fi;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
