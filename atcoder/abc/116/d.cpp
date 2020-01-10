// {{{
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
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
#define FOR(i, a, b) for(ll i = static_cast<ll>(a); i < static_cast<ll>(b); i++)
#define FORR(i, a, b) for(ll i = static_cast<ll>(a); i >= static_cast<ll>(b); i--)
#define REP(i, n) for(ll i = 0ll; i < static_cast<ll>(n); i++)
#define REPR(i, n) for(ll i = static_cast<ll>(n); i >= 0ll; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> IP;
typedef pair<ll, LP> LLP;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

constexpr int INF = 100000000;
constexpr ll LINF = 10000000000000000ll;
constexpr int MOD = static_cast<int>(1e9 + 7);
constexpr double EPS = 1e-9;
// }}}

int N, K;
LP s[100000];

void solve()
{
    ll ans = 0, ans1 = 0;
    set<int> ss;
    priority_queue<LP, vector<LP>, greater<LP> > q;

    sort(s, s+N, greater<LP>());
    REP(i, K){
        if(ss.find(s[i].se) == ss.end()){
            ss.insert(s[i].se);
        }else{
            q.push(s[i]);
        }
        ans1 += s[i].fi;
    }
    ans1 += ss.size() * ss.size();
    ans = ans1;
    FOR(i, K, N){
        if(q.size() == 0) break;
        if(ss.find(s[i].se) == ss.end()){
            int sz = ss.size();
            ans1 += 2*sz + 1 - (q.top().fi - s[i].fi);
            ans = max(ans, ans1);
            q.pop();
            ss.insert(s[i].se);
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) cin >> s[i].se >> s[i].fi;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
