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

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

// }}}

int N, K;
string s;

typedef pair<P, P> PP;
class Compare
{
public:
    bool operator()(const PP &lhs, const PP &rhs){
        if(lhs.fi.se < rhs.fi.se)
            return false;
        else if(lhs.fi.se == rhs.fi.se){
            int lc = 0, rc = 0;
            int lidx = (s[lhs.se.fi] == 'L' ? lhs.se.fi-1 : lhs.se.fi+1);
            int lidx2 = (s[lhs.se.se] == 'L' ? lhs.se.se-1 : lhs.se.se+1);
            int ridx = (s[rhs.se.fi] == 'L' ? rhs.se.fi-1 : rhs.se.fi+1);
            int ridx2 = (s[rhs.se.se] == 'L' ? rhs.se.se-1 : rhs.se.se+1);
            if((0 <= lidx && lidx < N) && s[lidx] == s[lhs.se.fi]){
                lc++;
            }
            if((0 <= lidx2 && lidx2 < N) && s[lidx2] == s[lhs.se.se]){
                lc++;
            }
            if((0 <= ridx && ridx < N) && s[ridx] == s[rhs.se.fi]){
                rc++;
            }
            if((0 <= ridx2 && ridx2 < N) && s[ridx2] == s[rhs.se.se]){
                rc++;
            }
            cout << "[" << lhs.se.fi << "," << lhs.se.se << "]: " << lc << " "
                 << "[" << rhs.se.fi << "," << rhs.se.se << "]: " << rc << endl;
            if(lc < rc) return false;
        }

        return true;
    }
};

void rotate(string &v, int l, int r)
{
    int n = r - l + 1;
    REP(i, n/2){
        char vl = v[l+i], vr = v[r-i];
        v[l+i] = (vr == 'L' ? 'R' : 'L');
        v[r-i] = (vl == 'L' ? 'R' : 'L');
    }
}

int count(string &v)
{
    int ret = 0;
    REP(i, N){
        int idx = (v[i] == 'L' ? i-1 : i+1);
        if((0 <= idx && idx < N) && v[idx] == v[i]){
            ret++;
        }
    }
    return ret;
}

void compress(string &s, vector<PP> &v)
{
    char t = s[0];
    int n = 1;
    int l = 0;
    FOR(i, 1, s.size()){
        if(s[i] == t) n++;
        else{
            v.pb(mp(mp(t, n), mp(l, i-1)));
            t = s[i];
            n = 1;
            l = i;
        }
    }
    v.pb(mp(mp(t, n), mp(l, s.size()-1)));
}

void compress2(string &s, vector<PP> &vl, vector<PP> &vr)
{
    char t = s[0];
    int n = 1;
    int l = 0;
    FOR(i, 1, s.size()){
        if(s[i] == t) n++;
        else{
            if(t == 'L')
                vl.pb(mp(mp(t, n), mp(l, i-1)));
            else
                vr.pb(mp(mp(t, n), mp(l, i-1)));
            t = s[i];
            n = 1;
            l = i;
        }
    }
    if(t == 'L')
        vl.pb(mp(mp(t, n), mp(l, s.size()-1)));
    else
        vr.pb(mp(mp(t, n), mp(l, s.size()-1)));
}

void solve()
{
    string sl(s), sr(s);
    vector<PP> vl, vr;
    compress2(s, vl, vr);
    sort(ALL(vl), Compare());
    sort(ALL(vr), Compare());
    REP(i, vl.size()){
        cout << (char)vl[i].fi.fi << " " << vl[i].fi.se << " "
             << vl[i].se.fi << " " << vl[i].se.se << endl;
    }
    REP(i, vr.size()){
        cout << (char)vr[i].fi.fi << " " << vr[i].fi.se << " "
             << vr[i].se.fi << " " << vr[i].se.se << endl;
    }
    REP(i, min((ll)vl.size(), (ll)K)){
        rotate(sl, vl[i].se.fi, vl[i].se.se);
    }
    REP(i, min((ll)vr.size(), (ll)K)){
        rotate(sr, vr[i].se.fi, vr[i].se.se);
    }
    cout << max(count(sl), count(sr)) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    cin >> s;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
