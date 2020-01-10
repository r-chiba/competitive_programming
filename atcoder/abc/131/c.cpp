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

ll a, b, c, d;

ll roundup(ll x, ll b)
{
    return ((x+b-1) / b) * b;
}

ll rounddown(ll x, ll b)
{
    return (x / b) * b;
}

ll gcd(ll a, ll b)
{
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

inline ll lcm(ll a, ll b)
{
    // a*b may be overflowed
    return a / gcd(a, b) * b;
}
void solve()
{
    ll lcm_cd = lcm(c, d);

    ll cu = roundup(a, c);
    ll cd = rounddown(b, c);
    ll ncu = cu / c;
    ll ncd = cd / c;

    ll du = roundup(a, d);
    ll dd = rounddown(b, d);
    ll ndu = du / d;
    ll ndd = dd / d;

    ll lu = roundup(a, lcm_cd);
    ll ld = rounddown(b, lcm_cd);
    ll nlu = lu / lcm_cd;
    ll nld = ld / lcm_cd;

#if 0
    cout << cu << " " << cd << " " << ncu << " " << ncd << endl
         << du << " " << dd << " " << ndu << " " << ndd << endl
         << lu << " " << ld << " " << nlu << " " << nld << endl;

    cout << (ncd - ncu + 1) << " "
         << (ndd - ndu + 1) << " "
         << (nld - nlu + 1) << endl;
#endif

    cout << (b - a + 1) - ((ncd - ncu + 1) + (ndd - ndu + 1) - (nld - nlu + 1)) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
