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

//#if __cplusplus >= 201103
typedef long long ll;
//#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
//#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
//#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

int n_tri[4];

int distinguish_tri(int a, int b, int c)
{
    int edges[3] = {a, b, c};
    sort(edges, edges+3);
    a = edges[0];
    b = edges[1];
    c = edges[2];

    if(a + b <= c) return -1;

    double len_orth = sqrt(a*a + b*b);
    if(c == len_orth) return 1;
    else if(c < len_orth) return 2;
    else return 3;
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

    while(true){
        int a, b, c;
        cin >> a >> b >> c;
        int v = distinguish_tri(a, b, c);
        if(v == -1){
            cout << n_tri[0] << " " << n_tri[1] << " " << n_tri[2] << " " << n_tri[3] << endl;
            break;
        }
        n_tri[0]++;
        n_tri[v]++;
    }
    return 0;
}

// vim:set foldmethod=marker:
