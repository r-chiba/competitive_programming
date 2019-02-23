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

ll N, X;

void init()
{
}

inline ll getLayerNum(int level)
{
    return (1ll << (level+2)) - 3;
}

inline ll getPattyNum(int level)
{
    return (1ll << (level+1)) - 1;
}

inline ll getPattyNumLevel1(ll x)
{
    if(x <= 1) return 0;
    if(x <= 4) return x-1;
    return 3;
}

ll rec(ll x, int level)
{
    if(x == 0) return 0;
    if(x == 1) return (level == 0 ? 1 : 0);
    if(level == 1) return getPattyNumLevel1(x);
    ll nPrevLayers = getLayerNum(level-1);
    if(x <= nPrevLayers + 1){
        return rec(x-1, level-1);
    }
    return getPattyNum(level-1) + 1 + rec(x-nPrevLayers-2, level-1);
}

void solve()
{
    cout << rec(X, N) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
