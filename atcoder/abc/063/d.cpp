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


ll N, a, b;
ll h[100000];
ll ans = 0;

class Compare
{
public:
    bool operator()(const LP &lhs, const LP &rhs){
        //if(lhs.fi - ans * b - lhs.se * (a-b) < rhs.fi - ans * b - rhs.se * (a-b))
        if(lhs.fi - lhs.se * (a-b) < rhs.fi - rhs.se * (a-b))
            return true;
        return false;
    }
};

void init()
{
}

void solve()
{
    priority_queue<LP, vector<LP>, Compare> q; 
    REP(i, N) q.push(mp(h[i], 0ll));
    while(true){
        LP p = q.top();
        q.pop();
        if(p.fi - ans * b - p.se * (a-b) <= 0) break;
        ans++;
        q.push(mp(p.fi, p.se+1));
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> a >> b;
    REP(i, N) cin >> h[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
