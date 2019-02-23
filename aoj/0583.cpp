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

int n;
int vs[3];

ll gcd(ll a, ll b)
{
    if(a < b) swap(a, b);
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

void init()
{
}

void solve()
{
    ll d = INF;
    REP(i, n){
        FOR(j, i+1, n){
            d = min(d, gcd(vs[i], vs[j]));
        }
    }
    FOR(i, 1, d+1){
        bool ok = true;
        REP(j, n) if(vs[j] % i != 0) ok = false;
        if(ok) cout << i << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> vs[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
