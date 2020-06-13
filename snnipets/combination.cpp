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

void permutation(vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  do{

  }while(next_permutation(arr.begin(), arr.end()));
}

// use this if n and k are small (e.g. 1 <= k <= n <= 2000)
// pascal's triangle
// comb[n][k] = nCk (mod MOD)
const int COMB_MAX = 2000;
ll comb[COMB_MAX][COMB_MAX];
void combination()
{
    comb[0][0] = 1ll;
    FOR(i, 1, COMB_MAX){
        FOR(j, 1, COMB_MAX){
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }
}
// use this if n is fixed and too big (<= 10^9) and k is relatively small (k ~ 10^7)
// O(k)
ll comb[200010];
void combInit(ll n, ll maxk, ll mod) {
    comb[0] = 1;
    FOR (k, 1, maxk+1) {
        comb[k] = comb[k-1];
        comb[k] *= (n - k + 1);
        comb[k] %= mod;
        comb[k] *= mod_inverse(k, MOD);
        comb[k] %= mod;
    }
}
// use this if above conditions are not met
// O(n)
constexpr int COMB_MAX = 510000;
ll fac[COMB_MAX];   // fac[i]  = i!        (mod MOD)
ll finv[COMB_MAX];  // finv[i] = (i!)^{-1} (mod MOD)
ll inv[COMB_MAX];   // inv[i]  = i^{-1}    (mod MOD)

void combInit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR(i, 2, COMB_MAX){
        fac[i] = fac[i-1] * i % MOD;
        // i^{-1} (mod p) = -(p mod i)^{-1} * (p/i) (mod p)
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll comb(int n, int k)
{
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

void solve()
{
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

// vim:set foldmethod=marker:
