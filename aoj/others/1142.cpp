#include <iostream>
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
using namespace std;

#define pb push_back
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> IP;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int INF = 100000000;
const ll LINF = 10000000000000000ll;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

string s;

void init()
{
}

int solve()
{
    int len = s.size();
    set<string> ss;
    FOR(i, 1, len){
        string s1, s2;
        s1 = s.substr(0, i);
        s2 = s.substr(i, len - i);
        vector<string> vv;
        string c1(s1), c2(s2);
        reverse(ALL(c1));
        reverse(ALL(c2));
        ss.insert(s1+s2);
        ss.insert(s2+s1);
        ss.insert(s1+c2);
        ss.insert(c2+s1);
        ss.insert(c1+s2);
        ss.insert(s2+c1);
        ss.insert(c1+c2);
        ss.insert(c2+c1);
    }
    return ss.size();
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    while(n--){
        cin >> s;
        cout << solve() << endl;
    }
    return 0;
}
