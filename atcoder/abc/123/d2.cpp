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

int X, Y, Z, K;
ll a[1000], b[1000], c[1000];

void solve()
{
    vector<ll> v;
    REP(i, X){
        REP(j, Y){
            v.pb(a[i] + b[j]);
        }
    }
    sort(ALL(v), greater<ll>());
    sort(c, c+Z, greater<ll>());
    //priority_queue<ll, vector<ll>, greater<ll> > q;
    priority_queue<ll> q;
    REP(i, min(K, X*Y)){
        REP(j, min(K, Z)){
            q.push(v[i] + c[j]);
        }
    }
    REP(i, K){
        cout << q.top() << endl;
        q.pop();
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> X >> Y >> Z >> K;
    REP(i, X) cin >> a[i];
    REP(i, Y) cin >> b[i];
    REP(i, Z) cin >> c[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
