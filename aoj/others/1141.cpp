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

int a, d, n;
int primes[210];

bool is_prime(int val)
{
    if(val < 2) return false;

    FOR(i, 2, static_cast<int>(floor(sqrt(val)))+1){
        if(val % i == 0) return false;
    }
    return true;
}

void init()
{
    REP(i, 210) primes[i] = 0;
}

void solve()
{
    int val = a;
    REP(i, n){
        while(true){
            bool p = false;
            if(is_prime(val)){
                primes[i] = val;
                p = true;
            }
            val += d;
            if(p) break;
        }
    }
    cout << primes[n-1] << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){
        cin >> a >> d >> n;
        if(a == 0 && d == 0 && n == 0) break;
        init();
        solve();
    }
    return 0;
}
