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

int n, k;
string s;

void init()
{
}

void solve()
{
#if 0
    vector<char> v(ALL(s));
    int len = v.size();
    int ch;
    sort(ALL(v));
    do{
        ch = 0;
        REP(i, len){
            if(v[i] != s[i]) ch++;
        }
        if(ch <= k) break;
    }while(next_permutation(ALL(v)));
    REP(i, len) cout << v[i];
    cout << endl;
#endif
    vector<string> v;
    int ma[100], mi[100];
    int len = s.size();
    REP(step, k+1){
        string ss(s);
        REP(d, len){
            REP(i, 100) ma[i] = mi[i] = -1;
            REP(i, len){
                REP(j, len){
                    if(ma[j] == -1 || ss[ma[j]] < ss[i]){
                        FORR(k, len-1, j+1) ma[k] = ma[k-1];
                        ma[j] = i;
                        break;
                    }
                }
                REP(j, len){
                    if(mi[j] == -1 || ss[mi[j]] > ss[i]){
                        FORR(k, len-1, j+1) mi[k] = mi[k-1];
                        mi[j] = i;
                        break;
                    }
                }
            }

            int sidx = INF;
            REP(i, len){
                if(mi[d] <= ma[i] || ss[mi[d]] >= ss[ma[i]]) continue;
                sidx = min(sidx, ma[i]);
            }
            if(sidx < len){
                swap(ss[mi[d]], ss[sidx]);
            }
            int change = 0;
            REP(i, len){
                if(s[i] != ss[i]) change++;
            }
            if(change <= step) v.pb(ss);
        }

    }
    cout << *min_element(ALL(v)) << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
