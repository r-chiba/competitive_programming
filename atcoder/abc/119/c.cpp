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

int N, a[3], l[8];

int score(vector<int> &v)
{
    int len = v.size();
    int ret = INF;
    REP(i, len) cout << v[i] << " ";
    cout << endl;
    REP(i, 3){
        int used[8] = {0};
        int r = 0;
        REP(j, 3){
            int m = INF, mi = -1;
            REP(k, len){
                if(used[k] == 0 && m > abs(v[k] - a[(i+j)%3])){
                    m = abs(v[k] - a[(i+j)%3]);
                    mi = k;
                    cout << "\t\t" << m << endl;
                }
            }
            used[mi] = 1;
            r += m;
        }
        cout << "\t" << r << endl;
        ret = min(ret, r);
    }
    cout << ret << endl;
    return ret;
}

void solve()
{
    int ans = INF;
    int i = 0;
    while(i < (1<<N)){
        vector<int> v;
        int j = i;
        int n = 0;
        int p = 0;
        REP(k, 8){
            if((j>>k) & 1) v.pb(l[k]);
            else{
                n += l[k];
                p += 10;
            }
        }
        if(n > 0) v.pb(n);
        ans = min(ans, score(v) + p);
        i++;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> a[0] >> a[1] >> a[2];
    REP(i, N) cin >> l[i];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
