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

priority_queue<double> q;
//priority_queue<double, vector<double>, greater<double> > q;

void init()
{
}

void solve()
{
    double ans = 0.0;
    while(q.size() > 1){
        double v1, v2, v;
        v1 = q.top(); q.pop();
        v2 = q.top(); q.pop();
        v = 2. * sqrt(v1 * v2);
        q.push(v);
    }
    printf("%.3lf\n", q.top());
}

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, n){
        double v;
        scanf("%lf", &v);
        q.push(v);
    }
    //REP(i, n){
    //    printf("%lf\n", q.top());
    //    q.pop();
    //}
    solve();

    return 0;
}

// vim:set foldmethod=marker:
