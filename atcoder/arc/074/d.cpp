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
ll a[300010];
ll f[100010];
ll s[100010];

void init()
{
}

void solve()
{
    priority_queue<ll, vector<ll>, greater<ll> > first;
    priority_queue<ll> second;
    REP(i, N){
        f[0] += a[i];
        first.push(a[i]);
        s[N] += a[3*N-1-i];
        second.push(a[3*N-1-i]);
    }

    FOR(k, 1, N+1){
        f[k] = f[k-1] + a[N-1+k];
        first.push(a[N-1+k]);
        f[k] -= first.top();
        //cout << "first: push " << a[N-1+k] << ", pop " << first.top() << endl;
        first.pop();

        s[N-k] = s[N+1-k] + a[2*N-k];
        second.push(a[2*N-k]);
        s[N-k] -= second.top();
        //cout << "second: push " << a[2*N-k] << ", pop " << second.top() << endl;
        second.pop();

    }
    
    ll ans = -LINF;
    REP(k, N+1){
        //cout << f[k] << " " << s[k] << endl;
        ans = max(ans, f[k]-s[k]);
    }

    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, 3*N){
        cin >> a[i];
        //cout << a[i] << " ";
    }
    //cout << endl;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
