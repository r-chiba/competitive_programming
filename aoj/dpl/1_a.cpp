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
#if __cplusplus >= 201103
#include <numeric>
#endif
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

int n, m;
int coins[20];
int dp[20][50001];

void init()
{
    sort(coins, coins+m);
    REP(i, m){
        int d = n / coins[i];
        FOR(j, 1, d+1){
            dp[i][coins[i] * j] = j;
        }
    }
}

int dfs(int k, int sum)
{
    int ret = INF;
    int d = sum / coins[k];
    if(dp[k][sum] != 0) return dp[k][sum];
    if(k < 0) return INF;
    REP(i, d+1){
        ret = min(ret, dfs(k-1, sum-coins[k]*i) + i);
    }
    dp[k][sum] = ret;
    return ret;
}

void solve()
{
    cout << dfs(m-1, n) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m){
        cin >> coins[i];
    }
    init();
    solve();
    return 0;
}

// vim:set foldmethod=marker:
