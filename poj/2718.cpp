// {{{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

void init()
{
}

void print_vec(vector<int> &v)
{
    size_t s = v.size();
    for(size_t i= 0; i < s-1; i++){
        cout << v[i] << ", ";
    }
    cout << v[s-1] << endl;
}

int vec_to_int(vector<int> &v)
{
    int ret = 0;
    int size = static_cast<int>(v.size());
    REP(i, size){
        ret *= 10;
        ret += v[i];
    }
    return ret;
}

int vec_to_int2(vector<int> &v, int begin, int end)
{
    int ret = 0;
    FOR(i, begin, end){
        ret *= 10;
        ret += v[i];
    }
    return ret;
}

void solve(vector<int> &digits)
{
    int ret = INF;
    int n = digits.size();
    do{
        int i = n >> 1;
        //if(digits[0] == 0 || digits[i] == 0) continue;
        if(digits[0] == 0) swap(digits[0], digits[1]);
        if(digits[i] == 0) swap(digits[i], digits[i+1]);
        int diff = vec_to_int2(digits, 0, i) - vec_to_int2(digits, i, n);
        int abs_diff = diff >= 0 ? diff : -diff;
        //cout << abs_diff << ": " << vec_to_int2(digits, 0, i) << " " << vec_to_int2(digits, i, n) << endl;
        ret = min(ret, abs_diff);
    }while(next_permutation(digits.begin(), digits.end()));
    cout << ret << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n_lines;
    cin >> n_lines;
    cin.ignore();
    REP(i, n_lines){
        string line;
        getline(cin, line);
        stringstream ss;
        ss << line;
        int ds[10];
        int cnt;
        for(cnt = 0; !ss.eof(); cnt++){
            ss >> ds[cnt];
        }
        vector<int> digits(ds, ds+cnt);
        sort(digits.begin(), digits.end());
        solve(digits);
    }
    return 0;
}

// vim:set foldmethod=marker:
