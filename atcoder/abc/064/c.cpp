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
int rate[100];
bool c[8];

void init()
{
}

void solve()
{
    int other = 0;
    int mi = 0, ma = 0;
    REP(i, N){
        if(1 <= rate[i] && rate[i] <= 399){
            c[0] = true;
        }
        else if(400 <= rate[i] && rate[i] <= 799){
            c[1] = true;
        }
        else if(800 <= rate[i] && rate[i] <= 1199){
            c[2] = true;
        }
        else if(1200 <= rate[i] && rate[i] <= 1599){
            c[3] = true;
        }
        else if(1600 <= rate[i] && rate[i] <= 1999){
            c[4] = true;
        }
        else if(2000 <= rate[i] && rate[i] <= 2399){
            c[5] = true;
        }
        else if(2400 <= rate[i] && rate[i] <= 2799){
            c[6] = true;
        }
        else if(2800 <= rate[i] && rate[i] <= 3199){
            c[7] = true;
        }
        else{
            other++;
        }
    }
    REP(i, 8){
        if(c[i]) mi++;
    }
    ma = min(mi + other, 8);
    if(mi == 0) mi = 1;
    cout << mi << " " << ma << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) cin >> rate[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
