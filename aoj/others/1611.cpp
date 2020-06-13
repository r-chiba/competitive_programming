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

int n;
int w[305];
int dp[305][305];

void init()
{
    REP(i, 305){
        w[i] = 0;
        REP(j, 305){
            dp[i][j] = -1;
        }
    }
}

int rec(int l, int r)
{
    if(r - l <= 1) return 0;
    if(dp[l][r] != -1) return dp[l][r];

    int ret = 0;
    if(abs(w[l] - w[r-1]) <= 1){
        if(rec(l+1, r-1) == r-l-2){
            ret = r-l;
            goto end;
        }
    }
    FOR(i, l+1, r){
        ret = max(ret, rec(l, i) + rec(i, r));
    }

end:
    dp[l][r] = ret;
    return ret;
}

void solve()
{
    cout << rec(0, n) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true){
        cin >> n;
        if(n == 0) break;
        init();
        REP(i, n) cin >> w[i];
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker:
