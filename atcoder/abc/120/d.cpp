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

struct UnionFind {
    vector<ll> parent;
    UnionFind(ll n) : parent(n, -1) {};
    int root(ll x) {
        return (parent[x] < 0 ? x : (parent[x] = root(parent[x])));
    }
    void unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if(x != y){
            if(parent[y] < parent[x]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
        }
    }
    bool same(ll x, ll y) {
        return root(x) == root(y);
    }
    int size(ll x) {
        return -parent[root(x)];
    }
};

ll N, M;
vector<LP> e;

void solve()
{
    stack<ll> ret;
    UnionFind uf(N);
    ll n = N*(N-1)/2;
    ret.push(n);
    FORR (i, M-1, 1) {
        auto p = e[i];
        if (!uf.same(p.fi, p.se)) {
            ll fsz = uf.size(p.fi);
            ll ssz = uf.size(p.se);
            n -= fsz*ssz;
        }
        ret.push(max(n, 0ll));
        uf.unite(p.fi, p.se);
    }
    while (!ret.empty()) {
        cout << ret.top() << endl;
        ret.pop();
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP (i, M) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        e.pb(mp(x, y));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
