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
#include <regex>

string s;

void init()
{
}

void solve()
{
    const char* words[2] = {"ream", "rase"};
    size_t len = s.size();
    size_t i = 0;
    bool ans = true;
    while(i < len){
        int val;
        switch(s[i]){
        case 'd':
            val = 0;
            break;
        case 'e':
            val = 1;
            break;
        default:
            ans = false;
            break;
        }
        if(!ans) break;
        i++;
        REP(j, 4){
            if(i >= len || s[i++] != words[val][j]){
                ans = false;
                break;
            }
        }
        if(!ans) break;
        if(val == 0 && s[i] == 'e' && s[i+1] == 'r' && s[i+2] != 'a') i += 2;
        if(val == 1 && s[i] == 'r') i++;
    }
    cout << (ans ? "YES" : "NO") << endl;
                
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
