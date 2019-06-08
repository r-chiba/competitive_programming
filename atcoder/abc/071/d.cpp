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
string s[2];
int m[2][52];
vector<int> g[52];
int c[52];

void init()
{
}

bool isAlpha(int c)
{
  return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ? true : false);
}

void createGraph()
{
    int v = 0;
    REP(i, 2) REP(j, N) m[i][j] = s[i][j];
    REP(i, 2){
        REP(j, N){
            bool addv = false;
            if(isAlpha(m[i][j])){
                if(j < N-1 && m[i][j] == m[i][j+1]){
                    m[i][j] = m[i][j+1] = v;
                }
                else if(i < 1 && m[i][j] == m[i+1][j]){
                    m[i][j] = m[i+1][j] = v;
                }
                addv = true;
            }
            if(i > 0 && !isAlpha(m[i-1][j]) && m[i-1][j] != m[i][j]
               && find(ALL(g[m[i][j]]), m[i-1][j]) == g[m[i][j]].end()){
                g[m[i][j]].pb(m[i-1][j]);
                g[m[i-1][j]].pb(m[i][j]);
            }
            if(j > 0 && !isAlpha(m[i][j-1]) && m[i][j-1] != m[i][j]
               && find(ALL(g[m[i][j]]), m[i][j-1]) == g[m[i][j]].end()){
                g[m[i][j]].pb(m[i][j-1]);
                g[m[i][j-1]].pb(m[i][j]);
            }
            if(i < 1 && !isAlpha(m[i+1][j]) && m[i+1][j] != m[i][j]
                && find(ALL(g[m[i][j]]), m[i+1][j]) == g[m[i][j]].end()){
                g[m[i][j]].pb(m[i+1][j]);
                g[m[i+1][j]].pb(m[i][j]);
            }
            if(j < N-1 && !isAlpha(m[i][j+1]) && m[i][j+1] != m[i][j]
               && find(ALL(g[m[i][j]]), m[i][j+1]) == g[m[i][j]].end()){
                g[m[i][j]].pb(m[i][j+1]);
                g[m[i][j+1]].pb(m[i][j]);
            }
            if(addv) v++;
        }
    }
}

ll rec(int v, int prev)
{
    //cout << v << " " << prev << endl;
    ll ans = 0;
    bool col[] = {false, true, true, true};
    bool move = false;
    for(int neighbor: g[v]){
        if(c[neighbor] != 0){
            col[c[neighbor]] = false;
            continue;
        }else{
            move = true;
        }
    }
    if(move){
        for(int next: g[v]){
            if(c[next] == 0){
                FOR(i, 1, 4){
                    if(col[i]){
                        c[v] = i;
                        ans += rec(next, v);
                        ans %= MOD;
                        c[v] = 0;
                        //break;
                    }
                }
                //int n = 0;
                //FOR(i, 1, 4) if(col[i]) n++;
                //return n * ans;
                break;
            }
        }
    }else{
        FOR(i, 1, 4){
            if(col[i]) ans++;
        }
        cout << ans << endl;
    }
    return ans;
}

void solve()
{
    createGraph();
    REP(i, N){
        cout << i << ": ";
        for(int x: g[i]) cout << x << " ";
        cout << endl;
    }
    cout << rec(0, -1) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> s[0] >> s[1];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
