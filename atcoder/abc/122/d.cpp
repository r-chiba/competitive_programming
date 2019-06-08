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

void solve()
{
    ll ans = 1;
    REP(i, N){
        ans *= 4;
        ans %= MOD;
    }
    ll ng = 1;
    REP(i, N-3){
        ng *= 4;
        ng %= MOD;
    }
    ng *= 3;
    ng %= MOD;
    ll nga = 1;
    REP(i, N-2){
        //nga *= ng;
        //nga %= MOD;
        ng *= 2;
    }
    cout << ans << " " << ng << " " << nga << endl;
    cout << ans - nga << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
