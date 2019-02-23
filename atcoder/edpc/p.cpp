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

int N;
vector<int> e[100000];
ll m[100000][2];

void init()
{
}

ll rec(int v, int prev, int c)
{
    if((e[v].size() == 0)
       || (e[v].size() == 1 && prev != -1)){
        return 1;
    }
    if(prev != -1 && m[v][c] != -1) return m[v][c];
    ll ret = 1;
    for(auto next: e[v]){
        if(next == prev) continue;
        ll s = 0;
        s += rec(next, v, 0);
        s %= MOD;
        if(c == 0) s += rec(next, v, 1);
        s %= MOD;
        ret *= s;
        ret %= MOD;
    }
    m[v][c] = ret;
    return ret;
}

void solve()
{
    REP(i, N) REP(j, 2) m[i][j] = -1;
    cout << (rec(0, -1, 0) + rec(0, -1, 1)) % MOD << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N-1){
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        e[v1].pb(v2);
        e[v2].pb(v1);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
