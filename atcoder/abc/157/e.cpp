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

class SegmentTree {
    size_t sz_, rsz_;
    vector<vector<int>> v_;

    void construct(size_t idx) {
        if (idx >= sz_-1) return;
        construct(2*idx+1);
        construct(2*idx+2);
        for (int i = 0; i < 26; ++i) {
            v_[idx][i] = v_[2*idx+1][i] + v_[2*idx+2][i];
        }
    }

    vector<int> query(size_t a, size_t b, size_t k, size_t l, size_t r) {
        vector<int> v(26);
        if (r <= a || b <= l) return v;
        if (a <= l && r <= b) return v_[k];
        size_t mid = (l+r) / 2;
        auto lv = query(a, b, 2*k+1, l, mid);
        auto rv = query(a, b, 2*k+2, mid, r);
        for (int i = 0; i < 26; ++i) {
            v[i] = lv[i] + rv[i];
        }
        return v;
    }

public:
    SegmentTree(size_t n): rsz_(n) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        v_.resize(2*sz_ - 1, vector<int>(26));
    }

    SegmentTree(string s): rsz_(s.size()) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        v_.resize(2*sz_ - 1, vector<int>(26));
        for (size_t i = 0; i < rsz_; i++) {
            v_[sz_-1+i][s[i]-'a'] = 1;
        }
        (void)construct(0);
    }

    int query(size_t a, size_t b) {
        auto v = query(a, b, 0, 0, sz_);
        int ret = 0;
        REP (i, 26) {
            ret += (v[i] > 0 ? 1 : 0);
        }
        return ret;
    }

    void update(size_t idx, char k) {
        int n = k - 'a';
        idx += sz_-1;
        if (v_[idx][n] > 0) return;
        int o = 0;
        REP (i, 26) {
            if (v_[idx][i] > 0){
                o = i;
                break;
            }
        }
        v_[idx][n]++;
        v_[idx][o]--;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            v_[idx][n]++;
            v_[idx][o]++;
        }
    }

    void print() {
        size_t vsz = v_.size();
        for (size_t i = 0; i < vsz; i++) {
            cout << v_[i] << " ";
        }
        cout << endl;
    }
};

int N, Q;
string s;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> s >> Q;
    SegmentTree st(s);
    REP (i, Q) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            int b;
            char c;
            cin >> b >> c;
            b--;
            st.update(b, c);
        } else {
            int b, c;
            cin >> b >> c;
            b--; c--;
            cout << st.query(b, c+1) << endl;
        }
    }
    return 0;
}

// vim:set foldmethod=marker:
