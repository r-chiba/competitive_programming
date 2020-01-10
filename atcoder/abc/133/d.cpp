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
ll a[100000];

bool ok(ll x, vector<ll> &t)
{
    cout << x << endl;
    t.clear();
    t.resize(N);
    t[0] = x;
    ll rem;
    REP(i, N+1){
        rem = a[i%N] - t[i%N]/2;
        cout << "(" << t[i%N] << "," << a[i%N] << ") " << rem << " ";
        if(rem < 0){
            cout << endl;
            //return false;
        }
        if(i+1 < N) t[(i+1)%N] = rem*2;
        else{
            cout << endl;
            if(rem*2 != t[0]){
                return false;
            }else{
                return true;
            }
        }
    }
    return true;
}

void solve()
{
    ll l = -1, u = a[0]+a[N-1];
    vector<ll> v;
    while(u-l > 1){
        ll mid = (l+u)/2;
        if(mid%2 == 1) mid -= 1;
        if(ok(mid, v)){
            REP(i, v.size()-1) cout << v[i] << " ";
            cout << v[v.size()-1] << endl;
            break;
        }else{
            l = mid;
        }
        break;
    }
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
