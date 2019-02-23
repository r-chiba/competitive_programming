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

int H, W, K;

ll dp[8][8][101][101];

void init()
{
}

void solve()
{
    REP(i, K){
        dp[i][i][0][0] = 1;
        FOR(j, 1, H+1){
            if(i-1 > 0) dp[i][i-1][j][j] = dp[i-1][i][j][j] = 1;
            if(i+1 < W) dp[i][i+1][j][j] = dp[i+1][i][j][j] = 1;
        }
    }
    REP(i, K){
        REP(j, K){
            FOR(k, 1, W+1){
                REP(l, W+1){
                    FOR(m, k, W+1){
                        if(i-1 > 0){
                            dp[i][j][k][l] += dp[i-1][j][m][l];
                            dp[i][j][k][l] %= MOD;
                        }
                        if(i+1 < W){
                            dp[i][j][k][l] += dp[i+1][j][m][l];
                            dp[i][j][k][l] %= MOD;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    REP(i, W+1){
        REP(j, W+1){
            ans += dp[0][K-1][i][j];
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> K;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
