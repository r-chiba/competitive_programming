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

bool achievable(int n)
{
    int l = 0, r = 0, nrev = 0, t = 0;
    queue<int> lq, rq;
    bool rev = false;
    while(true){
        while(r < N){
            while(r < N && !rev && s[r] == '1'){
                nrev++;
                r++;
            }
            while(r < N && rev && s[r] == '0'){
                nrev++;
                r++;
            }
            if(nrev >= n) return true;
            if(rev && s[r] == '1'){
                rq.push(r);
                rev = false;
            }
            if(t >= K && s[r] == '0') break;
            if(!rev && s[r] == '0' && t < K){
                lq.push(r);
                rev = true;
                t++;
            }
        };
        if(r >= N) return (nrev >= n);
        while(t >= K){
            if(s[l] == '1'){
                nrev--;
                l++;
            }
            else if(s[l] == '0' && l == lq.front()){
                while(l < rq.front()){
                    nrev--;
                    l++;
                }
                t--;
                lq.pop();
                rq.pop();
            }
        }
    }
    return false;
}


void solve()
{
    int l = 0, r = N+1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(achievable(mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    cin >> s;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
