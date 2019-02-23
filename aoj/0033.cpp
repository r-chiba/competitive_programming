// {{{
#include <iostream>
#include <cmath>
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

int balls[10];

void init()
{
}

void solve()
{
    bool ok = true;
    int l, r = -1;
    REP(i, 10){
        int *p, *q;
        if(l < r){
            p = &l;
            q = &r;
        }else{
            p = &r;
            q = &l;
        }
        if(*q < balls[i]) *q = balls[i];
        else if(*p < balls[i]) *p = balls[i];
        else{
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

bool check(vector<int> &v)
{
    if(v.empty()) return true;
    bool ret = true;
    REP(i, v.size()-1){
        //cout << i << " " << v[i] << endl;
        if(v[i] > v[i+1]){
            ret = false;
            break;
        }
    }
    return ret;
}

bool dfs(int i, vector<int> &v1, vector<int> &v2)
{
    //cout << i << endl;
    if(i == 10) return check(v1) && check(v2);

    vector<int> c1(v1), c2(v2);
    c1.pb(balls[i]);
    c2.pb(balls[i]);
    return dfs(i+1, c1, v2) || dfs(i+1, v1, c2);
}

void solve2()
{
    vector<int> v1, v2;
    bool ok = dfs(0, v1, v2);
    cout << (ok ? "YES" : "NO") << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    while(n--){
        REP(i, 10){
            cin >> balls[i];
        }
        //solve();
        solve2();
    }
    return 0;
}

// vim:set foldmethod=marker:
