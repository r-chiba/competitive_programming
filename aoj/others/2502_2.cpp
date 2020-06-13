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
vector<IP> phrases;
vector<int> melodies;
int dp[400][400];

void init()
{
}

void solve()
{
    FOR(i, 1, n+1){
        REP(j, 400){
            dp[i][j] = dp[i-1][j];
            FOR(k, phrases[i].se.fi, phrases[i].se.se+1){
                if(j >= k) dp[i][j] = max(dp[i][j], dp[i][j-k] + phrases[i].fi);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    phrases.pb(mp(0, mp(0, 0)));
    REP(i, n){
        int s, l, p;
        cin >> s >> l >> p;
        phrases.pb(mp(p, mp(s, l)));
    }
    solve();
    vector<int> anss;
    cin >> m;
    REP(i, m){
        int w;
        cin >> w;
        int ans = dp[n][w];
        if(ans == 0){
            cout << -1 << endl;
            return 0;
        }else{
            anss.pb(ans);
        }
    }
    REP(i, m) cout << anss[i] << endl;
    return 0;
}

// vim:set foldmethod=marker:
