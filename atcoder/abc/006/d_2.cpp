// {{{
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

//#if __cplusplus >= 201103
typedef long long ll;
//#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
//#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
//#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int N;
int a[30010];
int dp[30010];

void init()
{
}

void solve()
{
    FOR(i, 1, N+1){
        REP(j, i){
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = 0;
    FOR(i, 1, N+1){
        ans = max(ans, dp[i]);
    }
    cout << N - ans << endl;
}

void solve2()
{
    REP(i, N+1) dp[i] = INF;
    REP(i, N){
        *lower_bound(dp, dp+N, a[i]) = a[i];
    }
    cout << N - (lower_bound(dp, dp+N, INF) - dp) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    //FOR(i, 1, N+1) cin >> a[i];
    //solve();
    REP(i, N) cin >> a[i];
    solve2();
    return 0;
}

// vim:set foldmethod=marker:
