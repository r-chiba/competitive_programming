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
#if __cplusplus >= 201103
#include <numeric>
#endif
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

//#if __cplusplus >= 201103
typedef long long ll;
//#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
//#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
//#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int n, m;

int adj[100][100];

void init()
{
}

bool dfs(int x, set<int> &s)
{
    bool ret = true;
    s.insert(x);
    REP(i, n){
        if(adj[x][i] == 1){
            if(s.find(i) == s.end()){
                s.insert(i);
                adj[x][i] = adj[i][x] = 0;
                ret = ret && dfs(i, s);
            }else{
                ret = false;
            }
            if(!ret) goto end;
        }
    }
end:
    return ret;
}

void solve()
{
    int ans = 0;
    set<int> s;
    REP(i, n){
        if(s.find(i) == s.end()){
            bool ok = dfs(i, s);
            if(ok) ans++;
            if(s.size() == n) break;
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x][y] = adj[y][x] = 1;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
