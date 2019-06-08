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

int N, C;
int d[30][30];
int c[500][500];
ll cost[3][30];

void init()
{
}

void solve()
{
    REP(i, N){
        REP(j, N){
            REP(k, C){
                int idx = (i+j+2)%3;
                cost[idx][k] += d[c[i][j]][k];
            }
        }
    }
    ll ans = LINF;
    REP(i, C){
        REP(j, C){
            if(j == i) continue;
            REP(k, C){
                if(k == i || k == j) continue;
                ans = min(ans, cost[0][i]+cost[1][j]+cost[2][k]);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> C;
    REP(i, C) REP(j, C) cin >> d[i][j];
    REP(i, N){
        REP(j, N){
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
