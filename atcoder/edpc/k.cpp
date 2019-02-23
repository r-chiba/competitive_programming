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

int N, K;
int a[100];
int m[100001][2];

void init()
{
}

int rec(int v, int t)
{
    if(v < 0) return (t == 0 ? 1 : 0);
    if(m[v][t] != -1) return m[v][t];
    if(v == 0) return m[v][t] = (t == 0 ? 0 : 1);

    int ret = -1;
    if(t == 0){
        REP(i, N){
            if(rec(v-a[i], (t+1)%2) == 1){
                ret = 1;
                break;
            }
        }
        if(ret == -1) ret = 0;
    }else{
        REP(i, N){
            if(rec(v-a[i], (t+1)%2) == 0){
                ret = 0;
                break;
            }
        }
        if(ret == -1) ret = 1;
    }

    return m[v][t] = ret;
}

void solve()
{
    REP(i, K+1) REP(j, 2) m[i][j] = -1;
    cout << (rec(K, 0) == 1 ? "First" : "Second") << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) cin >> a[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
