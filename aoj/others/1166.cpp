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

// print pair
template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << ", " << p.se << ")";
    return os;
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

int w, h;
int m[50][50];
int lr[50][50], ub[50][50];

inline bool movable(P p, int d)
{
    int x = p.fi, y = p.se;
    int nx = x + dx[d], ny = y + dy[d];
    if (nx - x == 1) {
        return nx < w && lr[y][x] != 1 && m[ny][nx] == 0;
    } else if (nx - x == -1) {
        return nx >= 0 && lr[y][x-1] != 1 && m[ny][nx] == 0;
    } else if (ny - y == 1) {
        return ny < h && ub[y][x] != 1 && m[ny][nx] == 0;
    } else {
        return ny >= 0 && ub[y-1][x] != 1 && m[ny][nx] == 0;
    }
}

void solve()
{
    REP (i, h) REP (j, w) m[i][j] = 0;
    queue<IP> q;
    q.emplace(1, mp(0, 0));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.se.fi, y = p.se.se;
        if (x < 0 || w <= x || y < 0 || h <= y)
            continue;
        if (m[y][x] != 0)
            continue;
        //cerr << p.se << " " << m[y][x] << endl;
        if (x == w-1 && y == h-1) {
            cout << p.fi << endl;
            return;
        }
        m[y][x] = 1;
        REP (i, 4) {
            if (movable(p.se, i)) {
                q.emplace(p.fi+1, mp(x+dx[i], y+dy[i]));
            }
        }
    }
    cout << 0 << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (true) {
        REP (i, 50) REP (j, 50) lr[i][j] = 0;
        REP (i, 50) REP (j, 50) ub[i][j] = 0;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        REP (i, 2*h-1) {
            if (i % 2 == 0) {
                REP (j, w-1) cin >> lr[i/2][j];
            } else {
                REP (j, w) cin >> ub[i/2][j];
            }
        }
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker:
