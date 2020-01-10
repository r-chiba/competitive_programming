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

#if 1 // by size

struct UnionFind{
    vector<int> parent;
    UnionFind(int n) : parent(n, -1) {};
    int root(int x){
        return (parent[x] < 0 ? x : (parent[x] = root(parent[x])));
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x != y){
            if(parent[y] < parent[x]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
        }
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    int size(int x){
        return -parent[root(x)];
    }
};

#else // by rank

struct UnionFind{
    vector<int> parent, rank;
    UnionFind(int n) : parent(n, -1), rank(n, 1) {};
    int root(int x){
        return (parent[x] < 0 ? x : (parent[x] = root(parent[x])));
    }
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(rank[x] < rank[y]){
            parent[x] = y;
        }else{
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
};

#endif

void solve()
{
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

// vim:set foldmethod=marker:
