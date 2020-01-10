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

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

// }}}

int N;
ll a[100000];

int test(ll x)
{
    vector<ll> m(N);
    ll d = x;
    REP(i, N){
        m[i%N] += d;
        m[(i+1)%N] += a[i%N] - d;
        d = a[i%N] - d;
    }
    //cout << "[";
    //REP(i, N-1) cout << m[i] << " ";
    //cout << m[N-1] << "]" << endl;

    if(m[0] + m[N-1] == 2*a[N-1]){
        //cout << x << " " << 0 << endl;
        return 0;
    }
    else if(m[0] + m[N-1] > 2*a[N-1]){
        //cout << x << " " << 1 << endl;
        return 1;
    }
    else{
        //cout << x << " " << -1 << endl;
        return -1;
    }
}

void createAns(vector<ll> &v, ll x)
{
    ll d = x;
    REP(i, N){
        v[i%N] += d;
        v[(i+1)%N] += a[i%N] - d;
        d = a[i%N] - d;
    }
}


void solve()
{
    ll lb = -1, ub = a[0];
    while(ub - lb > 1){
        ll mid = (lb + ub) / 2;
        int ret = test(mid);
        if(ret == 0){
            ub = mid;
            break;
        }else if(ret > 0){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    //cout << ub << endl;
    vector<ll> ans(N);
    createAns(ans, ub);
    REP(i, N-1) cout << ans[i] << " ";
    cout << ans[N-1] << endl;

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
