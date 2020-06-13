// {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <numeric>
#include <complex>
#include <utility>
#include <type_traits>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define FORR(i, a, b) for(ll i = static_cast<ll>(a); i >= static_cast<ll>(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n, 0)
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

// {{{ popcount
static int popcount(int x) {
    return __builtin_popcount(static_cast<unsigned int>(x));
}
static int popcount(unsigned int x) {
    return __builtin_popcount(x);
}
static int popcount(long x) {
    return __builtin_popcountl(static_cast<unsigned long>(x));
}
static int popcount(unsigned long x) {
    return __builtin_popcountl(x);
}
static int popcount(long long x) {
    return __builtin_popcountll(static_cast<unsigned long long>(x));
}
static int popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}
// }}}

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

// print vector
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

// print array (except char literal)
template<
    typename T,
    int N,
    typename std::enable_if<!std::is_same<T, char>::value, std::nullptr_t>::type = nullptr>
ostream &operator<<(ostream &os, const T (&v)[N]) {
    os << "[";
    for (size_t i = 0; i < N-1; i++) {
        os << v[i] << ", ";
    }
    os << v[N-1] <<  "]";
    return os;
}

// print array
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

struct UnionFind{
    vector<ll> parent;
    UnionFind(ll n) : parent(n, -1) {};
    int root(ll x){
        return (parent[x] < 0 ? x : (parent[x] = root(parent[x])));
    }
    void unite(ll x, ll y){
        x = root(x);
        y = root(y);
        if(x != y){
            if(parent[y] < parent[x]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
        }
    }
    bool same(ll x, ll y){
        return root(x) == root(y);
    }
    ll size(ll x){
        return -parent[root(x)];
    }
};

int N, M, K;
vector<set<int> > fd, bd;
UnionFind *f;

void solve()
{
    unordered_map<int, vector<int>> m;
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
        m[f->root(i)].pb(i);
    }
    for (int i = 0; i < N; ++i) {
        int a = m[f->root(i)].size() - fd[i].size() - 1;
        //for (int j: m[f->root(i)]) {
        //    if (i == j || fd[i].find(j) != fd[i].end() || bd[i].find(j) != bd[i].end())
        //        continue;
        //    a++;
        //}
        ans.pb(a);
    }
    for (int i = 0; i < N-1; ++i) {
        cout << ans[i] << " ";
    }
    cout << ans[N-1] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    fd.resize(N);
    bd.resize(N);
    f = new UnionFind(N);
    for (int i = 0; i < M; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        fd[c].insert(d);
        fd[d].insert(c);
        f->unite(c, d);
    }
    for (int i = 0; i < K; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        if (f->same(c, d) && fd[c].find(d) == fd[c].end()) {
            //bd[c].insert(d);
            //bd[d].insert(c);
            fd[c].insert(d);
            fd[d].insert(c);
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
