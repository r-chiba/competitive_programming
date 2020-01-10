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

typedef vector<ll> vec;
typedef vector<vec> mat;

vec matvecmul(mat &A, vec &b)
{
    ll m = A.size(), n = b.size();
    vec v(m);
    REP(i, m){
        REP(j, n){
            v[i] += A[i][j] * b[j];
        }
    }
    return v;
}

mat matmul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    size_t nr = A.size(), nint = B.size(), nc = B[0].size();
    REP(i, nr){
        REP(k, nint){
            REP(j, nc){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

mat matpow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    REP(i, A.size()) B[i][i] = 1;
    while(n > 0){
        if(n & 1) B = matmul(B, A);
        A = matmul(A, A);
        n >>= 1;
    }
    return B;
}

void init()
{
}

void solve()
{
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}

// vim:set foldmethod=marker:
