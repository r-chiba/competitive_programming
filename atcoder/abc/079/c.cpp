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

int vals[4];

void init()
{
}

void solve()
{
    int ans;
    REP(i, 1<<3){
        int sum = vals[0];
        REP(j, 3){
            int b = (i>>j)&1;
            sum += b == 1 ? vals[j+1] : -vals[j+1];
        }
        if(sum == 7){
            ans = i;
            break;
        }
    }
    REP(i, 3){
        int b = (ans>>i)&1;
        cout << vals[i] << (b == 1 ? '+' : '-');
    }
    cout << vals[3] << "=7" << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    REP(i, 4) vals[i] = s[i] - '0';
    solve();
    return 0;
}

// vim:set foldmethod=marker:
