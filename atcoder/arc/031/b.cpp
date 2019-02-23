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

char m[10][10];
int n_land;
P s;
bool init = false;

int dfs(int x, int y)
{
    if(m[x][y] != 'o') return 0;
    int ret = 1;
    m[x][y] = '#';
    REP(i, 4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || 10 <= nx || ny < 0 || 10 <= ny) continue;
        if(m[nx][ny] != 'o') continue;
        ret += dfs(nx, ny);
    }
    return ret;
}

bool connectable(bool first)
{
    int n = dfs(s.fi, s.se);
    if(n < n_land){
        REP(i, 10){
            REP(j, 10){
                if(m[i][j] == '#') m[i][j] = 'o';
            }
        }
    }
    return (first ? n == n_land : n > n_land);
}

void solve()
{
    bool ans = false;
    if(connectable(true)){
        ans = true;
        goto end;
    }
    REP(i, 10){
        REP(j, 10){
            if(m[i][j] == 'x'){
                m[i][j] = 'o';
                ans = ans || connectable(false);
                m[i][j] = 'x';
                if(ans == true) goto end;
            }
        }
    }
end:
    cout << (ans ? "YES" : "NO") << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 10){
        REP(j, 10){
            char c;
            cin >> c;
            if(c == 'o'){
                if(!init) s = mp(i, j);
                n_land++;
            }
            m[i][j] = c;
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
