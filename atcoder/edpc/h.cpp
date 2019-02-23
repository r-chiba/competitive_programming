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
char m[1000][1000];
ll memo[1000][1000];

void init()
{
}

ll rec(int i, int j)
{
    if(i >= H || j >= W) return 0;
    if(m[i][j] == '#') return memo[i][j] = 0;
    if(i == H-1 && j == W-1) return memo[i][j] = 1;
    if(memo[i][j] != -1) return memo[i][j];
    ll ret = 0;
    ret += rec(i+1, j) % MOD;
    ret += rec(i, j+1) % MOD;
    ret %= MOD;
    memo[i][j] = ret;
    return ret;
}

void solve()
{
    REP(i, H){
        REP(j, W){
            memo[i][j] = -1;
        }
    }
    cout << rec(0, 0) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H){
        REP(j, W){
            cin >> m[i][j];
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
