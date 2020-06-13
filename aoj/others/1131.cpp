#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define pb(a) push_back(a)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
const ll LINF = 10000000000000000ll;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

int p, q, a, n;

void init()
{
}

int dfs(int num, int d, int prod, int sum)
{
    if(num > n) return 0;
    int ret = 0;
    for(int i = d; i * prod <= a; i++){
        // p / q == sum/prod + 1/i ?
        int lhs_numer = prod * i;
        int rhs_numer = sum * i + prod;
        if(lhs_numer * p == rhs_numer * q){
            ret++;
        }else if(lhs_numer * p > rhs_numer * q){
            ret += dfs(num+1, i, prod * i, rhs_numer);
        }
    }
    return ret;
}

void solve()
{
    cout << dfs(1, 1, 1, 0) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){
        cin >> p >> q >> a >> n;
        if(p == 0 && q == 0 && a == 0 && n == 0) break;
        solve();
    }

    return 0;
}
