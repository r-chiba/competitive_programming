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

enum direction{
    top = 1,
    right,
    bottom,
    left,
};
struct line{
    direction d;
    int len;
};
struct polygonal{
    int n;
    line lines[10];

    polygonal& operator=(const polygonal &x){
        n = x.n;
        REP(i, n){
            lines[i].d = x.lines[i].d;
            lines[i].len = x.lines[i].len;
        }
        return *this;
    }
    bool operator==(const polygonal &x){
        if(n != x.n) return false;
        int diff;
        bool ret = true;
        REP(k, 2){
            line ls[10];
            REP(i, n){
                ls[i] = k == 0 ? x.lines[i] : x.lines[n-1-i];
            }
            REP(i, n){
                if(lines[i].len != ls[i].len){
                    ret = false;
                    break;
                }
                if(i == 0){
                    diff = ls[i].d - lines[i].d;
                    if(diff < 0) diff += 4;
                    //cout << diff << "**";
                }
                int df;
                df = ls[i].d - lines[i].d;
                if(df < 0) df += 4;
                //cout << df << "*";
                if(df != diff || ls[i].len != lines[i].len){
                    ret = false;
                    break;
                }
            }
            //cout << endl;
            if(ret == true) break;
        }
        return ret;
    }

};

void print(const polygonal &x)
{
    REP(i, x.n){
        cout << x.lines[i].d << ":" << x.lines[i].len << " ";
    }
    cout << endl;
}

int n;
polygonal ps[51];

void init()
{
    REP(i, 51){
        ps[i].n = 0;
        REP(j, 10){
            ps[n].lines[j].d = direction::top;
            ps[n].lines[j].len = 0;
        }
    }
}

void solve()
{
}

polygonal make_polygonal(P *ps, int len)
{
    polygonal ret;
    ret.n = len - 1;
    int px, py;
    REP(j, len){
        int x, y;
        x = ps[j].first;
        y = ps[j].second;
        if(j > 0){
            direction d;
            int l;
            if(x - px == 0 && y - py > 0) d = direction::top;
            else if(x - px == 0 && y - py < 0) d = direction::bottom;
            else if(x - px > 0 && y - py == 0) d = direction::right;
            else if(x - px < 0 && y - py == 0) d = direction::left;
            l = max(abs(x - px), abs(y - py));
            ret.lines[j-1].d = d;
            ret.lines[j-1].len = l;
        }
        px = x;
        py = y;
    }
    return ret;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(true){
        cin >> n;
        if(n == 0) break;
        init();
        REP(i, n+1){
            int m;
            int px, py;
            cin >> m;
            P points[10];
            REP(j, m){
                int x, y;
                cin >> x >> y;
                points[j] = P(x, y);
            }
            if(i == 0){
                ps[i] = make_polygonal(points, m);
                //print(ps[i]);
            }else{
                bool pr = false;
                REP(ii, 2){
                    if(ii == 1) reverse(points, points+m);
                    //cout << "points: ";
                    //REP(l, m) cout << points[l].first << "#" << points[l].second << " ";
                    //cout << endl;
                    ps[i] = make_polygonal(points, m);
                    //print(ps[i]);
                    if(ps[0] == ps[i]){
                        pr = true;
                        cout << i << endl;
                    }
                    if(pr == true) break;
                }
            }
        }
        cout << "+++++" << endl;
    }

    return 0;
}
