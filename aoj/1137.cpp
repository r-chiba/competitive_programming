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
string str1, str2;

void init()
{
}

int mcxi2int(string str){
    int ret = 0;
    char c;
    int digit = 1;
    REP(i, str.size()){
        c = str[i];
        if('0' <= c && c <= '9'){
            digit = c - '0';
        }else{
            int val;
            if(c == 'm') val = 1000;
            else if(c == 'c') val = 100;
            else if(c == 'x') val = 10;
            else if(c == 'i') val = 1;
            ret += digit * val;
            digit = 1;
        }
    }
    return ret;
}

string int2mcxi(int val){
    string ret;
    int denom = 1000;
    while(denom > 0){
        int digit = val / denom;
        char c;
        if(denom == 1000) c = 'm';
        else if(denom == 100) c = 'c';
        else if(denom == 10) c = 'x';
        else if(denom == 1) c = 'i';
        if(digit > 0){
            if(digit > 1) ret += static_cast<char>('0' + digit);
            ret += c;
            val -= digit * denom;
        }
        denom /= 10;
    }
    return ret;
}

void solve()
{
    int lhs = mcxi2int(str1);
    int rhs = mcxi2int(str2);
    //cout << lhs << " " << rhs << endl;
    string ans = int2mcxi(lhs + rhs);
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    while(n--){
        cin >> str1 >> str2;
        solve();
    }
    return 0;
}
