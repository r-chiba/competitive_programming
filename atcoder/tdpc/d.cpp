// {{{
#include <iostream>
#include <iomanip>
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

double dp[101][70][70][70];
int primes[3];
int n;
ll d;

void init()
{
}

bool factorize(int val){
    int factor[] = {2, 3, 5};
    while(val > 1){
        bool divide = false;
        REP(i, 3){
            if(val % factor[i] == 0){
                divide = true;
                primes[i]++;
                val /= factor[i];
            }
        }
        if(!divide) break;
    }
    if(val > 1) return false;
    else return true;
}


void solve()
{
    if(!factorize(d)){
        cout << 0 << endl;
        return;
    }

    dp[0][0][0][0] = 1.;
    REP(i, n+1){
        REP(i2, 65){
            REP(i3, 65){
                REP(i5, 65){
                    dp[i+1][i2][i3][i5] += dp[i][i2][i3][i5] / 6;
                    dp[i+1][i2+1][i3][i5] += dp[i][i2][i3][i5] / 6;
                    dp[i+1][i2][i3+1][i5] += dp[i][i2][i3][i5] / 6;
                    dp[i+1][i2+2][i3][i5] += dp[i][i2][i3][i5] / 6;
                    dp[i+1][i2][i3][i5+1] += dp[i][i2][i3][i5] / 6;
                    dp[i+1][i2+1][i3+1][i5] += dp[i][i2][i3][i5] / 6;
                }
            }
        }
    }
    double ans = 0.;
    REP(i2, 70){
        REP(i3, 70){
            REP(i5, 70){
                if(i2 >= primes[0] && i3 >= primes[1] && i5 >= primes[2]){
                    ans += dp[n][i2][i3][i5];
                }
            }
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> d;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
