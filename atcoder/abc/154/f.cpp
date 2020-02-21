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
#include <unordered_map>
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

#define DBG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using IP = pair<int, P>;
using LLP = pair<ll, LP>;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;

// template specialization of std::hash for std::pair
namespace std {
template<typename T, typename U>
struct hash<pair<T, U> > {
    size_t operator()(const pair<T, U> &key) const noexcept {
        size_t h1 = hash<T>()(key.first);
        size_t h2 = hash<U>()(key.second);
        return h1 ^ (h2 << 1);
    }
};
} // namespace std

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    size_t sz = v.size();
    os << "[";
    for (size_t i = 0; i < sz-1; i++) {
        os << v[i] << ", ";
    }
    os << v[sz-1] <<  "]";
    return os;
}

template<typename T>
void printArray(T *arr, size_t sz) {
    cerr << "[";
    for (size_t i = 0; i < sz-1; i++) {
        cerr << arr[i] << ",";
    }
    cerr << arr[sz-1] <<  "]" << endl;
}

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

struct Compare {
    //vector<ll> &x_, &y_;
    //Compare(vector<ll> &x, vector<ll> &y): x_(x), y_(y) {}
    //bool operator()(const P &lhs, const P &rhs) {
    //    return x_[lhs.fi]+y_[lhs.se] < x_[rhs.fi]+y_[rhs.se];
    //}
    bool operator()(const int x, const int y) {
        return x < y;
    }
};

// print floating-point number
// cout << fixed << setprecision(12) <<

// }}}

ll pow_mod(ll x, ll n, ll mod)
{
    ll ret = 1ll;
    ll v = x;
    for (; n > 0; n >>= 1) {
        if (n & 1) (ret *= v) %= mod;
        (v *= v) %= mod;
    }
    return ret;
}

ll mod_inverse(ll a, ll m)
{
    return pow_mod(a, m-2, m);
}
constexpr int COMB_MAX = 1000001;
ll fac[COMB_MAX];   // fac[i]  = i!        (mod MOD)
ll finv[COMB_MAX];  // finv[i] = (i!)^{-1} (mod MOD)
ll inv[COMB_MAX];   // inv[i]  = i^{-1}    (mod MOD)

ll s[1000010];

void combInit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR(i, 2, COMB_MAX){
        fac[i] = fac[i-1] * i % MOD;
        // i^{-1} (mod p) = -(p mod i)^{-1} * (p/i) (mod p)
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll comb(int n, int k)
{
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

ll perm(int n, int k)
{
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD;
}

ll r1, r2, c1, c2;

void solve()
{
    combInit();
    ll ans = 0;
    FOR (c, c1, c2+1) {
        ll first = comb(r1+c, r1);
        ll ratio = (r1+c+1) * (r1+1) % MOD;
        ll s = first * mod(pow_mod(ratio, r2-r1+1, MOD) - 1, MOD)
                * mod_inverse(mod(ratio - 1, MOD), MOD);
        s %= MOD;
        ans = (ans + s) % MOD;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> r1 >> c1 >> r2 >> c2;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
