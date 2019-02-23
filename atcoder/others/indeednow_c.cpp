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

int n, m;
int companies[50000][4];
int people[50000][3];
int dp[110][110][110];

void init()
{
}

void solve()
{
    REP(i, n){
        int val = companies[i][3];
        dp[companies[i][0]][companies[i][1]][companies[i][2]] = max(val,
            dp[companies[i][0]][companies[i][1]][companies[i][2]]);
    }
    REP(i,101){
        REP(j,101){
            REP(k,101){
                if(i >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                if(j >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                if(k >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
            }
        }
    }

    REP(i, m){
        cout << dp[people[i][0]][people[i][1]][people[i][2]] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n){
        REP(j, 4) cin >> companies[i][j];
    }
    REP(i, m){
        REP(j, 3) cin >> people[i][j];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
