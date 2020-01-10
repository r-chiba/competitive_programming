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

int N, K;

// pascal's triangle
// comb[n][k] = nCk (mod MOD)
const int COMB_MAX = 2000;
ll comb[COMB_MAX][COMB_MAX];
void combination()
{
    comb[0][0] = 1ll;
    FOR(i, 1, COMB_MAX){
        FOR(j, 1, COMB_MAX){
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }
}

ll pow(ll x, ll n)
{
    ll ret = 1ll;
    ll v = x;
    while(n > 0){
        if(n & 1){
            ret *= v;
            ret %= MOD;
        }
        v *= v;
        n >>= 1;
    }
    return ret;
}

void solve()
{
    combination();
    FOR(i, 1, K+1){
        ll ans = pow(K-i, i);
        if(N-K-i+1 >= 0 && i-2 >= 0){
            ans *= pow(N-K-i+1, i-2);
            ans %= MOD;
        }
        cout << ans << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
