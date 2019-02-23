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

int H, W;
int a[500][500];

void init()
{
}

void solve()
{
    int i = 0, j = 0;
    int d = 1;
    vector<string> ans;
    int sum = H*W;
    while(i < H){
        //cout << "!" << i << " " << H << endl;
        while(d == 1 ? j < W : j >= 0){
            //cout << "[" << i+1 << ", " << j+1 << "] " << a[i][j] << " " << d << endl;
            if(a[i][j] % 2 == 1){
                if(i == H-1 && (d == 1 ? j == W-1 : j == 0)){
                    sum--;
                    goto END;
                }
                if(d == 1){
                    if(j < W-1){
                        a[i][j+1]++; a[i][j]--;
                        string s = to_string(i+1) + " " + to_string(j+1)
                                + " " + to_string(i+1) + " " + to_string(j+2);
                        //cout << s << endl;
                        ans.pb(s);
                    }else{
                        a[i+1][j]++; a[i][j]--;
                        string s = to_string(i+1) + " " + to_string(j+1)
                                + " " + to_string(i+2) + " " + to_string(j+1);
                        //cout << s << endl;
                        ans.pb(s);
                    }
                }else{
                    if(j > 0){
                        a[i][j-1]++; a[i][j]--;
                        string s = to_string(i+1) + " " + to_string(j+1)
                                + " " + to_string(i+1) + " " + to_string(j);
                        //cout << s << endl;
                        ans.pb(s);
                    }else{
                        a[i+1][j]++; a[i][j]--;
                        string s = to_string(i+1) + " " + to_string(j+1)
                                + " " + to_string(i+2) + " " + to_string(j+1);
                        //cout << s << endl;
                        ans.pb(s);
                    }
                }
            }
            j += (d == 1 ? 1 : -1);
        }
        j = (d == 1 ? W-1 : 0);
        i++;
        d *= -1;
    }

END:
    //cout << sum << endl;
    cout << ans.size() << endl;
    for(string s: ans) cout << s << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H) REP(j, W) cin >> a[i][j];
    solve();
    return 0;
}

// vim:set foldmethod=marker:
