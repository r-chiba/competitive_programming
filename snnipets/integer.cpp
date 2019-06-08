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

ll gcd(ll a, ll b)
{
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll gcd(vector<ll> v)
{
    size_t s = v.size();
    if(s == 0) return -1;
    if(s == 1) return v[0];
    ll ret = gcd(v[0], v[1]);
    FOR(i, 2, s){
        ret = gcd(ret, v[i]);
    }
    return ret;
}

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if(a < b) swap(a, b);
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll q = a / b;
    ll g = extgcd(b, a - q*b, x, y);
    ll z = x - q*y;
    x = y;
    y = z;
    return g;
}

// return a^{-1} mod m
// a and m must be co-prime
ll mod_inverse(ll a, ll m)
{
    ll x, y;
    extgdc(a, m, x, y);
    x %= m;
    if(x < 0) x += m;
    return x;
}

inline ll lcm(ll a, ll b)
{
    // a*b may be overflowed
    return a / gcd(a, b) * b;
}

ll lcm(vector<ll> v)
{
    size_t s = v.size();
    ll ret = 1ll;
    REP(i, s){
        if(ans % v[i] != 0) ans = lcm(ans, v[i]);
    }
    return ret;
}

bool is_prime(ll n)
{
    if(n == 1) return false;
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            ret.pb(i);
            if(i != n/i) ret.pb(n/i);
        }
    }
    return ret;
}

map<ll, ll> prime_factor(ll n)
{
    map<ll, ll> ret;
    for(ll i = 2; i*i <= n; i++){
        while(n % i == 0){
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n]++;
    return ret;
}

bool prime[100000];
void sieve(ll n)
{
    REP(i, n+1) prime[i] = true;
    prime[0] = prime[1] = false;
    FOR(i, 2, n+1){
        if(prime[i]){
            for(ll j = 2*i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
}

bool prime[100000];
// find primes in [a, b)
void segment_sieve(ll a, ll b)
{
    vector<bool> prime_small(static_cast<ll>(floor(sqrt(b)))+1);
    ll s = prime_small.size();
    REP(i, b-a)prime[i] = true;
    REP(i, s)prime_small[i] = true;
    for(ll i = 2; i*i < b; i++){
        if(prime_small[i]){
            for(ll j = 2*i; j*j < b; j += i) prime[j] = false;
            for(ll j = max(2ll, (a+i-1)/i)*i;; j < b; j += i) prime[j-a] = false;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}

// vim:set foldmethod=marker:
