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

int N;

void solve()
{
    int ans = 0;
    int fn, ln, dn = 1;
    ln = N % 10;
    int ni = N;
    while (ni >= 10){
        ni /= 10;
        dn++;
    }
    fn = ni;
    int nm = (dn > 2 ? stoi(to_string(N).substr(1, dn-2), nullptr, 10) : 1);
    FOR (i, 1, N+1) {
        int f, l, d = 1;
        l = i % 10;
        if (l == 0) continue;
        int j = i;
        while (j >= 10){
            j /= 10;
            d++;
        }
        f = j;
        cout << i << " " << f << " " << l << " " << d << endl;
        int a = 0;
        if (d == 1 && l == f) {
            int x = l;
            while (x <= N) {
                a++;
                x = x*10 + l;
            }
        } else if (dn >= 2) {
            a += (l == f ? 1 : 0);
            FOR (k, 0, dn-2) {
                a += pow(10, k);
            }
            if (l < fn) a += pow(10, dn-2);
            else if (l == fn) a += nm - (f <= ln ? 0 : 1);
        }
        cout << i << "!" << a << endl;
        ans += a;
        //}
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
