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

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (auto e: v) os << e << ",";
    os << "]";
    return os;
}

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

// print floating-point number
// cout << fixed << setprecision(12) <<

// }}}

int N, K;
string s;

void solve()
{
    ll ans1 = 0, ans2 = 0;
    int l = -1, t = 0;
    bool reverse = false;
    REP (i, N) {
        if (s[i] == 'R') {
            if (l == -1 && t < K) {
                l = i;
                reverse = true;
            }
        } else {
            if (i > 0 && (s[i] == s[i-1] || reverse)) ans1++;
            if (l != -1) {
                ans1 += i - l;
                l = -1;
                t++;
            }
            reverse = false;
        }
    }
    if (l != -1) {
        ans1 += N - l;
    }
    l = -1;
    t = 0;
    reverse = false;
    REPR (i, N-1) {
        if (s[i] == 'L') {
            if (l == -1 && t < K) {
                l = i;
                reverse = true;
            }
        } else {
            if (i < N-1 && (s[i] == s[i+1] || reverse)) ans2++;
            if (l != -1) {
                ans2 += l - i;
                l = -1;
                t++;
            }
            reverse = false;
        }
    }
    if (l != -1) {
        ans2 += l+1;
    }
    cout << max(ans1, ans2) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    cin >> s;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
