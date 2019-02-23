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

int N, Z, W;
int a[2000];
map<pair<P, P>, int> m;

void init()
{
}

int rec(int n, int turn, int x, int y)
{
    if(n == 0) return abs(x - y);
    if(m.find(mp(mp(n, turn), mp(x, y))) != end(m)) return m[mp(mp(n, turn), mp(x, y))];

    int ret;
    if(turn == 1){
        ret = 0;
        FOR(i, 1, n+1){
            ret = max(ret, rec(n-i, -turn, a[N-n-1+i], y));
        }
    }else{
        ret = INF;
        FOR(i, 1, n+1){
            ret = min(ret, rec(n-i, -turn, x, a[N-n-1+i]));
        }
    }
    m.insert(mp(mp(mp(n, turn), mp(x, y)), ret));
    return ret;
}

void solve()
{
    //int x = Z, y = W;
    //cout << rec(N, 1, x, y) << endl;
    if(N == 1){
        cout << abs(W - a[0]) << endl;
    }else{
        cout << max(abs(W - a[N-1]), abs(a[N-1] - a[N-2])) << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Z >> W;
    REP(i, N) cin >> a[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
