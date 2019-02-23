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
int coins[] = {10, 50, 100, 500};
int cs[4];

void init()
{
    REP(i, 4) cs[i] = 0;
}

void solve()
{
    int ret[] = {0, 0, 0, 0};
    int sum = 0;
    REPR(i, 3){
        sum += coins[i] * cs[i];
    }
    int returned = sum - n;
    REPR(i, 3){
        ret[i] = cs[i];
        while(returned >= coins[i]){
            ret[i] -= 1;
            returned -= coins[i];
        }
    }
    REP(i, 4){
        if(ret[i] > 0) cout << coins[i] << " " << ret[i] << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    bool first = true;
    while(true){
        cin >> n;
        if(n == 0) break;
        if(!first) cout << endl;
        init();
        REP(i, 4) cin >> cs[i];
        solve();
        first = false;
    }
    return 0;
}
