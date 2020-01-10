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

int A, B, Q;
vector<ll> s, t, x;

#if 0
void find(vector<ll> &a, vector<ll> &b, vector<LP> &c)
{
    cout << "start find()" << endl;
    auto itb = b.begin();
    for(ll v: a){
        while(itb+1 != b.end() && v > *itb && !(*itb < v && v <= *(itb+1))) itb++;
        cout << "v=" << v << ", *itb=" << *itb << endl;
        if(v < *itb){
            cout << *itb - v << endl;
            c.pb(mp(*itb-v, itb-b.begin()));
        }else if(itb+1 == b.end()){
            cout << v - *itb << endl;
            c.pb(mp(v-*itb, itb-b.begin()));
        }else{
            ll dl = v - *itb;
            ll dr = *(itb+1) - v;
            cout << dl << " " << dr << endl;
            if(dl < dr) c.pb(mp(dl, itb-b.begin()));
            else c.pb(mp(dr, itb-b.begin()+1));
        }
    }
}
#else
void find(vector<ll> &a, vector<ll> &b, map<ll, LP> &c)
{
    //cout << "start find()" << endl;
    auto itb = b.begin();
    for(ll v: a){
        while(itb+1 != b.end() && v > *itb && !(*itb < v && v <= *(itb+1))) itb++;
        //cout << "v=" << v << ", *itb=" << *itb << endl;
        if(v < *itb){
            c[v] = mp(*itb-v, *itb);
        }else if(itb+1 == b.end()){
            c[v] = mp(v-*itb, *itb);
        }else{
            ll dl = v - *itb;
            ll dr = *(itb+1) - v;
            if(dl < dr) c[v] = mp(dl, *itb);
            else c[v] = mp(dr, *(itb+1));
        }
        //cout << v << " " << c[v].fi << " " << c[v].se << endl;
    }
}
#endif

void solve()
{
    vector<ll> xx(x);
    sort(ALL(xx));
    map<ll, LP> vxs, vxt, vst, vts;
    find(xx, s, vxs);
    find(xx, t, vxt);
    find(s, t, vst);
    find(t, s, vts);
    //cout << endl;
    REP(i, Q){
        ll d1 = vxs[x[i]].fi + vst[vxs[x[i]].se].fi;
        //cout << x[i] << ": " << vxs[x[i]].fi << " " << vxs[i].se << ": " << vst[vxs[i].se].fi << endl;
        ll d2 = vxt[x[i]].fi + vts[vxt[x[i]].se].fi;
        //cout << x[i] << ": " << vxt[x[i]].fi << " " << vxt[i].se << ": " << vst[vxs[i].se].fi << endl;
        cout << min(d1, d2) << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> B >> Q;
    s.resize(A);
    t.resize(B);
    x.resize(Q);
    REP(i, A) cin >> s[i];
    REP(i, B) cin >> t[i];
    REP(i, Q) cin >> x[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
