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

class SegmentTree {
    size_t sz_, rsz_;
    vector<ll> v_;

    int construct(size_t idx) {
        if (idx >= sz_-1) return v_[idx];
        return v_[idx] = max(construct(2*idx+1), construct(2*idx+2));
    }

    ll query(size_t a, size_t b, size_t k, size_t l, size_t r) {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return v_[k];
        size_t mid = (l+r) / 2;
        ll lv = query(a, b, 2*k+1, l, mid);
        ll rv = query(a, b, 2*k+2, mid, r);
        return max(lv, rv);
    }

public:
    SegmentTree(size_t n): rsz_(n) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        v_.resize(2*sz_ - 1, 0);
    }

    SegmentTree(vector<ll> &v): rsz_(v.size()) {
        sz_ = 1;
        while (sz_ < rsz_) sz_ *= 2;
        v_.resize(2*sz_ - 1, 0);
        for (size_t i = 0; i < rsz_; i++) {
            v_[sz_-1+i] = v[i];
        }
        (void)construct(0);
    }

    // return min value in [a, b)
    ll query(size_t a, size_t b) {
        return query(a, b, 0, 0, sz_);
    }

    void update(size_t idx, ll k) {
        idx += sz_-1;
        v_[idx] = k;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            v_[idx] = max(v_[2*idx+1], v_[2*idx+2]);
        }
    }

    void print() {
        size_t vsz = v_.size();
        for(size_t i = 0; i < vsz; i++) {
            cout << v_[i] << " ";
        }
        cout << endl;
    }

};

int N;
ll h[200010], a[200010];

void solve()
{
    ll hm = 0;
    REP (i, N) hm = max(hm, h[i]);
    SegmentTree st(hm+1);
    REP (i, N) {
        ll val = max(st.query(h[i], h[i]+1), st.query(0, h[i])+a[i]);
        st.update(h[i], val);
    }
    cout << st.query(0, hm+1) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP (i, N) cin >> h[i];
    REP (i, N) cin >> a[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
