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
char grid[50][50];

void init()
{
}

void solve()
{
    bool ans = true;
    REP(i, h){
        REP(j, w){
            if(grid[i][j] == '.') continue;
            REP(k, 4){
                if(i+dx[k] < 0 || h <= i+dx[k] || j+dy[k] < 0 || w <= j+dy[k]) continue;
                if(grid[i+dx[k]][j+dy[k]] == '#') goto next;
            }
            ans = false;
next:
            if(!ans) goto end;
        }
    }
end:
    cout << (ans ? "Yes" : "No") << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    REP(i, h){
        REP(j, w){
            cin >> grid[i][j];
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker: