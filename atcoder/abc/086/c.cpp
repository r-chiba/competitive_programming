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

int N;
int t[100001], x[100001], y[100001];

void init()
{
}

void solve()
{
    bool ok = true;
    FOR(i, 1, N+1){
        int dt = t[i] - t[i-1];
        int dx = abs(x[i] - x[i-1]);
        int dy = abs(y[i] - y[i-1]);
        if(dt < dx+dy || ((dx+dy)-dt) % 2 != 0){
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    FOR(i, 1, N+1) cin >> t[i] >> x[i] >> y[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
