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
#define FOR(i, a, b) for(size_t i = static_cast<size_t>(a); i < static_cast<size_t>(b); i++)
#define FORR(i, a, b) for(size_t i = static_cast<size_t>(a); i >= static_cast<size_t>(b); i--)
#define REP(i, n) for(size_t i = 0; i < static_cast<size_t>(n); i++)
#define REPR(i, n) for(size_t i = static_cast<size_t>(n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> IP;
typedef pair<ll, LP> LLP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;
// }}}

int V, E;
struct edge {
    int from, to, cost;
    edge(): from(0), to(0), cost(0) {};
    edge(int f, int t, int c): from(f), to(t), cost(c) {};
};
int d[1000];
edge es[2000];
int s;

bool bellman_ford(int s)
{
    bool ret = true; // doesn't there exist negative loop?
    REP(i, V) d[i] = INF;
    d[s] = 0;
    int loop = 0;
    REP(l, V){
        bool update = false;
        REP(i, E){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
        if(update && l == V-1) ret = false;
    }
    return ret;
}

void init()
{
}

void solve()
{
    bool nl = bellman_ford(s);
    if(nl){
        REP(i, V) cout << (d[i] == INF ? "INF" : to_string(d[i])) << endl;
    }else{
        cout << "NEGATIVE CYCLE" << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> V >> E >> s;
    REP(i, E){
        int p, q, c;
        cin >> p >> q >> c;
        es[i] = edge(p, q, c);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
