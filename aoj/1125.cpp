#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define pb(a) push_back(a)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
const ll LINF = 10000000000000000ll;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

int n;
int w, h, s, t;
P pers[500];
int max_per;

void init()
{
    REP(i, 500) pers[i] = P(0, 0);
    max_per = 0;
}

void solve()
{
    REP(i, w){
        REP(j, h){
            int n_pers = 0;
            REP(k, n){
                if(i <= pers[k].first && pers[k].first < i + s
                    && j <= pers[k].second && pers[k].second < j + t){
                    n_pers += 1;
                }
            }
            if(max_per < n_pers) max_per = n_pers;
        }
    }
    cout << max_per << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){
        cin >> n;
        cin >> w >> h;
        if(n == 0) break;
        init();
        REP(i, n){
            int x, y;
            cin >> x >> y;
            pers[i] = P(x-1, y-1);
        }
        cin >> s >> t;
        solve();
    }
    return 0;
}
