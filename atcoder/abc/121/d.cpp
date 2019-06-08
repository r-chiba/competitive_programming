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

ll a, b;

ll f(ll n)
{
    queue<int> q;
    ll logn = 1;
    ll x = 1;
    while(x < n){
        x <<= 1;
        logn++;
    }
    if(x > n){
        x >>= 1;
        logn--;
    }

    REP(i, logn){
        cerr << "[" << n << ", " << x << "]" << endl;
        if(n < x || (n-x) % 2 == 1) q.push(0);
        else q.push(1);
        //if((n-x) % 2 == 0) q.push(1);
        //else q.push(0);
        if(n >= x) n -= x;
        x >>= 1;
    }
    ll ret = 0;
    while(!q.empty()){
        cerr << q.front() << " ";
        ret += q.front();
        q.pop();
        ret <<= 1;
    }
    cerr << endl;
    ret >>= 1;
    return ret;
}

ll f2(ll n)
{
    if(n % 2 == 0){
        return n ^ (n/2 % 2 == 0 ? 0 : 1);
    }else{
        return ((n+1) % 2 == 0 ? 0 : 1);
    }
}

void solve()
{
    ll aa = f(a-1);
    ll bb = f(b);
    ll aaa = f2(a-1);
    ll bbb = f2(b);
    cerr << aa << " " << bb << endl;
    cerr << aaa << " " << bbb << endl;
    cout << (aa ^ bb) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
