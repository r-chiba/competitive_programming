// {{{
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
// }}}

int N;
ll a[100000], b[100000], c[100000];
ll bi[100000];
ll nc[100000];

void init()
{
}

void solve()
{
    sort(a, a+N);
    sort(b, b+N);
    sort(c, c+N);
    ll ans = 0;
    REPR(i, N-1){
        ll cidx = lower_bound(begin(c), begin(c)+N-1, b[i]+1) - c;
        int cn = N - cidx;
        if(cidx == N-1 && c[cidx] <= b[i]) cn = 0;
        nc[i] = cn;
        if(i < N-1) nc[i] += nc[i+1];
    }
    REP(i, N){
        ll bidx = lower_bound(begin(b), begin(b)+N-1, a[i]+1) - b;
        if(bidx == N-1 && b[bidx] <= a[i]) bidx = N;
        if(bidx < N) ans += nc[bidx];
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];
    REP(i, N) cin >> c[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
