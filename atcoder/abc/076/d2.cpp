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

//#define RES 10000
//#define UNIT (1.0/RES)
#define RES 1
#define UNIT (1.0/RES)
int N;
int t[101], v[101];
int tt;
int tsum[101];
//int lim[200000001];

void init()
{
}

#if 0
void solve()
{
    int prev = 0;
    REP(i, N){
        FOR(j, prev*RES+1, (prev+t[i])*RES+1) lim[j] = v[i];
        prev += t[i];
    }

    double ans = 0.;
    double vel = 0.;
    int cur = 0;
    for(int i = 1; i <= tt*RES; i++){
        if(i > tsum[cur]*RES) cur++;
        double nlim = (v[cur+1] > v[cur] ? INF : (tsum[cur]*RES - i)*UNIT + v[cur+1]);
        double llim = (tt*RES - i)*UNIT;
        double nvel = min(vel+UNIT, min(lim[i]*1., min(nlim, llim)));
        double dv = nvel - vel;
        ans += abs(dv) * 0.5;
        ans += min(vel, nvel);
        vel = nvel;
        //if(i % 100 == 0) cerr << i << " " << nvel << " " << ans << endl;
    }
    cout << fixed << setprecision(5) << ans*UNIT << endl;
}
#endif
void solve()
{
    int prev = 0;
    //REP(i, N){
    //    FOR(j, prev*RES+1, (prev+t[i])*RES+1) lim[j] = v[i];
    //    prev += t[i];
    //}

    double ans = 0.;
    double vel = 0.;
    for(int i = 0; i < N; i++){
        double cur = (i > 0 ? tsum[i-1] : 0);
        //double v1 = (tsum[i]-cur+v[i+1]+vel) * 0.5;
        //double v2 = (tsum[N-1]-cur+vel) * 0.5;
        //double nv = min(v[i]*1., min(vel+t[i], min(v1, v2)));
        double v1 = LINF;
        FOR(j, i, N){
            v1 = min(v1, (tsum[j]-cur+v[j+1]+vel) * 0.5);
        }
        double nv = min(v[i]*1., min(vel+t[i], v1));
        double nvl = min(v1, v[i+1]*1.);
        double d1 = (nv > vel ? nv - vel : 0);
        double d2 = (nvl > nv ? 0 : abs(nvl - nv));
        double d3 = (d1+d2 > t[i] ? 0 : t[i] - d1 - d2);
        double dv = (nv > vel ? nv - vel : 0.);
        ans += d1 * dv * 0.5 + d1 * vel;
        ans += d2 * (nv - nvl) * 0.5 + d2 * nvl;
        ans += d3 * nv;
        vel = nv;
        //cout << v1 << " " << v2 << " [" << nv << "] " << nvl
        //     << " (" << d1 << " " << d2 << " " << d3 << ") " << ans << endl;
    }
    cout << fixed << setprecision(5) << ans*UNIT << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N){
        cin >> t[i];
        tt += t[i];
        tsum[i] = t[i] + (i > 0 ? tsum[i-1] : 0);
    }
    REP(i, N) cin >> v[i];
    v[N] = 0;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
