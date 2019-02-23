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
ll N;
ll h[100000], l[100000];
vector<LP> v;

bool condition(ll n)
{
    vector<double> t;
    REP(i, N){
        if(n < h[i]) return false;
        t.pb(static_cast<double>(n - h[i]) / l[i]);
    }
    sort(t.begin(), t.end());
    REP(i, N){
        if(t[i] < i) return false;
    }
    return true;
}

ll binary_search(ll n)
{
    ll lb = 0, ub = n;
    while(ub - lb > 1){
        ll mid = (lb + ub) / 2;
        if(condition(mid)) ub = mid;
        else lb = mid;
    }
    return ub;
}

void init()
{
}

void solve()
{
    cout << binary_search(LINF) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N){
        ll h_, l_;
        cin >> h_ >> l_;
        h[i] = h_;
        l[i] = l_;
        v.pb(LP(h_+(N-1)*l_, i));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
