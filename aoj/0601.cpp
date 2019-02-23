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

int n, m, x;
vector<int> h;
vector<P> vs[100000];

int memo[100000];

void init()
{
}

void rec(int tree, int height, int cost)
{
    if(memo[tree] < cost){
        return;
    }
    memo[tree] = cost;
    int len = vs[tree].size();
    REP(i, len){
        P &p = vs[tree][i];
        if(h[p.fi] >= p.se){
            int ncost = cost + h[p.fi] - (h[tree] - p.se);
            rec(p.fi, ncost);
        }
    }
}


void solve()
{
    REP(i, 100000) memo[i] = INF;
    rec(0, h[0] - x);
    cout << (memo[n-1] == INF ? -1 : memo[n-1]) << endl;
    REP(i, n) cout << memo[i] << " ";
    cout << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    REP(i, n){
        int v;
        cin >> v;
        h.pb(v);
    }
    REP(i, m){
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        vs[a].pb(mp(b, t));
        vs[b].pb(mp(a, t));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
