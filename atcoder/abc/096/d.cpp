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
bool prime[55556];
vector<int> p;

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

bool isPrime(int n)
{
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void solve()
{
    p.clear();
    sieve(55555);
    REP(i, 55556){
        if(prime[i]) p.pb(i);
    }

    int sum = 0;
    REP(i, N) sum += p[i];
    int i = 0;
    bool ok = false;
    while(i+N <= p.size()){
        if(isPrime(sum)){
            ok = true;
            break;
        }
        sum -= p[i];
        if(i+N < p.size()) sum += p[i+N];
        i++;
    }
    if(ok){
        REP(j, N-1) cout << p[i+j] << " ";
        cout << p[i+N] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cin >> N;
    FOR(i, 5, 56){
        N = i;
        cout << N << endl;
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker: