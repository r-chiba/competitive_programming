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
#include <unordered_set>
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

struct Hash {
    size_t operator()(const P &x) const {
        size_t f = hash<int>()(x.fi);
        size_t s = hash<int>()(x.se);
        return ((f << 1) ^ s);
    }
};

struct Compare {
    ll *a_;

    Compare(ll *a):a_(a) {}

    bool operator()(const P &lhs, const P &rhs) const {
        return a_[lhs.fi] + a_[lhs.se] < a_[rhs.fi] + a_[rhs.se];
    }
};

ll N, M;
ll a[100010];
unordered_set<P, Hash> s;

void solve()
{
    sort(a, a+N, greater<ll>());
    ll ans = 0;
    Compare comp(a);
    priority_queue<P, vector<P>, Compare> q(comp);
    q.push(mp(0, 0));
    while (!q.empty() && M > 0) {
        auto p = q.top();
        q.pop();
        if (s.find(p) != s.end()) continue;
        s.insert(p);
        M--;
        ans += a[p.fi] + a[p.se];
        if (p.fi < N-1)
            q.push(mp(p.fi+1, p.se));
        if (p.se < N-1)
            q.push(mp(p.fi, p.se+1));
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP (i, N) cin >> a[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
