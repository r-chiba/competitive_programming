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

#if 0
vector<int> h[2000], w[2000];
int mh[2000], mw[2000];
void solve()
{
    //REP(i, 2000){
    //    mh[i] = INF;
    //    mw[i] = INF;
    //}

    REP(i, H){
        REP(j, W){
            if(s[i][j] == '#'){
                h[i].pb(j);
                w[j].pb(i);
            }
        }
    }
    //int mh = 0, mw = 0;
    REP(i, H){
        int l = h[i].size();
        if(l == 0){
            mh[i] = W;
        }else{
            REP(j, l){
                mh[i] = max(mh[i], h[i][j] - (j >= 1 ? h[i][j-1] : 0) - (j >= 1 ? 1 : 0));
                //cout << mh << endl;
            }
            mh[i] = max(mh[i], W - h[i][l-1] - (l >= 1 ? 1 : 0));
        }
    }
    REP(i, W){
        int l = w[i].size();
        if(l == 0){
            mw[i] = H;
        }else{
            REP(j, l){
                mw[i] = max(mw[i], w[i][j] - (j >= 1 ? w[i][j-1] : 0 - (j >= 1 ? 1 : 0)));
                //cout << mw << endl;
            }
            mw[i] = max(mw[i], H - w[i][l-1] - (l >= 1 ? 1 : 0));
        }
    }
    int ans = 0;
    REP(i, H){
        REP(j, W){
            //cout << mh[i] << " " << mw[j] << endl;
            ans = max(ans, mh[i]+mw[j]);
        }
    }
    //cout << mh << " " << mw << endl;
    cout << ans-1 << endl;
}
#else
int ok[2][2000][2000];
void solve()
{
    REP(i, H){
        REP(j, W){
            int n = 0;
            int d1 = 1, d2 = 1;
            if(s[i][j] == '.'){
                ok[0][i][j]++;
                while(j+d1 < W && s[i][j+d1] == '.'){
                    ok[0][i][j]++;
                    d1++;
                }
                while(j-d2 >= 0 && s[i][j-d2] == '.'){
                    ok[0][i][j]++;
                    d2++;
                }
                d1 = 1; d2 = 1;
                while(i+d1 < H && s[i+d1][j] == '.'){
                    ok[1][i][j]++;
                    d1++;
                }
                while(i-d2 >= 0 && s[i-d2][j] == '.'){
                    ok[1][i][j]++;
                    d2++;
                }
            }
        }
    }
    int ans = 0;
    REP(i, H) REP(j, W) ans = max(ans, ok[0][i][j] + ok[1][i][j]);
    cout << ans << endl;
}
#endif

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
