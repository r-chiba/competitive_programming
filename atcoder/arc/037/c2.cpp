// {{{
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

#define int ll

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

typedef vector<int> vi;
int f(int N, int K, vi & a, vi & b, int x){
    int cnt = 0;
    REP(i,N){
        int l = -1;
        int r = N;
        while(l+1 < r){
            int m = (l+r)/2;
            if(a[i] * b[m] <= x){
                l = m;
            } else {
                r = m;
            }
        }
        cnt += r;
    }
    return cnt;
}

int solve(int N, int K, vi & a, vi & b){
    sort(ALL(a));
    sort(ALL(b));
    int l = 0;
    int r = a[N-1]*b[N-1];
    while(l + 1 < r){
        int m = (l+r)/2;
        int c = f(N,K,a,b,m);

        if(c >= K){
            r = m;
        } else{
            l = m;
        }
    }
    return r;
}

signed main(){
    int N,K;
    cin >> N >> K;
    vi a(N), b(N);
    REP(i,N) cin >> a[i];
    REP(i,N) cin >> b[i];
    cout << solve(N,K,a,b) << endl;
}

// vim:set foldmethod=marker:
