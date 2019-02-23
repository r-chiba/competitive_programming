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

ll N, W;
ll w[101], v[101];
ll dp[101][100001];

void init()
{
}

void solve()
{
    FOR(i, 1, 100001) dp[1][i] = (i <= v[1] ? w[1] : LINF);
    FOR(i, 2, N+1){
        REP(j, 100001){
            dp[i][j] = dp[i-1][j];
            if(j-v[i] >= 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);
            }
        }
    }
    REPR(i, 100000){
        if(dp[N][i] <= W){
            cout << i << endl;
            break;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> W;
    FOR(i, 1, N+1) cin >> w[i] >> v[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
