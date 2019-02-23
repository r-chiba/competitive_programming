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

int N, K;
int a[2010];
ll dp[2010][2010];

void init()
{
}

void solve()
{
    REP(i, N+1) REP(j, 2001) dp[i][j] = LINF;
    REP(i, N+1) dp[i][0] = 0;

    ll games = 0;
    FOR(i, 1, N+1){
        FOR(j, 1, i+1){
            dp[i][j] = dp[i-1][j];
            ll ai = games + a[i];
            ll ai_ = games;
            ll wi_ = dp[i-1][j-1];
            REP(k, a[i]+1){
                if((i == 1 && k > 0) || (wi_+k)*ai_ > ai*wi_){
                    dp[i][j] = min(dp[i][j], wi_ + k);
                    break;
                }
            }
        }
        games += a[i];
    }

    if(games == K){
        // always win_rate = 1
        cout << 1 << endl;
    }else{
        REPR(i, N){
            if(dp[N][i] <= K){
                cout << i << endl;
                break;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    FOR(i, 1, N+1){
        cin >> a[i];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
