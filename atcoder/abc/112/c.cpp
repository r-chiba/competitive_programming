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
ll x[100], y[100];
ll h[100];

void init()
{
}

void solve()
{
    REP(cx, 101){
        REP(cy, 101){
            set<ll> s;
            REP(i, N){
                if(h[i] > 0){
                    ll hh = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                    s.insert(hh);
                }
            }
            if(s.size() == 1){
                ll hh = *s.begin();
                bool ok = true;
                REP(i, N){
                    if(h[i] != max(hh - abs(x[i] - cx) - abs(y[i] - cy), 0ll)){
                        ok = false;
                    }
                }
                if(!ok) continue;
                cout << cx << " " << cy << " " << *s.begin() << endl;
                return;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i] >> h[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
