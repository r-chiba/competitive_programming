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
string s;
ll dp[3001][3001];

inline ll mod_positive(ll n)
{
    return (n + MOD) % MOD;
}

void init()
{
}

void solve()
{
    dp[1][1] = 1;
    FOR(i, 1, N+1){
        ll c[3001];
        c[0] = 0;
        FOR(j, 1, i+1) c[j] = mod_positive(c[j-1] + dp[i][j]);
        FOR(j, 1, i+2){
            if(s[i-1] == '<'){
                dp[i+1][j] = mod_positive(c[j-1] - c[0]);
            }else{
                dp[i+1][j] = mod_positive(c[i] - c[j-1]);
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, N+1) ans = (ans + dp[N][i]) % MOD;
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> s;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
