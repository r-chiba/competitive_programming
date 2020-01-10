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
const char atgc[] = "atgc";
ll dp[101][4][4][4];

void solve()
{
    ll ans = 0;
    REP(i, 4){
        REP(j, 4){
            REP(k, 4){
                if(atgc[i] == 'a' && atgc[j] == 'g' && atgc[k] == 'c') continue;
                if(atgc[i] == 'a' && atgc[j] == 'c' && atgc[k] == 'g') continue;
                if(atgc[i] == 'g' && atgc[j] == 'a' && atgc[k] == 'c') continue;
                dp[3][i][j][k] = 1;
            }
        }
    }
    FOR(i, 4, N+1){
        REP(j, 4){
            REP(k, 4){
                REP(l, 4){
                    REP(m, 4){
                        if(atgc[m] == 'a' && atgc[k] == 'g' && atgc[l] == 'c') continue;
                        if(atgc[j] == 'a' && atgc[k] == 'g' && atgc[l] == 'c') continue;
                        if(atgc[j] == 'a' && atgc[k] == 'c' && atgc[l] == 'g') continue;
                        if(atgc[j] == 'g' && atgc[k] == 'a' && atgc[l] == 'c') continue;
                        if(atgc[m] == 'a' && atgc[j] == 'g' && atgc[l] == 'c') continue;
                        dp[i][j][k][l] += dp[i-1][m][j][k];
                        dp[i][j][k][l] %= MOD;
                    }
                }
            }
        }
    }
    REP(i, 4){
        REP(j, 4){
            REP(k, 4){
                ans += dp[N][i][j][k];
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
