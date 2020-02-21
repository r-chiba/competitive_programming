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

int A, B, Q;
ll s[100010], t[100010], x[100010];
ll smv[100010], tmv[100010];

unordered_map<ll, int> m;
unordered_map<ll, LP> mxs, mxt, mst, mts;

void solve()
{
    sort(smv, smv+A);
    sort(tmv, tmv+B);
    REP (i, A) {
        ll j = lower_bound(t, t+B, s[i]) - t;
        auto kit = lower_bound(tmv, tmv+B, -s[i]);
        ll k = (kit != tmv+B ? m[-*kit] : B);
        ll dj = (j < B ? abs(t[j]-s[i]) : LINF);
        ll dk = (k < B ? abs(t[k]-s[i]) : LINF);
        if (dj < dk) {
            mst[s[i]] = mp(dj, j);
        } else {
            mst[s[i]] = mp(dk, k);
        }
    }
    REP (i, B) {
        ll j = lower_bound(s, s+A, t[i]) - s;
        auto kit = lower_bound(smv, smv+A, -t[i]);
        ll k = (kit != smv+A ? m[-*kit] : A);
        ll dj = (j < A ? abs(s[j]-t[i]) : LINF);
        ll dk = (k < A ? abs(s[k]-t[i]) : LINF);
        if (dj < dk) {
            mts[t[i]] = mp(dj, j);
        } else {
            mts[t[i]] = mp(dk, k);
        }
    }
    REP (i, Q) {
        ll js, ks, jt, kt;
        ll djs, dks, djt, dkt;
        {
            js = lower_bound(s, s+A, x[i]) - s;
            auto kit = lower_bound(smv, smv+A, -x[i]);
            ks = (kit != smv+A ? m[-*kit] : A);
            djs = (js < A ? abs(s[js]-x[i]) : LINF);
            dks = (ks < A ? abs(s[ks]-x[i]) : LINF);
            if (js == A) js = 0;
            if (ks == A) ks = 0;
        }
        {
            jt = lower_bound(t, t+B, x[i]) - t;
            auto kit = lower_bound(tmv, tmv+B, -x[i]);
            kt = (kit != tmv+B ? m[-*kit] : B);
            djt = (jt < B ? abs(t[jt]-x[i]) : LINF);
            dkt = (kt < B ? abs(t[kt]-x[i]) : LINF);
            if (jt == B) jt = 0;
            if (kt == B) kt = 0;
        }
        ll dxs1 = djs + mst[s[js]].fi;
        ll dxs2 = dks + mst[s[ks]].fi;
        ll dxt1 = djt + mts[t[jt]].fi;
        ll dxt2 = dkt + mts[t[kt]].fi;
        cout << min(dxs1, min(dxs2, min(dxt1, dxt2))) << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> B >> Q;
    REP (i, A) {
        cin >> s[i];
        m[s[i]] = i;
        smv[i] = -s[i];
    }
    REP (i, B) {
        cin >> t[i];
        m[t[i]] = i;
        tmv[i] = -t[i];
    }
    REP (i, Q) {
        cin >> x[i];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
