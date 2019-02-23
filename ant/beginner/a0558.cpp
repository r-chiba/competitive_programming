// {{{
#include <iostream>
#include <iomanip>
#include <cmath>
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

#if __cplusplus >= 201103
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;
typedef pair<P, P> PP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int h, w, n;
char field[1000][1000];
int md[1000][1000];
P s;

void solve()
{
    int ans = 0;
    FOR(i, 1, n+1){
        REP(j, h) REP(k, w) md[j][k] = INF;
        int ans_i = INF;
        queue<IP> q;
        q.push(mp(0, s));
        while(!q.empty()){
            IP &ip = q.front();
            q.pop();
            int d = ip.fi;
            P p = ip.se;
            md[p.fi][p.se] = d;
            if(field[p.fi][p.se] == '0'+i){
                ans_i = min(ans_i, d);
                s = p;
                continue;
            }
            REP(j, 4){
                int nx = p.fi + dx[j];
                int ny = p.se + dy[j];
                if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
                if(field[nx][ny] == 'X') continue;
                if(md[nx][ny] <= d) continue;
                q.push(mp(d+1, mp(nx, ny)));
            }
        }
        //if(i == 6){
        //    REP(k, h){
        //        REP(l, w){
        //            if(md[k][l] == INF) md[k][l] = 99;
        //            cout << setfill('0') << setw(2) << right << md[k][l] << " ";
        //        }
        //        cout << endl;
        //    }
        //}
        //cout << ans_i << endl;
        ans += ans_i;
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
            cin >> field[i][j];
            if(field[i][j] == 'S') s = mp(i, j);
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
