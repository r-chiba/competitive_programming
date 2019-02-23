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

int h, w, n;
char m[1000][1000];
P vs[10];

void init()
{
}

int bfs(P &s, P &d)
{
    int ret = INF;
    queue<IP> q;
    q.push(mp(0, s));
    while(!q.empty()){
        int step = q.front().fi;
        P p = q.front().se;
        q.pop();
        if(m[p.fi][p.se] != '.') continue;
        if(p == d){
            ret = min(ret, step);
            continue;
        }
        m[p.fi][p.se] = '-';
        REP(i, 4){
            int nx = p.fi + dx[i];
            int ny = p.se + dy[i];
            if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
            if(m[nx][ny] != '.') continue;
            q.push(mp(step+1, mp(nx, ny)));
        }
    }
    return ret;
}

void solve()
{
    int ans = 0;
    REP(i, n){
        ans += bfs(vs[i], vs[i+1]);
        REP(j, h){
            REP(k, w){
                if(m[j][k] == '-') m[j][k] = '.';
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w >> n;
    REP(i, h){
        REP(j, w){
            char c;
            cin >> c;
            if('0' <= c && c <= '9'){
                vs[c-'0'] = mp(i, j);
                m[i][j] = '.';
            }else if(c == 'S'){
                vs[0] = mp(i, j);
                m[i][j] = '.';
            }else{
                m[i][j] = c;
            }
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
