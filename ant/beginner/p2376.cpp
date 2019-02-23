// {{{
#include <iostream>
#include <cmath>
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
#include <cstdio>

int n;
int t;
P cows[25000];

void init()
{
}

void solve()
{
    sort(cows, cows+n);
    int ans = 0;
    int now = 1;
    int i = 0;
    while(now < t){
        int ma = 0;
        while(i < n && cows[i].fi <= now){
            ma = max(ma, cows[i++].se);
        }
        ans++;
        if(i >= n){
            if(ma < t) ans = -1;
            break;
        }
        if(ma == 0){
            ans = -1;
            break;
        }
        now = ma;
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d %d", &n, &t);
    REP(i, n){
        scanf("%d %d", &(cows[i].fi), &(cows[i].se));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
