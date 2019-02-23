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

string K;
int D;
ll dp[100001][2][100];

void init()
{
}

void solve()
{
    int nDigits = K.size();
    dp[0][0][0] = 1;
    REP(i, nDigits){
        int d = K[i] - '0';
        REP(j, 2){
            REP(k, D){
                int x = (j == 1 ? 10 : d+1);
                FOR(l, (i == 0 ? 0 : 0), x){
                    dp[i+1][(j == 1 || l < d ? 1 : 0)][(k+l)%D] += dp[i][j][k];
                    dp[i+1][(j == 1 || l < d ? 1 : 0)][(k+l)%D] %= MOD;
                }
            }
        }
    }
    ll ans = (dp[nDigits][0][0] + dp[nDigits][1][0]) % MOD;
    ans--;
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> K >> D;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
