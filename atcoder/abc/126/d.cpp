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
struct edge {
    int to;
    ll cost;
    edge(int t, ll c): to(t), cost(c) {};
};
vector<edge> g[100010];
ll d[100000];

void dijkstra(int s)
{
    priority_queue<LP, vector<LP>, greater<LP> > q;
    REP(i, N) d[i] = LINF;
    d[s] = 0;
    q.push(make_pair(0ll, s));
    while(!q.empty()){
        LP p = q.top(); q.pop();
        //cout << p.fi << " " << p.se << endl;
        ll v = p.se;
        if(p.first > d[v]) continue;
        for(edge &e: g[v]){
            //cout << v << " " << e.to << " " << e.cost << endl;
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                q.push(mp(d[e.to], e.to));
            }
        }
    }
}

void solve()
{
    //REP(i, N){
    //    for(edge &e: g[i]){
    //        cout << i << " " << e.to << " " << e.cost << endl;
    //    }
    //}
    //cout << endl;
    dijkstra(0);
    REP(i, N){
        if(d[i] % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
        //cout << "\t" << d[i] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N-1){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].pb(edge(v, w));
        g[v].pb(edge(u, w));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
