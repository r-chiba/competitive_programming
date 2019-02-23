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

int n;
int m;
set<int> ss[12];

void print_vec(const vector<int> &v)
{
    int len = v.size();
    REP(i, len) cout << v[i] << " ";
    cout << endl;
}

void init()
{
}

void solve()
{
    int ans = 0;
    REP(i, 1 << n){
        vector<int> v;
        REP(j, n){
            if((i>>j) & 1) v.push_back(j);
        }
        int nn = v.size();
        REP(j, nn){
            FOR(k, j+1, nn){
                if(ss[v[j]].find(v[k]) == ss[v[j]].end()) goto next;
            }
        }
        ans = max(ans, nn);
next:
        ;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        ss[x].insert(y);
        ss[y].insert(x);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
