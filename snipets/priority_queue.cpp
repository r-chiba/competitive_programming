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

#if __cplusplus >= 201103
typedef long long ll;
#endif
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
#if __cplusplus >= 201103
const ll LINF = 10000000000000000ll;
#endif
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
// }}}

class Compare
{
public:
    // compare function used in priority_queue should return true if lhs < rhs
    // however, priority_queue sorts the inner vector in descending order by using the compare function
    // so, you must implement compare function like the std::greater function
    bool operator()(const P &lhs, const P &rhs){
        if(lhs.fi < rhs.fi)
            return false;
        return true;
    }
};

priority_queue<P, vector<P>, Compare> q;


void init()
{
}

void solve()
{
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    q.push(mp(1, 0));
    q.push(mp(-3, 5));
    q.push(mp(2, -2));
    while(!q.empty()){
        const P &p = q.top();
        cout << p.fi << " " << p.se << endl;
        q.pop();
    }
    return 0;
}

// vim:set foldmethod=marker:
