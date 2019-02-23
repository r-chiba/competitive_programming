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

int packets[6];

void init()
{
}

void solve()
{
    int ans = packets[5] + packets[4] + packets[3];
    int space[2] = {0, 0};

    space[0] += packets[4] * 11 + packets[3] * 20;
    space[1] += packets[3] * 5;

    if(packets[2] > 0){
        int r = packets[2] % 4;
        ans += (packets[2] / 4) + r == 0 ? 0 : 1;
        space[0] += r == 0 ? 0 : (4-r) * 9;
        space[1] += r == 0 ? 0 : r == 1 ? 5 : r == 2 ? 3 : 1;
    }
    //cout  << "[]"  << ans << " "<< space[0] << " " << space[1] << endl;

    if(packets[1] > 0){
        space[0] -= min(packets[1], space[1]) * 4;
        if(packets[1] > space[1]){
            packets[1] -= space[1];
            int r = packets[1] % 9;
            ans += packets[1] / 9 + r == 0 ? 0 : 1;
            space[0] += r == 0 ? 0 : (9-r) * 4;
        }
    }
    //cout  << "[]"  << ans << " "<< space[0] << " " << space[1] << endl;

    if(packets[0] > 0){
        if(packets[0] > space[0]){
            packets[0] -= space[0];
            int r = packets[0] % 36;
            ans += packets[0] / 36 + r == 0 ? 0 : 1;
        }
    }
    //cout  << "[]"  << ans << " "<< space[0] << " " << space[1] << endl;
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(true){
        bool end = true;
        REP(i, 6){
            cin >> packets[i];
            if(packets[i] != 0) end = false;
        }
        if(end) break;
        solve();
    }
    return 0;
}

// vim:set foldmethod=marker:
