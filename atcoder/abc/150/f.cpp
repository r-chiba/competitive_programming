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

int N;
unsigned a[200010], b[200010];

void solve()
{
    unsigned x = 0;
    REP (k, N) {
        unsigned x = a[k] ^ b[0];
        //cout << bitset<30>(a[k]) << endl;
        //cout << bitset<30>(b[0]) << endl;
        //cout << bitset<30>(x) << endl;
        bool ok = true;
        REP (i, N) {
            if ((a[(i+k)%N]^x) != b[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << k << " " << x << endl;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP (i, N) cin >> a[i];
    REP (i, N) cin >> b[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
