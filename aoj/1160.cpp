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

int h, w;
int m[50][50];

void init()
{
}

void dfs(int x, int y)
{
    int ddx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int ddy[] = {0, 1, 0, -1, 1, -1, 1, -1};
    m[x][y] = 0;
    REP(i, 8){
        int nx = x + ddx[i];
        int ny = y + ddy[i];
        if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
        if(m[nx][ny] == 0) continue;
        dfs(nx, ny);
    }
}

void solve()
{
    int ans = 0;
    REP(i, h){
        REP(j, w){
            if(m[i][j] == 1){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        REP(i, h){
            REP(j, w){
                cin >> m[i][j];
            }
        }
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker:
