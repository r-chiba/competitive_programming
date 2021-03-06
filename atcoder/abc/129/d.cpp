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

int H, W;
string s[2000];
int l[2000][2000], r[2000][2000], u[2000][2000], b[2000][2000];

int brightArea(int i, int j)
{
    if (i < 0 || H <= i || j < 0 || W <= j || s[i][j] == '#')
        return 0;
    int ret = 1;
    FOR (k, 1, H) {
        if (i+k >= H || s[i+k][j] == '#') break;
        ret++;
    }
    FOR (k, 1, H) {
        if (i-k < 0 || s[i-k][j] == '#') break;
        ret++;
    }
    FOR (k, 1, W) {
        if (j+k >= W || s[i][j+k] == '#') break;
        ret++;
    }
    FOR (k, 1, W) {
        if (j-k < 0 || s[i][j-k] == '#') break;
        ret++;
    }
    return ret;
}

void solve()
{
    REP (i, H) {
        FOR (j, 1, W) {
            l[i][j] = (s[i][j-1] == '#' ? 0 : l[i][j-1]+1);
        }
    }
    REP (i, H) {
        REPR (j, W-2) {
            r[i][j] = (s[i][j+1] == '#' ? 0 : r[i][j+1]+1);
        }
    }
    FOR (i, 1, H) {
        REP (j, W) {
            u[i][j] = (s[i-1][j] == '#' ? 0 : u[i-1][j]+1);
        }
    }
    REPR (i, H-2) {
        REP (j, W) {
            b[i][j] = (s[i+1][j] == '#' ? 0 : b[i+1][j]+1);
        }
    }

    int ans = 0;
    REP (i, H) {
        REP (j, W) {
            if (s[i][j] != '#') {
                ans = max(ans, l[i][j]+r[i][j]+u[i][j]+b[i][j]+1);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H) cin >> s[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
