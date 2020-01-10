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

static inline ll mod(ll x, ll m)
{
    ll y = x % m;
    return (y >= 0 ? y : y+m);
}

// }}}

string s, t;

int isOk(string s, string t)
{
    int cs[26] = {0};
    int ct[26] = {0};
    REP(i, s.size()){
        cs[s[i]-'a']++;
    }
    REP(i, t.size()){
        cs[t[i]-'a']++;
    }
    REP(i, 26){
        if(cs[i] == 0 && ct[i] > 0) return false;
    }
    return true;
}

int countSameChars(string s)
{
    int count[26] = {0};
    REP(i, s.size()){
        count[s[i]-'a']++;
    }
    int ret = 0;
    REP(i, 26){
        ret = max(ret, count[i]);
    }
    return ret;
}

bool isSubstring(string s, int i, string target)
{
    int is = 0;
    int it = 0;
    while(is < i && it < target.size()){
        if(s[is%s.size()] == target[it]){
            it++;
        }
        is++;
    }
    return (it == target.size());
}

void makeTable(string s, string t)
{
    int is = 0;
    int it = 0;
    while(is < i && it < target.size()){
        if(s[is%s.size()] == target[it]){
            it++;
        }
        is++;
    }
    return (it == target.size());


void solve()
{
    if(!isOk(s, t)){
        cout << -1 << endl;
        return;
    }
#if 0
    ll ub = s.size() * t.size() + 1;
    ll lb = -1;
    while(ub - lb > 1){
        //cout << ub << " " << lb << endl;
        ll mid = (ub + lb) / 2;
        if(isSubstring(s, mid, t)){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    cout << (ub >= s.size()*t.size()+1 ? -1 : ub) << endl;
#endif
    int is = 0;
    int it = 0;
    while(is < s.size()*t.size()+1 && it < t.size()){
        if(s[is%s.size()] == t[it]){
            it++;
        }
        is++;
    }
    if(it == t.size()) cout << is << endl;
    else cout << -1 << endl;
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
