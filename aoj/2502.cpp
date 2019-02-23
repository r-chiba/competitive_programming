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

int n, m, maxw;
vector<IP> v;
vector<int> w;
int dp[400][400];

void init()
{
}

void solve()
{
    REP(i, n){
        REP(j, maxw+1){
            FORR(k, v[i].se.se, v[i].se.fi){
                if(j >= k){
                    dp[i+1][j] = max(dp[i][j], dp[i+1][j-k] + v[i].fi);
                }else{
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
    }
    bool ok = true;
    REP(i, m){
        if(dp[n][w[i]] == 0){
            ok = false;
            break;
        }
    }
    if(ok){
        REP(i, m){
            cout << dp[n][w[i]] << endl;
        }
    }else{
        cout << -1 << endl;
    }
    //REP(i, m){
    //    REP(j, n+1){
    //        REP(k, w[i]+1){
    //            cout << dp[i][j][k] << " ";
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;
    //}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n){
        int s, l, p;
        cin >> s >> l >> p;
        v.pb(mp(p, mp(s, l)));
    }
    cin >> m;
    REP(i, m){
        int a;
        cin >> a;
        w.pb(a);
        maxw = max(maxw, a);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
