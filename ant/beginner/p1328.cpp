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

int no = 0;
int n, d;
vector<P> ps;

void init()
{
    ps.clear();
}

void solve()
{
    int ans = 0;
    sort(ps.begin(), ps.end());
    int idx = 0;
    while(true){
        int x = ps[idx].fi;
        int y = ps[idx].se;
        double d2 = static_cast<double>(d*d) - static_cast<double>(y*y);
        if(d2 < 0.){
            ans = -1;
            goto END;
        }
        double delta = sqrt(d2);
        double pos = static_cast<double>(x) + delta;
        ans++;
        idx++;
        while(true){
            if(idx == n) goto END;
            int nx = ps[idx].fi;
            int ny = ps[idx].se;
            double d_ = static_cast<double>(nx) - pos;
            if(d_*d_ + static_cast<double>(ny*ny) > static_cast<double>(d*d)){
                if(d_ >= 0){
                    // add new circle in next loop
                    break;
                }else{
                    // turn back pos so that the circle contains (nx, ny)
                    pos = static_cast<double>(nx) + sqrt(static_cast<double>(d*d) - static_cast<double>(ny*ny));
                }
            }
            idx++;
        }
    }
END:
    cout << "Case " << ++no << ": " << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){
        init();
        cin >> n >> d;
        if(n == 0 && d == 0) break;
        bool imp = false;
        REP(i, n){
            int a, b;
            cin >> a >> b;
            if(b > d) imp = true;
            ps.push_back(mp(a, b));
        }
        if(imp){
            cout << "Case " << ++no << ": " << -1 << endl;
        }else{
            solve();
        }
        cin.ignore();
    }
    return 0;
}

// vim:set foldmethod=marker:
