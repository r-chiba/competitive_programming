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
#include <numeric>
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

struct Circle{
    P m_center;
    int m_radius;
    Circle(): m_center(mp(0, 0)), m_radius(0)
    {}
    Circle(const P c, const int r): m_center(c), m_radius(r)
    {}

    struct Circle& operator=(const struct Circle &rhs)
    {
        if(this == &rhs) return *this;
        this->m_center = rhs.m_center;
        this->m_radius = rhs.m_radius;
        return *this;
    }

    bool operator==(const struct Circle &rhs) const
    {
        return (this->m_center == rhs.m_center && this->m_radius == rhs.m_radius);
    }

    bool operator<(const struct Circle &rhs) const
    {
        if(this->m_radius >= rhs.m_radius) return false;
        double dx = this->m_center.fi - rhs.m_center.fi;
        double dy = this->m_center.se - rhs.m_center.se;
        double dist2 = dx*dx + dy*dy;
        if(dist2 + this->m_radius*this->m_radius < rhs.m_radius*rhs.m_radius){
            return true;
        }
        return false;
    }

    bool operator>(const struct Circle &rhs) const
    {
        return !(*this < rhs && *this == rhs);
    }

    bool operator<=(const struct Circle &rhs) const
    {
        return (*this < rhs || *this == rhs);
    }

    bool operator>=(const struct Circle &rhs) const
    {
        return !(*this < rhs);
    }

};

int N;
Circle circles[100010];
Circle dp[100010];

// search for the smallest circle which is larger than or equal to target in [begin, end).
Circle *binary_search(Circle * array,
                      size_t begin,
                      size_t end,
                      const Circle &target)
{
    size_t b = begin;
    size_t e = end;
    while(e - b >= 1){
        size_t m = (b + e) / 2;
        if(target < array[m]) e = m;
        else if(target == array[m]) e = m + 1;
        else b = m + 1;
        cout << "[" <<  b << " " << e << "]" << endl;
    }
    cout << e << endl;
    return &array[e];
}

void init()
{
}

void solve()
{
    Circle inf(mp(0, 0), INF);
    REP(i, N) dp[i] = inf;
    REP(i, N){
        Circle *p = binary_search(dp, 0, N, circles[i]);
        *p = circles[i];
        //cout << "(" << p->m_center.fi << ", " << p->m_center.se << ") "
        //     << p->m_radius << endl;
    }
    REP(i, N){
        cout << "(" << dp[i].m_center.fi << ", " << dp[i].m_center.se << ") "
             << dp[i].m_radius << endl;
    }
    Circle *last = binary_search(dp, 0, N, inf);
    cout << (reinterpret_cast<size_t>(last) - reinterpret_cast<size_t>(&dp[0])) / sizeof(Circle *)
         << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N){
        int x, r;
        cin >> x >> r;
        circles[i].m_center = mp(x, 0);
        circles[i].m_radius = r;
    }
    solve();
    return 0;
}

// vim:set foldmethod=marker:
