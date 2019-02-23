// {{{
#include <iostream>
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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int M;
//IP meteors[50000];
int field[300][300];

void init()
{
    REP(i, 300){
        REP(j, 300){
            field[i][j] = INF;
        }
    }
}

int solve()
{
    queue<IP> q;
    q.push(mp(0, mp(0, 0)));
    while(!q.empty()){
        IP state = q.front();
        q.pop();
        int t = state.fi;
        int x = state.se.fi;
        int y = state.se.se;
        if(x < 0 || 300 <= x || y < 0 || 300 <= y) continue;
        if(field[x][y] <= t) continue;
        if(field[x][y] > 1000){
            return t;
        }
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || 300 <= nx || ny < 0 || 300 <= ny) continue;
            if(field[nx][ny] <= t+1) continue;
            q.push(mp(t+1, mp(nx, ny)));
        }
    }

    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    init();
    cin >> M;
    REP(i, M){
        int x, y, t;
        cin >> x >> y >> t;
        //meteors[i] = mp(t, mp(x, y));
        field[x][y] = min(field[x][y], t);
        REP(j, 4){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 0 || 300 <= nx || ny < 0 || 300 <= ny) continue;
            field[nx][ny] = min(field[nx][ny], t);
        }
    }
    cout << solve() << endl;

    return 0;
}

// vim:set foldmethod=marker:
