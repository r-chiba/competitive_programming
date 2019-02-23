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

int n;
int v[100000];

void init()
{
}

void solve()
{
    map<int, int> mo, me;
    int i = 0;
    while(true){
        if(2*i < n) me[v[2*i]]++;
        else break;
        if(2*i+1 < n) mo[v[2*i+1]]++;
        else break;
        i++;
    }
    int maxo = 0, maxo2=0, maxe = 0, maxe2=0;
    int maxov = 0, maxov2=0, maxev = 0, maxev2=0;
    for(auto it = me.begin(); it != me.end(); it++){
        if(maxe < it->se){
            maxe2 = maxe;
            maxev2 = maxev;
            maxe = it->se;
            maxev = it->fi;
        }
        else if(maxe2 < it->se){
            maxe2 = it->se;
            maxev2 = it->fi;
        }
    }
    for(auto it = mo.begin(); it != mo.end(); it++){
        if(maxo < it->se){
            maxo2 = maxo;
            maxov2 = maxov;
            maxo = it->se;
            maxov = it->fi;
        }
        else if(maxo2 < it->se){
            maxo2 = it->se;
            maxov2 = it->fi;
        }
    }
    if(maxov != maxev) cout << n - maxe - maxo << endl;
    else{
        if(maxo2 < maxe2) cout << n - maxe2 - maxo << endl;
        else cout << n - maxe - maxo2 << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> v[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
