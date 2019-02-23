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

ll N, K;
ll w[1000], p[1000];

bool condition(double n)
{
    vector<double> v;
    REP(i, N) v.pb(p[i]*w[i] - n*w[i]);
    sort(ALL(v), greater<double>());
    double sum = 0;
    REP(i, K) sum += v[i];
    return sum >= 0;
}

double binary_search(ll l, ll u)
{
    double lb = l, ub = u;
    REP(i, 100){
        double mid = (lb + ub) / 2;
        if(condition(mid)) lb = mid;
        else ub = mid;
    }
    return lb;
}

void init()
{
}

void solve()
{
    cout << fixed;
    cout << setprecision(10) << binary_search(0, LINF) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N){
        cin >> w[i] >> p[i];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
