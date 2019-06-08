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
vector<int> g[100000];
int c[100000];
vector<int> black, white;

void init()
{
}

void solve()
{
    c[0] = 1;
    c[N-1] = -1;
    black.pb(0);
    white.pb(N-1);
    int i = 0;
    while(true){
        vector<int> &v = (i % 2 == 0 ? black : white);
        int next = -1;
        for(int e: v){
            for(int n: g[e]){
                if(c[n] == 0 && (next != -1 || g[n].size() > g[next].size())){
                    next = n;
                }
            }
        }
        if(next == -1) break;
        c[next] = (i % 2 == 0 ? 1 : -1);
        v.pb(next);
        i++;
    }
    cout << (i % 2 == 0 ? "Snuke" : "Fennec") << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
