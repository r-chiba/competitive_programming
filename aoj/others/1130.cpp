#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define pb(a) push_back(a)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
const ll LINF = 10000000000000000ll;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

char field[20][20];
int w, h;
P s;

void init()
{
    REP(i, 20){
        REP(j, 20){
            field[i][j] = '#';
        }
    }
}

int dfs(int x, int y)
{
    if(x < 0 || h <= x || y < 0 || w <= y) return 0;
    if(field[x][y] == '#') return 0;
    field[x][y] = '#';
    int ret = 1;
    REP(i, 4){
        REP(j, 4){
            ret += dfs(x+dx[i], y + dy[i]);
        }
    }
    return ret;
}

void solve()
{
    cout << dfs(s.first, s.second) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        init();
        REP(i, h){
            REP(j, w){
                char c;
                cin >> c;
                if(c == '@'){
                    s = P(i, j);
                }
                field[i][j] = c;
            }
        }
        solve();
    }
    return 0;
}
