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

#if __cplusplus
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

class Compare
{
public:
    bool operator()(const P &lhs, const P &rhs){
        //if(lhs.se < rhs.se
        //    || (lhs.se == rhs.se && lhs.fi > rhs.fi))
        if(2*rhs.fi*lhs.se < 2*lhs.fi*rhs.se)
            return true;
        return false;
    }
};

priority_queue<P, vector<P>, Compare> q;

void init()
{
}

void solve()
{
    ll ans = 0ll;
    ll t = 0ll;
    while(!q.empty()){
        const P &p = q.top();
        ans += t * p.se;
        t += 2ll * p.fi;
        q.pop();
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
     cin >> n;
     REP(i, n){
         int t, d;
         cin >> t >> d;
         q.push(mp(t, d));
     }
     //REP(i, n){
     //    const P &p = q.top();
     //    cout << p.fi << " " << p.se << endl;
     //    q.pop();
     //}
     solve();
    return 0;
}

// vim:set foldmethod=marker:
