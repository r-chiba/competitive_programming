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
ll a[200000];

bool isOk(ll a, ll b)
{
    bool ret = true;
    while(a != 0 && b != 0){
        ll aa = a & 1;
        ll bb = b & 1;
        if(aa == bb && aa == 1){
            ret = false;
            break;
        }
        a >>= 1;
        b >>= 1;
    }
    return ret;
}

void init()
{
}

void solve()
{
    ll ans = 0;
    ll current = 0;
    int r = -1;
    REP(l, N){
        while(r < N-1 && isOk(current, a[r+1])){
            current ^= a[r+1];
            ans += (r+1) - l + 1;
            r++;
        }
        if(r == N-1) break;
        current &= ~a[l];
    }

    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) cin >> a[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
