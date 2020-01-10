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

struct Cake{
    ll x, y, z;
};

bool comp1(const Cake &lhs, const Cake &rhs){
    if(lhs.x < rhs.x)
        return false;
    return true;
}
bool comp2(const Cake &lhs, const Cake &rhs){
    if(lhs.x > rhs.x)
        return false;
    return true;
}
bool comp3(const Cake &lhs, const Cake &rhs){
    if(lhs.y < rhs.y)
        return false;
    return true;
}
bool comp4(const Cake &lhs, const Cake &rhs){
    if(lhs.y > rhs.y)
        return false;
    return true;
}
bool comp5(const Cake &lhs, const Cake &rhs){
    if(lhs.z < rhs.z)
        return false;
    return true;
}
bool comp6(const Cake &lhs, const Cake &rhs){
    if(lhs.z > rhs.z)
        return false;
    return true;
}

ll N, M;
Cake c[1000];

void solve()
{
    ll ans = 0;
    ll xx = 0, yy = 0, zz = 0;
    sort(c, c+N, comp1);
    REP(i, M){
        xx += c[i].x;
        yy += c[i].y;
        zz += c[i].z;
    }
    ans = max(ans, abs(xx)+abs(yy)+abs(zz));

    xx = 0, yy = 0, zz = 0;
    sort(c, c+N, comp2);
    REP(i, M){
        xx += c[i].x;
        yy += c[i].y;
        zz += c[i].z;
    }
    ans = max(ans, abs(xx)+abs(yy)+abs(zz));

    xx = 0, yy = 0, zz = 0;
    sort(c, c+N, comp3);
    REP(i, M){
        xx += c[i].x;
        yy += c[i].y;
        zz += c[i].z;
    }
    ans = max(ans, abs(xx)+abs(yy)+abs(zz));

    xx = 0, yy = 0, zz = 0;
    sort(c, c+N, comp4);
    REP(i, M){
        xx += c[i].x;
        yy += c[i].y;
        zz += c[i].z;
    }
    ans = max(ans, abs(xx)+abs(yy)+abs(zz));

    xx = 0, yy = 0, zz = 0;
    sort(c, c+N, comp5);
    REP(i, M){
        xx += c[i].x;
        yy += c[i].y;
        zz += c[i].z;
    }
    ans = max(ans, abs(xx)+abs(yy)+abs(zz));

    xx = 0, yy = 0, zz = 0;
    sort(c, c+N, comp6);
    REP(i, M){
        xx += c[i].x;
        yy += c[i].y;
        zz += c[i].z;
    }
    ans = max(ans, abs(xx)+abs(yy)+abs(zz));

    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N) cin >> c[i].x >> c[i].y >> c[i].z;
    solve();
    return 0;
}

// vim:set foldmethod=marker:
