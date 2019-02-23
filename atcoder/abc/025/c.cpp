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
#include <numeric>
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

int m[5][5];
int b[2][3];
int c[3][2];
int s;

void init()
{
}

int score()
{
    int ret = 0;
    REP(i, 3){
        REP(j, 3){
           if(0 <= i && i <= 1 && 0 <= j && j <= 2){
               if(m[i][j] == m[i+1][j]) ret += b[i][j];
           }
           if(0 <= i && i <= 2 && 0 <= j && j <= 1){
               if(m[i][j] == m[i][j+1]) ret += c[i][j];
           }
        }
    }
    return ret;
}

int rec(int count)
{
    if(count == 9) return score();

    int turn = (count % 2 == 0) ? 1 : -1;
    int ret = (turn == 1) ? 0 : INF;
    REP(i, 3){
        REP(j, 3){
            if(m[i][j] != 0) continue;
            if(turn == 1){
                m[i][j] = 1;
                ret = max(ret, rec(count+1));
                m[i][j] = 0;
            }else{
                m[i][j] = -1;
                ret = min(ret, rec(count+1));
                m[i][j] = 0;
            }
        }
    }
    return ret;
}

void solve()
{
    int first = rec(0);
    cout << first << endl;
    cout << s - first << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 2){
        REP(j, 3){
            cin >> b[i][j];
            s += b[i][j];
        }
    }
    REP(i, 3){
        REP(j, 2){
            cin >> c[i][j];
            s += c[i][j];
        }
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
