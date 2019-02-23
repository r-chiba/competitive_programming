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
ll M;
//map<ll, ll> m;
vector<ll> vec;
map<LP, ll> memo;

void init()
{
}

ll rec(ll n, ll v){
    cout << n << " " << v << endl;
    if(memo.find(mp(n, v)) != memo.end()) return memo[mp(n, v)];
    if(v == M) return (n <= N ? 1 : 0);
    if(v > M || n > N) return 0;
    ll ret = 0;
    for(auto it = vec.begin(); it != vec.end(); it++){
        if(v * *it <= M) ret += rec(n+1, v * *it);
        ret %= MOD;
    }
    return ret;
}

void solve()
{
    for(ll i = 2; i*i <= M; i++){
        if(M % i == 0){
            vec.pb(i);
            if(/*i != 1 && */i*i != M) vec.pb(M/i);
        }
    }
    for(auto v: vec) cout << v << " ";
    cout << endl;
    cout << (rec(0, 1) + 2) % MOD << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
