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

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

// }}}

int N;
vector<ll> a;
vector<ll> b;

void solve()
{
    ll ans1 = 0, ans2 = 0;
    vector<ll> a1(a), a2(a), b1(b), b2(b);
    REP(i, N){
        ll x = min(a1[i], b1[i]);
        ans1 += x;
        if(b1[i] > x){
            b1[i] -= x;
            ll y = min(b1[i], a1[i+1]);
            a1[i+1] -= y;
            ans1 += y;
        }
    }
    REPR(i, N-1){
        ll x = min(a2[i+1], b2[i]);
        ans2 += x;
        if(b2[i] > x){
            b2[i] -= x;
            ll y = min(b2[i], a2[i]);
            a2[i] -= y;
            ans2 += y;
        }
    }
    cout << max(ans1, ans2) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    a.resize(N+1);
    b.resize(N);
    REP(i, N+1) cin >> a[i];
    REP(i, N) cin >> b[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
