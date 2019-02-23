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

const string iwi("iwi");
string s;
int dp[305];
bool removable[305][305];

void init()
{
    REP(i, 305){
        REP(j, 305){
            removable[i][j] = false;
        }
        removable[i][i] = true;
    }
}

void rec(int l, int r)
{
    int n = s.size();
    if(l < 0 || n < r) return;

    FOR(i, l, r+1){
        if(s[l] == iwi[0] && s[i] == iwi[1] && s[r-1] == iwi[2]){
            if(removable[l+1][i] && removable[i+1][r-1]){
                removable[l][r] = true;
            }
        }
        if(removable[l][i] && removable[i][r]){
            removable[l][r] = true;
        }
    }
}

void solve()
{
    int n = s.size();
    FOR(l, 3, n+1){
        REP(i, n){
            rec(i, i+l);
        }
    }

    REPR(i, n){
        dp[i] = dp[i+1];
        FOR(j, i, n+1){
            if(removable[i][j]){
                dp[i] = max(dp[i], dp[j] + (j-i));
            }
        }
    }
    cout << dp[0] / 3 << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    init();
    solve();
    return 0;
}

// vim:set foldmethod=marker:
