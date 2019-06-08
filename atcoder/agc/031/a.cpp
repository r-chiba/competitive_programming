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

int N;
string s;
vector<int> same[26];
vector<int> v;

void init()
{
}

void solve()
{
    ll ans = 0ll;
    int sz = s.size();
    REP(i, sz) same[s[i]-'a'].pb(i);
    REP(i, 26){
        if(same[i].size() > 0) v.pb(same[i].size());
    }
    for(int x: v) cout << x << " ";
    cout << endl;
    ans += v.size();
    REP(i, v.size()){
        vector<ll> a;
        a.pb(v[i]);
        FOR(j, i+1, v.size()){
            vector<ll> b;
            for(ll x: a){
                ans += x * v[j];
                ans %= MOD;
                b.pb(x * v[i]);
            }
            copy(b.begin(), b.end(), back_inserter(a));
        }
    }
#if 0
    int right = -1;     
    for(int left = 0; left < sz; ++left){
        bool flag[26];
        REP(i, 26) flag[i] = false;
        while(right < sz-1 && !flag[s[right+1]-'a']){
            right++;
            flag[s[right]-'a'] = true;
            ans += right - left + 1;
            cout << left << " " << right << " " << ans << endl;
        }
    }
#endif
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> s;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
