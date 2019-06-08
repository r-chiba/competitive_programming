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

int H, W, D, Q;
P a[90000];
P p[100000];
int m[900000];

void init()
{
}

void solve()
{
    REPR(i, H*W){
        if(i+D <= H*W){
            m[i] = m[i+D] + abs(a[i+D].fi-a[i].fi) + abs(a[i+D].se-a[i].se);
        }
    }
    REP(i, Q){
        cout << m[p[i].fi] - m[p[i].se] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> D;
    FOR(i, 1, H+1){
        FOR(j, 1, W+1){
            int v;
            cin >>v;
            a[v] = mp(i, j);
        }
    }
    cin >> Q;
    REP(i, Q){
        cin >> p[i].fi >> p[i].se;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
