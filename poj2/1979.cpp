#include <iostream>
using namespace std;

typedef pair<int, int> P;

const int MAX = 20;
char m[MAX][MAX];
int w, h;
P s;

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            m[i][j] = '#';
        }
    }
}

int dfs(int x, int y)
{
    int ret = 1;
    m[x][y] = 0;
    if(m[x+1][y] == '.') ret += dfs(x+1, y);
    if(m[x-1][y] == '.') ret += dfs(x-1, y);
    if(m[x][y+1] == '.') ret += dfs(x, y+1);
    if(m[x][y-1] == '.') ret += dfs(x, y-1);
    return ret;
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
                if(m[i][j] == '@') s = P(i, j);
            }    
        }
        cout << dfs(s.first, s.second) << endl;
    }
}
