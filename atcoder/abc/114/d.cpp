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
int divisor[101];

void init()
{
}

ll rec(int i, int n)
{
    if(n == 75) return 1;
    if(i == 100) return 0;
    ll ret = 0;
    REP(j, divisor[i]+1){
        if(!(j == 0 || j == 2 || j == 4 || j == 14 || j == 24 || j == 74)) continue;
        ret += rec(i+1, n*(j+1));
    }
    return ret;
}

void solve()
{
    int val = 2;
    while(val <= N){
        int val_ = val;
        int n = 2;
        while(val_ > 1){
            if(val_ % n == 0){
                divisor[n]++;
                val_ /= n;
            }else{
                n++;
            }
        }
        val++;
    }
    cout << rec(1, 1) << endl;
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
