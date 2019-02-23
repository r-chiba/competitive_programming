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

int n;
vector<P> red, blue;

bool compare_red(const P &lhs, const P &rhs)
{
    //if(lhs.fi > rhs.fi && lhs.se > rhs.se) return true;
    //if(lhs.fi == rhs.fi && lhs.se > rhs.se) return true;
    //return false;
    if(lhs.se > rhs.se) return true;
    return false;
}

bool compare_blue(const P &lhs, const P &rhs)
{
    //if(lhs.fi < rhs.fi && lhs.se < rhs.se) return true;
    //if(lhs.fi == rhs.fi && lhs.se < rhs.se) return true;
    //return false;
    if(lhs.fi < rhs.fi) return true;
    return false;
}

void init()
{
}

void solve()
{
    int ans = 0;
    sort(red.begin(), red.end(), compare_red);
    sort(blue.begin(), blue.end(), compare_blue);
    REP(i, n){
        P &cur_b = blue[i];
        //int diff = -1;
        //int pos = -1;
        REP(j, red.size()){
            if(red[j].fi < cur_b.fi && red[j].se < cur_b.se){
                ////int diff_cur = cur_b.fi - red[j].fi + cur_b.se - red[j].se;
                //int diff_cur = max(cur_b.fi - red[j].fi, cur_b.se - red[j].se);
                //if(diff == -1 || diff > diff_cur){
                //    diff = diff_cur;
                //    pos = j;
                //}
                ans++;
                red.erase(red.begin() + j);
                break;
            }
        }
        //if(pos != -1){
        //    ans++;
        //    red.erase(red.begin() + pos);
        //}
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n){
        int a, b;
        cin >> a >> b;
        red.pb(mp(a, b));
    }
    REP(i, n){
        int a, b;
        cin >> a >> b;
        blue.pb(mp(a, b));
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
