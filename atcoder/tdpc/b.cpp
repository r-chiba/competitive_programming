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

int A, B;
int a[1010];
int b[1010];
int dp[1010][1010];

void init()
{
}

// returns point which first player can obtain when A deck has i cards and B deck has j cards.
int rec(int i, int j)
{
    if(i == 0 && j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ret;
    if((A-i + B-j) % 2 == 0){ // frist player's turn
        // first player aims to maximize his point.
        ret = (i >= 1) ? rec(i-1, j) + a[A-i] : 0;
        ret = max(ret, (j >= 1) ? rec(i, j-1) + b[B-j] : 0);
    }else{ // second player's turn
        // second player aims to minimize first player's point.
        ret = (i >= 1) ? rec(i-1, j) : INF;
        ret = min(ret, (j >= 1) ? rec(i, j-1) : INF);
    }
    dp[i][j] = ret;
    return ret;
}

void solve()
{
    REP(i, A+1) REP(j, B+1) dp[i][j] = -1;
    cout << rec(A, B) << endl;
}

void solve2()
{
    REPR(i, A){
        REPR(j, B){
            if(i == A && j == B) dp[i][j] = 0;
            else if((i+j) % 2 == 0){
                dp[i][j] = 0;
                if(i < A) dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j]);
                if(j < B) dp[i][j] = max(dp[i][j+1] + b[j], dp[i][j]);
            }else{
                dp[i][j] = INF;
                if(i < A) dp[i][j] = min(dp[i+1][j], dp[i][j]);
                if(j < B) dp[i][j] = min(dp[i][j+1], dp[i][j]);
            }
        }
    }
    cout << dp[0][0] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> B;
    FOR(i, 0, A) cin >> a[i];
    FOR(i, 0, B) cin >> b[i];
    solve2();
    return 0;
}

// vim:set foldmethod=marker:
