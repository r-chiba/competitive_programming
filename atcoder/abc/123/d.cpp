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
    cerr << arr[sz-1] <<  "]";
}

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

template<typename T>
struct PairHash {
    size_t operator()(const pair<T, T> &p) const {
        const auto h1 = hash<T>()(p.fi);
        const auto h2 = hash<T>()(p.se);
        return h1 ^ (h2 << 1);
    }
};

// print floating-point number
// cout << fixed << setprecision(12) <<

// }}}

int X, Y, Z, K;
vector<ll> a, b, c;

struct Compare {
    vector<ll> &x_, &y_;
    Compare(vector<ll> &x, vector<ll> &y): x_(x), y_(y) {}
    bool operator()(const P &lhs, const P &rhs) {
        return x_[lhs.fi]+y_[lhs.se] < x_[rhs.fi]+y_[rhs.se];
    }
};

void solve()
{
    vector<ll> ab;
    REP (i, X) REP (j, Y) {
        ab.pb(a[i]+b[j]);
    }
    sort(ALL(ab), greater<ll>());
    sort(ALL(c), greater<ll>());
    unordered_set<P, PairHash<int> > s;
    priority_queue<P, vector<P>, Compare> q(Compare(ab, c));
    q.push(mp(0, 0));
    while (K > 0) {
        auto p = q.top();
        q.pop();
        if (s.find(p) != s.end()) continue;
        if (p.fi >= ab.size() || p.se >= c.size()) continue;
        s.insert(p);
        K--;
        cout << ab[p.fi]+c[p.se] << endl;
        q.push(mp(p.fi+1, p.se));
        q.push(mp(p.fi, p.se+1));
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> X >> Y >> Z >> K;
    a.resize(X);
    b.resize(Y);
    c.resize(Z);
    REP (i, X) cin >> a[i];
    REP (i, Y) cin >> b[i];
    REP (i, Z) cin >> c[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
