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

int a, b;
int n;
P cons[40];
ll dp[16][16];

void init()
{
}

ll rec(int x, int y)
{
    if(x == 0 && y == 0) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    REP(i, n){
        if(x == cons[i].fi && y == cons[i].se) return 0;
    }
    ll ret = 0;
    const int ddx[] = {-1, 0};
    const int ddy[] = {0, -1};
    REP(i, 2){
        int nx = x + ddx[i];
        int ny = y + ddy[i];
        if(nx < 0 || a <= nx || ny < 0 || b <= ny) continue;
        ret += rec(nx, ny);
    }
    dp[x][y] = ret;
    return ret;
}

void solve()
{
    REP(i, 16) REP(j, 16) dp[i][j] = -1;
    cout << rec(a-1, b-1) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        cin >> n;
        REP(i, n){
            int x, y;
            cin >> x >> y;
            x--; y--;
            cons[i] = mp(x, y);
        }
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker:
