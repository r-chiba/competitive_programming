// {{{
#include <iostream>
#include <cmath>
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
#if __cplusplus >= 201103
#include <numeric>
#endif
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

#if __cplusplus >= 201103
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int n;
int sum;
int comb[10][10];

void init()
{

    REP(i, 10){
        REP(j, 10){
            if(i == 0 || j == 0) comb[i][j] = 1;
            else if(i == j) comb[i][j] = 1;
            else comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
}

void solve()
{
    vector<int> v;
    REP(i, n){
        v.push_back(i+1);
    }

    do{
        int s = 0;
        REP(i, n){
            s += v[i] * comb[n-1][i];
        }
        if(s == sum) break;
    }while(next_permutation(v.begin(), v.end()));

    REP(i, n-1) cout << v[i] << " ";
    cout << v[n-1] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    init();
    cin >> n >> sum;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
