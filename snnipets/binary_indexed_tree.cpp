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

class BinaryIndexedTree {
    const int n_;
    vector<int> vec_;
public:
    BinaryIndexedTree(int n): n_(n), vec_(n+1, 0) {}

    BinaryIndexedTree(vector<int> &vec): n_(vec.size()), vec_(vec.size()+1, 0) {
        for (int i = 0; i < n_; i++) {
            this->add(i, vec[i]);
        }
    }

    void add(int idx, int val) {
        for (int i = idx+1; i <= n_; i += (i&-i)) {
            vec_[i] += val;
        }
    }

    int sum(int idx) {
        int ret = 0;
        for (int i = idx+1; i >= 1; i -= (i&-i)) {
            ret += vec_[i];
        }
        return ret;
    }

    int sumRange(int l, int r) {
        return sum(r) - sum(l-1);
    }
};

class BinaryIndexedTree2D {
    const int h_, w_;
    vector<vector<int> > mat_;
public:
    BinaryIndexedTree2D(int h, int w): h_(h), w_(w), mat_(h+1, vector<int>(w+1, 0)) {};

    BinaryIndexedTree2D(vector<vector<int> > &mat):
        h_(mat.size()),
        w_(mat[0].size()),
        mat_(mat.size()+1, vector<int>(mat[0].size()+1, 0))
    {
        for (int i = 0; i < h_; i++) {
            for (int j = 0; j < w_; j++) {
                this->add(i, j, mat[i][j]);
            }
        }
    };

    void add(int x, int y, int val) {
        for (int i = x+1; i <= h_; i += (i&-i)) {
            for (int j = y+1; j <= w_; j += (j&-j)) {
                mat_[i][j] += val;
            }
        }
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x+1; i >= 1; i -= (i&-i)) {
            for (int j = y+1; j >= 1; j -= (j&-j)) {
                ret += mat_[i][j];
            }
        }
        return ret;
    }

    int sumRegion(int i1, int j1, int i2, int j2) {
        return sum(i2, j2) - sum(i1-1, j2) - sum(i2, j1-1) + sum(i1-1, j1-1);
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
