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
//const int MOD = 1e9 + 7;
const int MOD = 1000000007;
const double EPS = 1e-9;
// }}}

int N;
vector<int> v[100000];
ll dp[100000][2];

void init()
{
}

ll rec(int vtx, int color, int prev)
{
    if(dp[vtx][color] != -1) return dp[vtx][color];
    ll ret = 1;
    REP(i, v[vtx].size()){
        int next = v[vtx][i];
        if(next == prev) continue;
        if(color == 0){
            ret *= rec(next, 1, vtx);
        }else{
            ret *= (rec(next, 0, vtx) + rec(next, 1, vtx)) % MOD;
        }
        ret %= MOD;
    }
    dp[vtx][color] = ret;
    return ret;
}

void solve()
{
    REP(i, N) REP(j, 2) dp[i][j] = -1;
    cout << (rec(0, 0, -1) + rec(0, 1, -1)) % MOD << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
