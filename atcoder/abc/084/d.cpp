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

int Q;
int l[100001], r[100001];
bool prime[100001];
bool prime2017[100001];
int n_prime2017[100001];
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

void init()
{
}

void solve()
{
    sieve(100000);
    FOR(i, 3, 100001){
        if(prime[i] && prime[(i+1)/2]) prime2017[i] = true;
    }
    REP(i, 100001){
        n_prime2017[i+1] = n_prime2017[i];
        if(prime2017[i+1]) n_prime2017[i+1]++;
    }
    REP(i, Q){
        cout << n_prime2017[r[i]] - n_prime2017[l[i]-1] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> Q;
    REP(i, Q){
        cin >> l[i] >> r[i];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
