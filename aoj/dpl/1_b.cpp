// {{{
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#if __cplusplus >= 201103
#include <numeric>
#endif
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

#if __cplusplus >= 201103
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int n, w;
int values[100];
int weights[100];
int dp[100][10001];

void init()
{
}

void solve()
{
    REP(i, n){
        FOR(j, 1, w+1){
            if(i == 0) dp[i][j] = weights[i] <= j ? values[i] : 0;
            else if(j - weights[i] < 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]]+values[i]);
            }
        }
    }
    //REP(i, n){
    //    FOR(j, 1, w+1){
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    cout << dp[n-1][w] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> w;
    REP(i, n){
        cin >> values[i] >> weights[i];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
