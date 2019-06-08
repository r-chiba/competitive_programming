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
// }}}

int N, M;
int a[100000], b[100000];
ll parent[100000];
ll connect[100000];

void init()
{
}

void solve()
{
    ll m = N*(N-1)/2;
    vector<ll> ans;
    ans.pb(0);
    REP(i, N-1) parent[i] = i;
    for(ll i = M-1; i > 0; i--){
        int pa = parent[a[i]];
        int pb = parent[b[i]];
        ll cpa = connect[pa];
        ll cpb = connect[pb];
        parent[a[i]] = min(min(pa, pb), a[i]);
        parent[b[i]] = min(min(pa, pb), a[i]);
        ll aa = (parent[a[i]] != pa ? cpa : 0);
        ll ab = (parent[b[i]] != pb ? cpb : 0);
        connect[parent[a[i]]] += aa + ab + 1;
        ans.pb(ans[M-1-i] + (aa+1) * (ab+1));
    }
    for(auto it = ans.rbegin(); it != ans.rend(); it++){
        cout << max(m - *it, 0ll) << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
