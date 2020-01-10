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

// only applicable to lower-case alphabet strings
class Trie {
    vector<vector<int> > mat_;
public:
    Trie() {
        mat_.push_back(vector<int>(27, -1));
        mat_[0][26] = 0;
    }

    // return the matched length and its state
    int _search(string &word, int &state) {
        int sz = word.size();
        int mlen = 0;
        state = 0;
        while (mlen < sz) {
            char c = word[mlen];
            int code = ('a' <= c && c <= 'z' ? c-'a' : 26);
            if (mat_[state][code] >= 0) state = mat_[state][code];
            else break;
            mlen++;
        }
        return mlen;
    }

    void insert(string word) {
        word += "#";
        int sz = word.size();
        int state;
        int mlen = _search(word, state);
        if (mlen == sz) return;

        // add new states
        while (mlen < sz) {
            char c = word[mlen];
            int code = ('a' <= c && c <= 'z' ? c-'a' : 26);
            mat_.push_back(vector<int>(27, -1));
            mat_[state][code] = mat_.size()-1;
            state = mat_.size()-1;
            mlen++;
        }
    }

    bool search(string word) {
        word += "#";
        int state;
        return _search(word, state) == word.size();
    }
    
    bool startsWith(string prefix) {
        int state;
        return _search(prefix, state) == prefix.size();
    }
};

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
