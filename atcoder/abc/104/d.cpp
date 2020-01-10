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

string s;
ll dp[100001][4];

void solve()
{
    dp[0][0] = 1;
    REP(i, s.size()){
        REP(j, 4){
            dp[i+1][j] += dp[i][j] * (s[i] == '?' ? 3 : 1);
            dp[i+1][j] %= MOD;
        }
        if(s[i] == 'A' || s[i] == '?'){
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] %= MOD;
        }
        if(s[i] == 'B' || s[i] == '?'){
            dp[i+1][2] += dp[i][1];
            dp[i+1][2] %= MOD;
        }
        if(s[i] == 'C' || s[i] == '?'){
            dp[i+1][3] += dp[i][2];
            dp[i+1][3] %= MOD;
        }
    }
    cout << dp[s.size()][3] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
