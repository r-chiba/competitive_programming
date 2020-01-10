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
ull K;
ull a[100000];
int d[50];

ll f(ll x)
{
    ll ret = 0;
    REP(i, N) ret += (x ^ a[i]);
    return ret;
}

void solve()
{
    REP(i, N){
        ll x = a[i];
        int j = 0;
        while(x > 0){
            if(x & 1) d[j]++;
            x >>= 1;
            j++;
        }
    }
    ll x = 0;
    REPR(i, 49){
        if(K >= (1ull << i) && d[i] < N-d[i]){
            x += (1ull << i);
        }
    }
    int i = 0;
    while(x > K) x &= ~(1ull << i++);
    cout << f(x) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N){
        cin >> a[i];
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
