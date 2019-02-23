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

string a, b;
int dp[1010][1010];
void init()
{
    REP(i, 1010){
        REP(j, 1010){
            dp[i][j] = 0;
        }
    }
}

void solve()
{
    int ans = 0;
    int alen = a.size();
    int blen = b.size();
    FOR(i, 1, alen+1){
        FOR(j, 1, blen+1){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i-1] == b[j-1]){
                dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
            }
        }
    }
    cout << dp[alen][blen] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        init();
        cin >> a >> b;
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker:
