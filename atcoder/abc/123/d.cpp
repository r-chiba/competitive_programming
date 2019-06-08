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

int x, y, z, k;
ll a[1000], b[1000], c[1000];

void init()
{
}

#if 0
void solve()
{
    sort(a, a+x, greater<ll>());
    sort(b, b+y, greater<ll>());
    sort(c, c+z, greater<ll>());
    int ca = 0, cb = 0, cc = 0;
    int cpa = 0, cpb = 0, cpc = 0;
    int up = -1;
    vector<ll> paira, pairb, pairc;
    REP(i, y) REP(j, z) paira.pb(b[i]+c[j]);
    REP(i, z) REP(j, x) pairb.pb(c[i]+a[j]);
    REP(i, x) REP(j, y) pairc.pb(a[i]+b[j]);
    sort(paira.begin(), paira.end(), greater<ll>());
    sort(pairb.begin(), pairb.end(), greater<ll>());
    sort(pairc.begin(), pairc.end(), greater<ll>());
    k *= 3;
    while(k-- > 0){
        ll ans = 0;
        ll suma = (ca < x && cpa < y*z ? a[ca] + paira[cpa] : 0);
        ll sumb = (cb < y && cpb < z*x ? b[cb] + pairb[cpb] : 0);
        ll sumc = (cc < z && cpc < x*y ? c[cc] + pairc[cpc] : 0);
        if(suma >= sumb && suma >= sumc){
            ans = suma;
            up = 0;
        }
        else if(sumb >= suma && sumb >= sumc){
            ans = sumb;
            up = 1;
        }
        else if(sumc >= suma && sumc >= sumb){
            ans = sumc;
            up = 2;
        }
        //if(k % 3 == 0) cout << ans << endl;
        cout << ans << endl;
        //cout << ca << " " << cb << " " << cc << endl;
        //cout << cpa << " " << cpb << " " << cpc << endl;
        //cout << suma << " " << sumb << " " << sumc << endl;
        if(up == 0){
            if(ca+1 < x && cpa+1 < y*z){
                if(a[ca+1] + paira[cpa] > a[ca] + paira[cpa+1]) ca++;
                else cpa++;
            }else if(ca+1 < x){
                ca++;
            }else if(cpa+1 < y*z){
                cpa++;
            }
        }
        else if(up == 1){
            if(cb+1 < y && cpb+1 < z*x){
                if(b[cb+1] + pairb[cpb] > b[cb] + pairb[cpb+1]) cb++;
                else cpb++;
            }else if(cb+1 < y){
                cb++;
            }else if(cpb+1 < z*x){
                cpb++;
            }
        }
        if(up == 2){
            if(cc+1 < z && cpc+1 < x*y){
                if(c[cc+1] + pairc[cpc] > c[cc] + pairc[cpc+1]) cc++;
                else cpc++;
            }else if(cc+1 < z){
                cc++;
            }else if(cpc+1 < x*y){
                cpc++;
            }
        }
    }
}
#endif

void solve()
{
    sort(a, a+x, greater<ll>());
    sort(b, b+y, greater<ll>());
    sort(c, c+z, greater<ll>());
    int ca = 1, cb = 1, cc = 1;
    P cpa = mp(0, 0), cpb = mp(0, 0), cpc = mp(0, 0);
    int up = -1;
    cout << a[0] + b[0] + c[0] << endl;
    k--;
    while(k-- > 0){
        ll ans = 0;
        ll suma = (ca < x && cpa.fi < y && cpa.se < z ? a[ca] + b[cpa.fi] + c[cpa.se] : 0);
        ll sumb = (cb < y && cpb.fi < z && cpb.se < x ? b[cb] + c[cpb.fi] + a[cpb.se] : 0);
        ll sumc = (cc < z && cpc.fi < x && cpc.se < y ? c[cc] + a[cpc.fi] + b[cpc.se] : 0);
        if(suma >= sumb && suma >= sumc){
            ans = suma;
            up = 0;
        }
        else if(sumb >= suma && sumb >= sumc){
            ans = sumb;
            up = 1;
        }
        else if(sumc >= suma && sumc >= sumb){
            ans = sumc;
            up = 2;
        }
        cout << ans << endl;
        cout << ca << " " << cpa.fi << " " << cpa.se << endl;
        cout << cb << " " << cpb.fi << " " << cpb.se << endl;
        cout << cc << " " << cpc.fi << " " << cpc.se << endl;
        cout << suma << " " << sumb << " " << sumc << endl;
        if(up == 0){
            if(ca+1 < x) ca++;
            else{
                ca = 0;
                if(cpa.fi+1 < y && cpa.se+1 < z){
                    if(b[cpa.fi+1] + c[cpa.se] >= b[cpa.fi] + c[cpa.se+1]) cpa.fi++;
                    else cpa.se++;
                }else if(cpa.fi+1 < y){
                    cpa.fi++;
                }else if(cpa.se+1 < z){
                    cpa.se++;
                }
            }
        }
        else if(up == 1){
            if(cb+1 < y) cb++;
            else{
                cb = 0;
                if(cpb.fi+1 < z && cpb.se+1 < x){
                    if(c[cpb.fi+1] + a[cpb.se] >= c[cpb.fi] + a[cpb.se+1]) cpb.fi++;
                    else cpb.se++;
                }else if(cpb.fi+1 < z){
                    cpb.fi++;
                }else if(cpb.se+1 < x){
                    cpb.se++;
                }
            }
        }
        if(up == 2){
            if(cc+1 < z) cc++;
            else{
                cc = 0;
                if(cpc.fi+1 < x && cpc.se+1 < y){
                    if(a[cpc.fi+1] + b[cpc.se] >= a[cpc.fi] + b[cpc.se+1]) cpc.fi++;
                    else cpc.se++;
                }else if(cpc.fi+1 < x){
                    cpc.fi++;
                }else if(cpc.se+1 < y){
                    cpc.se++;
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> x >> y >> z >> k;
    REP(i, x) cin >> a[i];
    REP(i, y) cin >> b[i];
    REP(i, z) cin >> c[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
