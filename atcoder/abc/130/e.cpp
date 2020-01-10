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
int s[2000], t[2000];
ll dp[2000][2000];

ll rec(int x, int y)
{
    if(x >= N || y >= M) return 0;
    if(dp[x][y] != 0) return dp[x][y];

    cout << x << " " << y << endl;
    ll ret = ((rec(x+1, y) + rec(x, y+1)) % MOD - rec(x+1, y+1)) % MOD;
    if(s[x] == t[y]){
        ret = ((2*rec(x+1, y+1) % MOD) + 1) % MOD;
        cout << "\t" << x << " " << y << " " << ret <<endl;
    }
    return dp[x][y] = ret;
}

void solve()
{
#if 0
    dp[N-1][M-1] = (s[N-1] == t[M-1] ? 1 : 0);
    REPR(i, N-1){
        if(i < N-1) dp[i][M-1] = (dp[i+1][M-1] + (s[i] == t[M-1] ? 1 : 0)) % MOD;
        REPR(j, M-1){
            if(s[i] == t[j]) dp[i][j] = (1*dp[i][j+1] + 1) % MOD;
            else dp[i][j] = dp[i][j+1];
        }
    }
    cout << (dp[0][0] + 2) % MOD << endl;
#endif
    //cout << (rec(0, 0) + 1) % MOD << endl;
    cout << (rec(0, 0) + 1) % MOD << endl;
    REP(i, N){
        REP(j, M) cout << dp[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N) cin >> s[i];
    REP(i, M) cin >> t[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
