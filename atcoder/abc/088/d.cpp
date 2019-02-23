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
int n_white;
char m[50][50];

void init()
{
}

int movable()
{
    int ret = INF;
    queue<IP> q;
    q.push(mp(0, mp(0, 0)));
    while(!q.empty()){
        int d, x, y;
        d = q.front().fi;
        x = q.front().se.fi;
        y = q.front().se.se;
        q.pop();
        if(m[x][y] != '.') continue;
        if(x == h-1 && y == w-1){
            ret = min(ret, d);
        }
        m[x][y] = '-';
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
            if(m[nx][ny] != '.') continue;
            q.push(mp(d+1, mp(nx, ny)));
        }
    }
    if(ret == INF) ret = -1;
    else ret = n_white - ret;
    return ret;
}

void solve()
{
    cout << movable() << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    REP(i, h){
        REP(j, w){
            cin >> m[i][j];
            if(m[i][j] == '.') n_white++;
        }
    }
    n_white--;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
