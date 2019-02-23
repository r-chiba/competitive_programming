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

int N, Q, K;
vector<P> v[100000];
ll dp[100010];

void init()
{
}

void rec(int vtx, int prev)
{
    REP(i, v[vtx].size()){
        P &p = v[vtx][i];
        int next = p.fi;
        int d = p.se;
        if(next == prev) continue;
        dp[next] = dp[vtx] + d;
        rec(next, vtx);
    }
}

void solve()
{
    REP(i, N) dp[i] = -1;
    dp[K] = 0;
    rec(K, -1);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        v[a].pb(mp(b, c));
        v[b].pb(mp(a, c));
    }
    cin >> Q >> K;
    K--;
    solve();
    REP(i, Q){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << dp[a] + dp[b] << endl;
    }
    return 0;
}

// vim:set foldmethod=marker:
