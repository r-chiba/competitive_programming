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

#if __cplusplus >= 201103
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int n;
int pins[350][350];
int dp[350][350];

int dfs(int i, int j)
{
    if(i == n) return 0;
    int ret = 0;
    //if(j == 0){
    //    ret = max(dfs(i+1, 0)+pins[i][0], dfs(i+1, 1)+pins[i][1]);
    //}else if(j == i){
    //    ret = max(dfs(i+1, i-1)+pins[i][i-1], dfs(i+1, i)+pins[i][i]);
    //}else{
    //    ret = max(dfs(i+1, j-1)+pins[i][j-1],
    //                max(dfs(i+1, j)+pins[i][j], dfs(i+1, j+1)+pins[i][j+1]));
    //}
    int d1 = dp[i+1][j] != 0 ? dp[i+1][j] : dfs(i+1, j);
    int d2 = dp[i+1][j+1] != 0 ? dp[i+1][j+1] : dfs(i+1, j+1);
    if(dp[i+1][j] == 0) dp[i+1][j] = d1;
    if(dp[i+1][j+1] == 0) dp[i+1][j+1] = d2;
    ret = pins[i][j] + max(d1, d2);
    return ret;
}

void init()
{
}

void solve()
{
    //cout << dfs(0, 0) << endl;
    REPR(i, n-1){
        REP(j, i+1){
            if(i == n-1) dp[i][j] = pins[i][j];
            else{
                dp[i][j]  = pins[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
            }
        }
    }
    cout << dp[0][0] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n){
        REP(j, i+1){
            cin >> pins[i][j];
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
