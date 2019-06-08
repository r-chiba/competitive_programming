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

int a, b, c;
int m;

int memo[100][100][100];

int rec(int x, int y, int z)
{
    if(memo[x][y][z] != -1) return memo[x][y][z];
    if(x == y && x == z) return 0;
    if(max(x, max(y, z)) > m+2) return INF;
    int ret = rec(x, y+1, z+1) + 1;
    ret = min(ret, rec(x+1, y, z+1) + 1);
    ret = min(ret, rec(x+1, y+1, z) + 1);
    ret = min(ret, rec(x+2, y, z) + 1);
    ret = min(ret, rec(x, y+2, z) + 1);
    ret = min(ret, rec(x, y, z+2) + 1);
    return memo[x][y][z] = ret;
}

void init()
{
}

void solve()
{
    m = max(a, max(b, c));
    REP(i, 100) REP(j, 100) REP(k, 100) memo[i][j][k] = -1;
    cout << rec(a, b, c) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
