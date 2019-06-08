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

int sx, sy, tx, ty;

void solve()
{
    string s;
    int dx = tx - sx;
    int dy = ty - sy;
    REP(i, dx) s += 'R';
    REP(i, dy) s += 'U';
    REP(i, dx) s += 'L';
    REP(i, dy) s += 'D';
    s += 'D';
    REP(i, dx+1) s += 'R';
    REP(i, dy+1) s += 'U';
    s += 'L';
    s += 'U';
    REP(i, dx+1) s += 'L';
    REP(i, dy+1) s += 'D';
    s += 'R';
    cout << s << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> sx >> sy >> tx >> ty;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
