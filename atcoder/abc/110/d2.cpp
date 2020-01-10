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

ll N, M;
map<ll, ll> dp;

void prime_factor(ll n, map<ll, ll> &m)
{
    for(ll i = 2; i*i <= n; i++){
        while(n % i == 0){
            m[i]++;
            n /= i;
        }
    }
    if(n != 1) m[n]++;
}

ll rec(ll x, ll i)
{
    cout << x << " " << i << endl;
    if(x == 1 && i >= 0) return 1;
    else if(i <= 0) return 0;
    cout << "\t" << x << " " << i << endl;
    ll ans = 0;
    for(ll j = 1; j*j <= x; j++){
        if(x % j == 0){
            if(j != 1){
                ans += rec(x/j, i-1);
                ans %= MOD;
            }
            if(j != x/j){
                ans += rec(j, i-1);
                ans %= MOD;
            }
        }
    }
    return ans;
}

void solve()
{
    map<ll, ll> m;
    prime_factor(M, m);
    ll n = 0;
    ll ans = 1;
    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->fi << " " << it->se << endl;
        n += it->se;
    }
    REP(i, n){
        ans *= N;
        ans %= MOD;
    }
    cout << ans << endl;
    //cout << (rec(M, N)+1) % MOD << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
