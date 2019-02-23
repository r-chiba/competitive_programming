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

string s, t;

void init()
{
}

void solve()
{
    reverse(ALL(s));
    reverse(ALL(t));
    int slen = s.size();
    int tlen = t.size();
    int p = -1;
    REP(i, slen - tlen + 1){
        REP(j, tlen){
            if(s[i+j] != t[j] && s[i+j] != '?') goto next;
        }
        p = i;
        break;
next:
        ;
    }
    if(p == -1) cout << "UNRESTORABLE" << endl;
    else{
        REP(i, tlen){
            s[p+i] = t[i];
        }
        REP(i, slen){
            s[i] = (s[i] == '?' ? 'a' : s[i]);
        }
        reverse(ALL(s));
        cout << s << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> t;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
