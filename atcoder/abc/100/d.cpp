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

ll N, M;
LLP v[1001];
LLP dp[1001][1001];

void init()
{
}

void solve()
{
    FOR(i, 1, N+1){
        FOR(j, 1, min(i, M)+1){
            if(i == 1 && j == 1){
                dp[i][j].fi = v[1].fi;
                dp[i][j].se.fi = v[1].se.fi;
                dp[i][j].se.se = v[1].se.se;
                continue;
            }
            ll nx = dp[i-1][j].fi;
            ll ny = dp[i-1][j].se.fi;
            ll nz = dp[i-1][j].se.se;
            ll cva = abs(nx) + abs(ny) + abs(nz);
            FOR(k, j-1, i){
                REP(l, 2){
                    if(k < j-l) continue;
                    ll nnx = dp[k][j-l].fi + (l == 1 ? v[i].fi : 0);
                    ll nny = dp[k][j-l].se.fi + (l == 1 ? v[i].se.fi : 0);
                    ll nnz = dp[k][j-l].se.se + (l == 1 ? v[i].se.se : 0);
                    ll nva = abs(nnx) + abs(nny) + abs(nnz);
                    //cout << "\t" << i << " " << j << " " << k << " " << j-l << " "
                    //     << nnx << " " << nny << " " << nnz << " " << nva << endl;
                    if(nva > cva){
                        //if(j == i) cout << i << " " 
                        //                << dp[i][j].fi << " "
                        //                << dp[i][j].se.fi << " "
                        //                << dp[i][j].se.se << " " << endl;
                        cva = nva;
                        nx = nnx;
                        ny = nny;
                        nz = nnz;
                    }
                    //else{
                    //    dp[i][j].fi = dp[i-1][j].fi;
                    //    dp[i][j].se.fi = dp[i-1][j].se.fi;
                    //    dp[i][j].se.se = dp[i-1][j].se.se;
                    //}
                }
            }
            dp[i][j].fi = nx;
            dp[i][j].se.fi = ny;
            dp[i][j].se.se = nz;
            //cout << i << " " << j << " " 
            //     << dp[i][j].fi << " "
            //     << dp[i][j].se.fi << " "
            //     << dp[i][j].se.se << " " << endl;
        }
    }
    ll ans = abs(dp[N][M].fi) + abs(dp[N][M].se.fi) + abs(dp[N][M].se.se);
    cout << ans << endl;

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    FOR(i, 1, N+1){
        cin >> v[i].fi >> v[i].se.fi >> v[i].se.se;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
