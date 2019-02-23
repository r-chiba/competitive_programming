// {{{
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
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
#define FOR(i, a, b) for(ll i = static_cast<ll>(a); i < static_cast<ll>(b); i++)
#define FORR(i, a, b) for(ll i = static_cast<ll>(a); i >= static_cast<ll>(b); i--)
#define REP(i, n) for(ll i = 0ll; i < static_cast<ll>(n); i++)
#define REPR(i, n) for(ll i = static_cast<ll>(n); i >= 0ll; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> IP;
typedef pair<ll, LP> LLP;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;
// }}}

string s, t;
int dp[3001][3001][5];

void init()
{
}

void solve()
{
    int sl = s.size();
    int tl = t.size();
    FOR(i, 1, sl+1){
        FOR(j, 1, tl+1){
            if(s[i-1] == t[j-1]){
                dp[i][j][0] = dp[i-1][j-1][0] + 1;
                dp[i][j][1] = i-1;
                dp[i][j][2] = j-1;
                int v3 = (dp[i-1][j-1][0] > 0 ? dp[i-1][j-1][1]+1 : -1);
                int v4 = (dp[i-1][j-1][0] > 0 ? dp[i-1][j-1][2]+1 : -1);
                dp[i][j][3] = v3;
                dp[i][j][4] = v4;
            }else{
                int ii = (dp[i-1][j][0] > dp[i][j-1][0] ? i-1 : i);
                int jj = (dp[i-1][j][0] > dp[i][j-1][0] ? j : j-1);
                dp[i][j][0] = dp[ii][jj][0];
                dp[i][j][1] = dp[ii][jj][1];
                dp[i][j][2] = dp[ii][jj][2];
                dp[i][j][3] = dp[ii][jj][3];
                dp[i][j][4] = dp[ii][jj][4];
            }
        }
    }
    int ii = sl;
    int jj = tl;
    string rans;
    do{
        if(dp[ii][jj][0] > 0) rans += s[dp[ii][jj][1]];
        int ni = dp[ii][jj][3];
        int nj = dp[ii][jj][4];
        ii = ni; jj = nj;
    }while(ii > 0 && jj > 0);
    reverse(ALL(rans));
    cout << rans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> t;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
