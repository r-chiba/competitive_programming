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

int n, c;
vector<P> v;
int ans = 0;

void init()
{
}

void solve()
{
    sort(v.begin(), v.end(), greater<P>());
    while(true){
        REP(i, n){
            int sum = v[i].fi;
            int num = v[i].se;
            vector<int> use;
            use.push_back(i);
            FORR(j, n-1, i+1){
                if(v[j].se > 0){
                    sum += v[j].fi;
                    num = min(num, v[j].se);
                    use.push_back(j);
                }
                if(sum >= c && num > 0) break;
            }
            //cout <<  i << " " << sum << " " << num << endl;
            if(sum >= c && num > 0){
                ans += num;
                REP(j, use.size()){
                    //cout << "use[" << j << "]=" << use[j] << endl;
                    v[use[j]].se -= num;
                }
                break;
            }else{
                int m = (c+v[i].fi-1) / v[i].fi;
                //cout << m << endl;
                if(m <= v[i].se){
                    ans += v[i].se / m;
                    v[i].se -= m * v[i].se / m;
                    break;
                }else{
                    goto END;
                }
            }
        }
        //REP(i, n){
        //    cout << "v[" << i << "] = " << v[i].fi << ": " << v[i].se << endl;
        //}
    }
END:
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> c;
    REP(i, n){
        int val, b;
        cin >> val >> b;
        if(val >= c) ans += b;
        else v.push_back(mp(val, b));
    }
    n = v.size();
    solve();
    return 0;
}

// vim:set foldmethod=marker:
