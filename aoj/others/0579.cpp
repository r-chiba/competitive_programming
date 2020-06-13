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

int d, n;
vector<int> ts;
vector<IP> cs;
int dp[201][201];

void init()
{
}

void solve()
{
    REP(i, n){
        REP(j, n){
            if(cs[i].se.fi <= ts[1] && ts[1] <= cs[i].se.se
               && cs[j].se.fi <= ts[0] && ts[0] <= cs[j].se.se){
                dp[1][i] = max(dp[1][i], abs(cs[i].fi-cs[j].fi));
            }
        }
    }
    FOR(i, 1, d-1){
        REP(j, n){
            if(cs[j].se.fi <= ts[i+1] && ts[i+1] <= cs[j].se.se){
                REP(k, n){
                   if(cs[k].se.fi <= ts[i] && ts[i] <= cs[k].se.se){
                    dp[i+1][j] = max(dp[i+1][j], dp[i][k] + abs(cs[k].fi-cs[j].fi));
                   }
                }
            }
        }
    }
    int ans = 0;
    REP(i, n){
        ans = max(ans, dp[d-1][i]);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> d >> n;
    REP(i, d){
        int a;
        cin >> a;
        ts.pb(a);
    }
    REP(i, n){
        int a, b, c;
        cin >> a >> b >> c;
        cs.pb(mp(c, mp(a, b)));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
