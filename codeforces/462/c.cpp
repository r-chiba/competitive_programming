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

int n;
vector<ll> v;

void init()
{
}

void solve()
{
    ll ans = 0;
    int depth = 1;
    sort(v.begin(), v.end());
    vector<ll>::iterator it = v.begin();
    vector<ll>::iterator e = v.end();
    while(it != e){
        //if(it+1 != e) ans += *it;
        //ans += accumulate(it, e, 0);
        ans += depth * *it;
        if(it+1 != e) ans += *it;
        depth++; it++;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n){
        ll a;
        cin >> a;
        v.pb(a);
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
