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

string s;
int f[100000];

bool isOk(int k, int t)
{
    int n = s.size();
    REP(i, n) f[i] = 0;
    int sum = 0;
    REP(i, n-k+1){
        int v = (s[i] - '0' == t ? 0 : 1);
        if((v + sum) % 2 != 0) f[i] = 1;
        sum += f[i];
        //cout << f[i] << " ";
        if(i-k+1 >= 0) sum -= f[i-k+1];
    }
    //cout << endl;
    FOR(i, n-k+1, n){
        int v = (s[i] - '0' == t ? 0 : 1);
        if((v + sum) % 2 != 0){
            //cout << k << " " << i << " " << sum << endl;
            return false;
        }
        if(i-k+1 >= 0) sum -= f[i-k+1];
    }
    return true;
}

void init()
{
}

void solve()
{
#if 0
    int lbi = 0, ube = s.size();
    while(ube - lbi > 1){
        int mid = (lbi + ube) / 2;
        if(isOk(mid, 0) || isOk(mid, 1)) lbi = mid;
        else ube = mid;
        cout << lbi << " " << ube << endl;
    }
    cout << lbi << endl;
#else
    int ans = 0;
    REPR(i, s.size()){
        if(isOk(i, 0) || isOk(i, 1)){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
#endif
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
