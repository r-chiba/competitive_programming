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
double p[3000];
double dp[3000][3000];

void init()
{
}

void solve()
{
    dp[1][0] = 1. - p[1];
    dp[1][1] = p[1];

    FOR(i, 2, N+1){
        FOR(j, 0, N+1){
            dp[i][j] = dp[i-1][j]*(1.-p[i]) + dp[i-1][j-1]*p[i];
        }
    }
    double ans = 0.;
    int n = N/2+1;
    FOR(i, n, N+1){
        ans += dp[N][i];
    }
    cout << fixed;
    cout << setprecision(10) << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    FOR(i, 1, N+1) cin >> p[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
