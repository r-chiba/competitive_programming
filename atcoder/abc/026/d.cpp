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

double A, B, C;

inline double equation(double t)
{
    return A*t + B*sin(C*M_PI*t) - 100.;
}

double bisection(double l, double u, int iter)
{
    double lb = l, ub = u;
    REP(i, iter){
        double mid = (lb + ub) / 2;
        double v = equation(mid);
        if(v < 0) lb = mid;
        else if(v > 0) ub = mid;
        else return mid;
    }
    return ub;
}

void init()
{
}

void solve()
{
    double ub = 100.;
    while(equation(ub) <= 0) ub *= 10.;
    double ans = bisection(0.0, ub, 500);
    cout << fixed;
    cout << setprecision(15) << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> B >> C;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
