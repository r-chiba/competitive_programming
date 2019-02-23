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

int w, n, k;
vector<P> v;
int dp[55][10010][55];

void init()
{
}

void solve()
{
    FOR(i, 1, n+1){
        REP(j, w+1){
            FOR(l, 1, k+1){
                if(j >= v[i].fi){
                    dp[i][j][l] = max(dp[i-1][j][l], dp[i-1][j-v[i].fi][l-1] + v[i].se);
                }else{
                    dp[i][j][l] = dp[i-1][j][l];
                }
            }
        }
    }
    cout << dp[n][w][k] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> w >> n >> k;
    v.pb(mp(0, 0));
    REP(i, n){
        int a, b;
        cin >> a >> b;
        v.pb(mp(a, b));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
