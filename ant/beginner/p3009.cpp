#include <iostream>
using namespace std;

typedef pair<int, int> P;

enum direction{
    LEFT = 0,
    RIGHT,
    TOP,
    BOTTOM,
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

const int MAX = 20;
const int INF = 1e3;
int m[MAX][MAX];
int w, h;
P s, g;

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            m[i][j] = -1;
        }
    }
}

int dfs(int x, int y, direction d, bool move)
{
    if((x < 0 || h <= x) || (y < 0 || w <= y)){
        return INF;
    }
    if (x == g.first && y == g.second){
        return 1;
    }
    if((0 <= x+dx[d] && x+dx[d] < h)
        && (0 <= y+dy[d] && y+dy[d] < w)
        && (m[x+dx[d]][y+dy[d]] == 1)
      ){
        if(move == true){
            m[x+dx[d]][y+dy[d]] = 0;
            int ret = INF;
            for(int i = 0 ; i < 4; i++){
                ret = min(ret, dfs(x, y, (direction)i, false));
            }
            ret += 1;
            m[x+dx[d]][y+dy[d]] = 1;
            return ret;
        }else{
            return INF;    
        }
    }else{
        return dfs(x+dx[d], y+dy[d], d, true);
    }
    return INF;
}

int main()
{
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        init();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> m[i][j];    
                if(m[i][j] == 2) s = P(i, j);
                else if(m[i][j] == 3) g = P(i, j);
            }    
        }
        int x = s.first, y = s.second;
        int d = INF;
        for(int i = 0; i < 4; i++){
            d = min(d, dfs(x, y, (direction)i, false));
        }
        if(d <= 10){
            cout << d << endl;
        }else{
            cout << -1 << endl;
        }
    }
}
