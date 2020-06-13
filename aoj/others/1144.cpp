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
using namespace std;

#define pb push_back
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
const ll LINF = 10000000000000000ll;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int w, h;
int field[20][20];
P s, g;

void init()
{
    REP(i, 20) REP(j, 20) field[i][j] = 1;
}

int dfs(int x, int y, int d)
{
    if(d > 10) return 100;
    //cout << x << " " << y << " " << d << endl;
    if(make_pair(x, y) == g) return 0;

    int ret = 100;
    REP(i, 4){
        int nx = x, ny = y;
        bool in = true;
        bool collesion = false;
        while(true){
            nx += dx[i];
            ny += dy[i];
            if(make_pair(nx, ny) == g) break;
            else if(nx < 0 || h <= nx || ny < 0 || w <= ny){
                in = false;
                break;
            }
            else if(field[nx][ny] == 1){
                collesion = true;
                nx -= dx[i];
                ny -= dy[i];
                break;
            }
        }
        if(in && (nx != x || ny != y)){
            if(collesion) field[nx+dx[i]][ny+dy[i]] = 0;
            ret = min(ret, dfs(nx, ny, d+1) + 1);
            if(collesion) field[nx+dx[i]][ny+dy[i]] = 1;
        }
    }
    return ret;
}

void solve()
{
    int m = dfs(s.first, s.second, 0);
    cout << (m <= 10 ? m : -1) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(cin >> w >> h, w != 0 && h != 0){
        REP(i, h){
            REP(j, w){
                cin >> field[i][j];
                if(field[i][j] == 2) s = make_pair(i, j);
                else if(field[i][j] == 3) g = make_pair(i, j);
            }
        }
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker:
