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

// segment tree (range min)
template<typename T>
class SegmentTree {
    size_t sz_, rsz_;
    vector<T> v_;

    T construct(size_t idx) {
        if (idx >= sz_-1) return v_[idx];
        return v_[idx] = min(construct(2*idx+1), construct(2*idx+2));
    }

    T query(size_t a, size_t b, size_t k, size_t l, size_t r) {
        if (r <= a || b <= l) return numeric_limits<T>::max();
        if (a <= l && r <= b) return v_[k];
        size_t mid = (l+r) / 2;
        T lv = query(a, b, 2*k+1, l, mid);
        T rv = query(a, b, 2*k+2, mid, r);
        return min(lv, rv);
    }

public:
    SegmentTree(size_t n): rsz_(n) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        v_.resize(2*sz_ - 1, numeric_limits<T>::max());
    }

    SegmentTree(vector<T> &v): rsz_(v.size()) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        v_.resize(2*sz_ - 1, numeric_limits<T>::max());
        for (size_t i = 0; i < rsz_; i++) {
            v_[sz_-1+i] = v[i];
        }
        (void)construct(0);
    }

    // return min value in [a, b)
    T query(size_t a, size_t b) {
        return query(a, b, 0, 0, sz_);
    }

    void update(size_t idx, T k) {
        idx += sz_-1;
        v_[idx] = k;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            v_[idx] = min(v_[2*idx+1], v_[2*idx+2]);
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

// lazy-evaluated segment tree (range sum)
template<typename T>
class LazyEvalSegmentTree {
    size_t sz_, rsz_;
    vector<T> val_, lazy_;

    T construct(size_t idx) {
        if (idx >= sz_-1) return val_[idx];
        return val_[idx] = construct(2*idx+1) + construct(2*idx+2);
    }

    void evaluate(size_t k, size_t l, size_t r) {
        if (lazy_[k] == 0) return;
        val_[k] += lazy_[k];
        if (k < sz_ - 1) {
            lazy_[2*k+1] += lazy_[k]/2;
            lazy_[2*k+2] += lazy_[k]/2;
        }
        lazy_[k] = 0;
    }

    T query(size_t a, size_t b, size_t k, size_t l, size_t r) {
        if (r <= a || b <= l) return 0;
        evaluate(k, l, r);
        if (a <= l && r <= b) return val_[k];
        size_t mid = (l+r) / 2;
        T lv = query(a, b, 2*k+1, l, mid);
        T rv = query(a, b, 2*k+2, mid, r);
        return lv + rv;
    }

    void add(size_t a, size_t b, T val, size_t k, size_t l, size_t r) {
        evaluate(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy_[k] += val * (r - l);
            evaluate(k, l, r);
        } else {
            size_t mid = (l+r) / 2;
            add(a, b, val, 2*k+1, l, mid);
            add(a, b, val, 2*k+2, mid, r);
            val_[k] = val_[2*k+1] + val_[2*k+2];
        }
    }

public:
    LazyEvalSegmentTree(size_t n): rsz_(n) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        val_.resize(2*sz_ - 1, 0);
        lazy_.resize(2*sz_ - 1, 0);
    }

    LazyEvalSegmentTree(vector<T> &v): rsz_(v.size()) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        val_.resize(2*sz_ - 1, 0);
        lazy_.resize(2*sz_ - 1, 0);
        for (size_t i = 0; i < rsz_; i++) {
            val_[sz_-1+i] = v[i];
        }
        (void)construct(0);
    }

    // return sum in [a, b)
    T query(size_t a, size_t b) {
        return query(a, b, 0, 0, sz_);
    }

#if 0
    void add(size_t idx, T k) {
        idx += sz_-1;
        val_[idx] = k;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            val_[idx] = min(val_[2*idx+1], val_[2*idx+2]);
        }
    }
#endif

    // add val to each element in [a, b)
    void add(size_t a, size_t b, T val) {
        add(a, b, val, 0, 0, sz_);
    }
};

void solve()
{
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

// vim:set foldmethod=marker:
