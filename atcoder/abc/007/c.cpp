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

int r, c;
P s, g;
char m[50][50];

void init()
{
}

void solve()
{
    int ans = INF;
    queue<IP> q;
    q.push(mp(0, s));
    while(!q.empty()){
        int n = q.front().fi;
        P p = q.front().se;
        q.pop();
        if(m[p.fi][p.se] == '#') continue;
        if(p == g){
            ans = min(ans, n);
            continue;
        }
        m[p.fi][p.se] = '#';
        REP(i, 4){
            int nx = p.fi + dx[i];
            int ny = p.se + dy[i];
            if(nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
            if(m[nx][ny] == '#') continue;
            q.push(mp(n+1, mp(nx, ny)));
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> r >> c;
    cin >> s.fi >> s.se;
    cin >> g.fi >> g.se;
    s.fi--; s.se--;
    g.fi--; g.se--;
    REP(i, r){
        REP(j, c){
            cin >> m[i][j];
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
