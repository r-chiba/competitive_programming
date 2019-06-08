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

ll N;

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

void init()
{
}

void solve()
{
    ll a = 1, b = 1;
    map<ll, ll> m = prime_factor(N);
    int d = 1;
    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->fi << ": " << it->se << endl;
        ll n = it->se / 2;
        REP(i, n){
            a *= it->fi;
            b *= it->fi;
        }
        if(2*n < it->se){
            if(d == 1) a *= it->fi;
            else b *= it->fi;
            d *= -1;
        }
    }
    cout << a << " " << b << endl;

    ll da = 0, db = 0;
    while(a != 0){
        a /= 10;
        da++;
    }
    while(b != 0){
        b /= 10;
        db++;
    }
    cout << max(da, db) << endl;
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
