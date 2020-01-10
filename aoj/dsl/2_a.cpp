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

int n, q;

class SegmentTree {
    int sz_, rsz_;
    vector<int> v_;

    int construct(int idx) {
        if (idx >= sz_-1) return v_[idx];
        return v_[idx] = min(construct(2*idx+1), construct(2*idx+2));
    }

    int query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INT_MAX;
        if (a <= l && r <= b) return v_[k];
        int mid = (l+r) / 2;
        int lv = query(a, b, 2*k+1, l, mid);
        int rv = query(a, b, 2*k+2, mid, r);
        return min(lv, rv);
    }

public:
    SegmentTree(int n): rsz_(n) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        v_.resize(2*sz_ - 1, INT_MAX);
    }

    SegmentTree(vector<int> &v): rsz_(v.size()) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        v_.resize(2*sz_ - 1, INT_MAX);
        for (int i = 0; i < rsz_; i++) {
            v_[sz_-1+i] = v[i];
        }
        (void)construct(0);
    }

    // return min value in [a, b)
    int query(int a, int b) {
        return query(a, b, 0, 0, sz_);
    }

    void update(int idx, int k) {
        idx += sz_-1;
        v_[idx] = k;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            v_[idx] = min(v_[2*idx+1], v_[2*idx+2]);
        }
    }

    void print() {
        int vsz = v_.size();
        cout << "[ ";
        for(int i = 0; i < vsz; i++) {
            cout << v_[i] << " ";
        }
        cout << "]" << endl;;
    }

};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    SegmentTree st(n);
    for (int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            st.update(x, y);
        } else {
            cout << st.query(x, y+1) << endl;
        }
    }

    return 0;
}

// vim:set foldmethod=marker:
