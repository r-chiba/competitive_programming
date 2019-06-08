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

int N;
int f[100][10];
int p[100][11];

void init()
{
}

void solve()
{
    ll ans = -LINF;
    FOR(i, 1, 1<<10){
        ll op[100];
        REP(j, N) op[j] = 0;
        REP(j, 10){
            if((i>>j) & 1){
                REP(k, N) if(f[k][j] == 1) op[k]++;
            }
        }
        ll profit = 0;
        REP(i, N){
            profit += p[i][op[i]];
        }
        ans = max(ans, profit);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N){
        REP(j, 5) REP(k, 2) cin >> f[i][j*2+k];
    }
    REP(i, N) REP(j, 11) cin >> p[i][j];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
