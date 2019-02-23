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

typedef pair<ll, ll> LP;
typedef pair<bool, LP> BLP;
int N, M;
int a[100010];
BLP dp[10010][10010];

void init()
{
}

LP rec(int l, int r)
{
    LP ret;
    if(r - l < 1){
        ret.fi = 0;
        ret.se = 0;
    }else if(r - l == 1){
        ret.fi = (a[l] % M == 0) ? 1ll : 0ll;
        ret.se = a[l];
    }else if(dp[l][r].fi){
        ret = dp[l][r].se;
    }else{
        int mid = (l + r)/2;
        LP lans = rec(l, mid);
        LP rans = rec(mid, r);
        ret.fi = lans.fi + rans.fi;
        ret.se = lans.se + rans.se;
        if(ret.se % M == 0) ret.fi++;
    }
    if(!dp[l][r].fi){
        dp[l][r].fi = true;
        dp[l][r].se = ret;
    }
    return ret;
}

void solve()
{
    cout << rec(0, N).fi << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N){
        cin >> a[i];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
