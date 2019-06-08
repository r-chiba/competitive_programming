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
vector<IP> p;

void init()
{
}

void solve()
{
    vector<P> r;
    sort(p.begin(), p.end());
    FOR(i, 0, N) cerr << p[i].fi << " " << p[i].se.fi << " " << p[i].se.se << endl;
    r.pb(mp(p[0].fi, p[0].se.se));
    FOR(i, 1, N){
        bool ok = false;
        REP(j, r.size()){
            if((r[j].se == p[i].se.se && r[j].fi <= p[i].se.fi)
               || (r[j].se != p[i].se.se && r[j].fi < p[i].se.fi)){
                ok = true;
                r[j].fi = p[i].fi;
                r[j].se = p[i].se.se;
                break;
            }
        }
        if(!ok) r.pb(mp(p[i].fi, p[i].se.se));
    }
    cout << r.size() << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> C;
    p.resize(N);
    REP(i, N){
        int c;
        cin >> p[i].se.fi >> p[i].fi >> p[i].se.se;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
