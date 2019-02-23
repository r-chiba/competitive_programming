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
char m[500][500];
P s, g;

void init()
{
}

bool reachable()
{
    queue<IP> q;
    q.push(mp(0, s));
    while(!q.empty()){
        int d = q.front().fi;
        int x = q.front().se.fi;
        int y = q.front().se.se;
        q.pop();
        if(m[x][y] <= d || (d == 2 && m[x][y] == '#')) continue;
        if(mp(x, y) == g) return true;
        if(m[x][y] != '#') m[x][y] = d;
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
            q.push(mp(m[x][y] == '#' ? d+1 : d, mp(nx, ny)));
        }
    }
    return false;
}

void solve()
{
    cout << (reachable() ? "YES" : "NO") << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    REP(i, h){
        REP(j, w){
            char c;
            cin >> c;
            if(c == 's'){
                s = mp(i, j);
                c = '.';
            }
            if(c == 'g'){
                g = mp(i, j);
                c = '.';
            }
            m[i][j] = c;
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
