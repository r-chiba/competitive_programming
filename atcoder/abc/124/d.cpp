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

int N, K;
string s;

void init()
{
}

void solve()
{
    int ans = 0;
    queue<int> pl, pr;
    pl.push(0);
    int r = 0;
    int d = 0;
    int x = 0;
    while(r < N){
        bool rev = false;
        while(r < N && (s[r] == 1 || (s[r] == 0 && (rev || d+1 <= K)))){
            //cout << "\t" << r << endl;
            x++;
            if(s[r] == 0){
                if(!rev){
                    rev = true;
                    d++;
                }
            }else{
                if(rev){
                    pl.push(r);
                    if(r > 1) pr.push(r-1);
                    rev = false;
                }
            }
            r++;
        }
        //cout << x << endl;
        ans = max(ans, x);
        if(r < N && d == K){
            int ppl = pl.front(); pl.pop();
            int ppr = pr.front(); pr.pop();
            //cout << "\t" << ppl << " " << ppr << endl;
            x -= ppr - ppl + 1;
            d--;
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K >> s;
    REP(i, s.size()) s[i] -= '0';
    solve();
    return 0;
}

// vim:set foldmethod=marker:
