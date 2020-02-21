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

string s;
int K;
ll dp[110][2][10];

void solve()
{
    auto sz = s.size();
    dp[0][0][0] = 1;
    REP (i, sz) {
        int d = s[i] - '0';
        REP (j, 4) {
            FOR (k, 0, 10) {
                dp[i+1][1][j+(k != 0 ? 1 : 0)] += dp[i][1][j];
                if (k <= d) dp[i+1][(d > k ? 1 : 0)][j+(k != 0 ? 1 : 0)] += dp[i][0][j];
            }
        }
    }
    cout << dp[sz][0][K] + dp[sz][1][K] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> K;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
