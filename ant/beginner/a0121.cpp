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

int cards[8];
map<int, int> m;

void init()
{
    m.clear();
}

int find(vector<int> &v, int val)
{
    size_t size = v.size();
    REP(i, static_cast<int>(size)){
        if(v[i] == val) return i;
    }
    return -1;
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
    REP(i, 8){
        ret *= 10;
        ret += v[i];
    }
    return ret;
}

int arr_to_int(int *v)
{
    int ret = 0;
    REP(i, 8){
        ret *= 10;
        ret += v[i];
    }
    return ret;
}

void solve()
{
    int ret;
    queue<pair<int, vector<int> > > q;
    vector<int> v_initial{0, 1, 2, 3, 4, 5, 6, 7};
    q.push(mp(0, v_initial));
    while(!q.empty()){
        int t = q.front().fi;
        vector<int> v = q.front().se;
        q.pop();
        int val = vec_to_int(v);
        if(m[val] != 0) continue;
        if(val != 1234567) m[val] = t;
        int idx0 = find(v, 0);
        if(idx0 != 0 && idx0 != 4){
            vector<int> v1(v);
            swap(v1[idx0], v1[idx0-1]);
            q.push(mp(t+1, v1));
        }
        if(idx0 != 3 && idx0 != 7){
            vector<int> v1(v);
            swap(v1[idx0], v1[idx0+1]);
            q.push(mp(t+1, v1));
        }
        if(idx0 < 4){
            vector<int> v1(v);
            swap(v1[idx0], v1[idx0+4]);
            q.push(mp(t+1, v1));
        }
        else{
            vector<int> v1(v);
            swap(v1[idx0], v1[idx0-4]);
            q.push(mp(t+1, v1));
        }
    }
    //cout << ret << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    while(true){
        cin >> cards[0];
        if(cin.eof()) break;
        REP(i, 7) cin >> cards[i+1];
        cout << m[arr_to_int(cards)] << endl;
    }
    return 0;
}

// vim:set foldmethod=marker:
