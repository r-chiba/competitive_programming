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

int N;
ll M;
ll a[100010];
ll s[100010];

void init()
{
}

void solve()
{
    ll ans = 0;
    s[0] = a[0] % M;
    FOR(i, 1, N) s[i] = (s[i-1] + a[i]) % M;
    ll sub = 0;
    REP(i, N){
        //int n = 1;
        //while(n*M + sub <= s[N-1]){
        //    ans += upper_bound(s+i, s+N, n*M+sub) - lower_bound(s+i, s+N, n*M+sub);
        //    n++;
        //}
        ans += upper_bound(s+i, s+N, sub) - lower_bound(s+i, s+N, sub);
        sub += a[i];
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N){
        cin >> a[i];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
