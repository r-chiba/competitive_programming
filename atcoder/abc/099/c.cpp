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

void init()
{
}

int rec(int v)
{
    if(v < 6) return v;
    int ret = INF;
    int x = 1;
    while(x * 6 <= v){
        x *= 6;
    }
    ret = min(ret, rec(v-x)+1);
    x = 1;
    while(x * 9 <= v){
        x *= 9;
    }
    ret = min(ret, rec(v-x)+1);
    return ret;
}

void solve3()
{
    cout << rec(N) << endl;;
}

void solve2()
{
    int ret = 0;
    int n2 = 0, n3 = 0;
    int NN = N;
    while(NN % 2 == 0){
        NN /= 2;
        n2++;
    }
    while(NN % 3 == 0){
        NN /= 3;
        n3++;
    }
    cout << NN << " " << n2 << " " << n3 << endl;
}

void solve()
{
    int ret = 0;
    const int vs[] = {9, 6};
    while(N >= 6){
        int ns[] = {1, 1};
        REP(i, 2){
            int n = 0;
            while(ns[i]*vs[i] < N){
                ns[i] *= vs[i];
            }
        }
        if(ns[0] >= ns[1]){
            N -= ns[0];
            cout << ns[0] << " " << N << endl;
        }else{
            N -= ns[1];
            cout << ns[1] << " " << N << endl;
        }
        ret++;
    }
    ret += N;
    cout << ret << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    solve3();
    return 0;
}

// vim:set foldmethod=marker:
