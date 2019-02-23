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

ll N, K;
vector<ll> a, b;

bool condition(ll n)
{
    ll le = 0;
    REP(i, N){
        ll lb = -1, ub = N-1;
        ll v = upper_bound(b.begin(), b.end(), n/a[i]) - b.begin();
        if(v == N-1 && b[N-1] <= n/a[i]) v = N;
        le += v;
    }
    return le >= K;
}

ll binary_search()
{
    ll lb = 0, ub = a[N-1]*b[N-1];
    while(ub - lb > 1){
        ll mid = (lb + ub) / 2;
        if(condition(mid)) ub = mid;
        else lb = mid;
    }
    return ub;
}

void init()
{
}

void solve()
{
    sort(ALL(a));
    sort(ALL(b));
    cout << binary_search() << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    a.resize(N);
    b.resize(N);
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
