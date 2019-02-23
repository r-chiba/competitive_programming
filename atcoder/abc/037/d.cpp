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
//const int MOD = 1e9 + 7;
const int MOD = 1000000007;
const double EPS = 1e-9;
// }}}

int H, W;
ll grid[1000][1000];
ll dp[1000][1000];

void init()
{
}

ll rec(int x, int y)
{
    if(dp[x][y] != -1) return dp[x][y];
    ll ret = 0;
    REP(i, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
        if(grid[nx][ny] <= grid[x][y]) continue;
        ret += rec(nx, ny);
        ret %= MOD;
    }
    ret += 1;
    dp[x][y] = ret;
    return ret;
}

void solve()
{
    REP(i, H) REP(j, W) dp[i][j] = -1;
    ll ret = 0;
    REP(i, H){
        REP(j, W){
            ll val = rec(i, j);
            ret += val;
            ret %= MOD;
        }
    }
    cout << ret << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H){
        REP(j, W){
            cin >> grid[i][j];
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
