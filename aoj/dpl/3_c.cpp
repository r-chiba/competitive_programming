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

int N;
ll h[100001];

void solve()
{
    ll ans = 0;
    stack<pair<ll, int> > s;
    REP(i, N+1) {
        if (s.empty()) {
            s.push(make_pair(h[i], i));
        } else {
            auto &p = s.top();
            if (p.fi < h[i]) {
                s.push(make_pair(h[i], i));
            } else if (p.fi == h[i]) {
                ;
            } else {
                int li = i;
                while (true) {
                    if (s.empty() || s.top().fi <= h[i]) {
                        s.push(make_pair(h[i], li));
                        break;
                    }
                    //cout << i << ": " << s.top().fi << " " << (i - s.top().se) << endl;
                    li = s.top().se;
                    ans = max(ans, s.top().fi * (i - li));
                    s.pop();
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) cin >> h[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
