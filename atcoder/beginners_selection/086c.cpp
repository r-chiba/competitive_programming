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

vector<IP> ips;

void init()
{
}

bool is_reachable(P &s, P &d, int n)
{
    stack<IP> st;
    st.push(mp(0, s));
    while(!st.empty()){
        int t = st.top().fi;
        P p = st.top().se;
        st.pop();
        if(t == n && p == d) return true;
        if(t >= n) continue;
        REP(i, 4){
            int nx = p.fi + dx[i];
            int ny = p.se + dy[i];
            st.push(mp(t+1, mp(nx, ny)));
        }
    }
    return false;
}

void solve()
{
    size_t len = ips.size();
    REP(i, len-1){
        if(!is_reachable(ips[i].se, ips[i+1].se, ips[i+1].fi-ips[i].fi)){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ips.push_back(mp(0, mp(0, 0)));
    int n;
    IP prev = mp(0, mp(0, 0));
    cin >> n;
    REP(i, n){
        int t, x, y;
        cin >> t >> x >> y;
        IP now = mp(t, mp(x, y));
        if(!is_reachable(prev.se, now.se, now.fi-prev.fi)){
            cout << "No" << endl;
            return 0;
        }
        prev = now;
    }
    cout << "Yes" << endl;
    return 0;
}

// vim:set foldmethod=marker:
