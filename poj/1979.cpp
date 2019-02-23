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
    if(x < 0 || h <= x) return 0;
    if(y < 0 || w <= y) return 0;
    if(m[x][y] == '#') return 0;
    else{
        m[x][y] = '#';
        return dfs(x-1, y) + dfs(x+1, y) + dfs(x, y-1) + dfs(x, y+1) + 1;
    }
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
        //for(int i = 0; i < h; i++){
        //    for(int j = 0; j < w; j++){
        //        cout << m[i][j] << " ";    
        //    }    
        //    cout << endl;    
        //}
    }
}
