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

struct key {
    int a, b;
    unsigned int c;
};

int N, M;
key k[1000];
ll dp[12][1<<12];

ll rec(int i, int *h, int m)
{
    if(i >= N) return m;
    ll b = 0;
    REP(j, N){
        if(h[j] > 0) b |= (1<<j);
    }
    if(dp[i][b] != 0) return dp[i][b];
    if(h[i] > 0) return rec(i+1, h, m);
    ll ans = LINF;
    REP(j, M){
        if(k[j].c & (1 << i)){
            REP(l, N){
                if(k[j].c & (1 << l)) h[l]++;
            }
            ans = min(ans, rec(i+1, h, m) + k[j].a);
            REP(l, N){
                if(k[j].c & (1 << l)) h[l]--;
            }
        }
    }
    return dp[i][b] = ans;
}


void solve()
{
    int ans = 0;
    int h[12] = {0};
    cout << rec(0, h, 0) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    int ac = 0;
    REP(i, M){
        cin >> k[i].a >> k[i].b;
        REP(j, k[i].b){
            int n;
            cin >> n;
            n--;
            k[i].c |= (1<<n);
            ac |= (1<<n);
        }
    }
    bool ok = true;
    REP(i, N){
        if((ac & (1<<i)) == 0){
            ok = false;
            break;
        }
    }
    if(ok) solve();
    else cout << -1 << endl;
    return 0;
}

// vim:set foldmethod=marker:
