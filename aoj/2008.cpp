// {{{
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#if __cplusplus >= 201103
#include <numeric>
#endif
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

#if __cplusplus >= 201103
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int n;
P h, d;
P crystals[20];

void init()
{
}

void solve()
{
    vector<int> d_d(n);
    vector<int> v(n);
    REP(i, n){
        d_d[i] = static_cast<int>(ceil(sqrt((crystals[i].fi-d.fi)*(crystals[i].fi-d.fi)
                    + (crystals[i].se-d.se)*(crystals[i].se-d.se))));
        //d_d[i] = abs(crystals[i].fi-d.fi) + abs(crystals[i].se-d.se);
        v[i] = i;
    }
    sort(ALL(v), [&d_d](size_t i1, size_t i2){return d_d[i1] < d_d[i2];});
    for(auto x : v) cout << d_d[x] << " ";
    cout << endl;

    bool ans = true;
    int cum = 0;
    P cur = h;
    REP(i, n){
        cout << crystals[v[i]].fi << ":" << crystals[v[i]].se << endl;
        int d = static_cast<int>(ceil(sqrt((crystals[v[i]].fi-cur.fi)*(crystals[v[i]].fi-cur.fi)
                 + (crystals[v[i]].se-cur.se)*(crystals[v[i]].se-cur.se))));
        //int d = abs(crystals[v[i]].fi-cur.fi) + abs(crystals[v[i]].se-cur.se);
        cout << cum+d << " " << d_d[v[i]] << endl;
        if(cum + d >= d_d[v[i]]){
            ans = false;
            break;
        }
        cum += d;
        cur = crystals[v[i]];
    }
    cout << (ans == true ? "YES" : "NO") << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){
        cin >> n >> h.fi >> h.se >> d.fi >> d.se;
        if(n == 0) break;
        REP(i, n){
            cin >> crystals[i].fi >> crystals[i].se;
        }
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker:
