#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> PI;

const int MAX = 20;
const int INF = 1000000;
int m[MAX][MAX];
int w, h;
P s;
P g;
int min_d;
const int dxs[] = {1, 0, -1, 0};
const int dys[] = {0, 1, 0, -1};

void init()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            m[i][j] = 1;
        }
    }
    min_d = INF;
}

int solve()
{
    stack<PI> state_s;
    stack<P> broken_s;
    state_s.push(PI(s, 0));
    while(!state_s.empty()){
        PI &state_d = state_s.top();
        P &state = state_d.first;
        int d = state_d.second;
        cout << state.first << " " << state.second << endl;
        state_s.pop();
        if(state == g){
            min_d = min(min_d, d);
        }else if(d > 10){
            continue;
        }
        else{
            for(int i = 0; i < 4; i++){
                int j = 1;
                while(0 <= state.first + dxs[i]*j && state.first + dxs[i]*j < h
                        && 0 <= state.second + dys[i]*j && state.second + dys[i]*j < w){
                    if(m[state.first + dxs[i]*j][state.second + dys[i]*j] == 3) break;
                    if(m[state.first + dxs[i]*j][state.second + dys[i]*j] == 1){
                        j--;
                        break;
                    }
                    j++;
                }
                if(j != 0 
                    && 0 <= state.first + dxs[i]*j && state.first + dxs[i]*j < h
                    && 0 <= state.second + dys[i]*j && state.second + dys[i]*j < w){
                    //cout << state.first + dxs[i]*j << " " << state.second + dys[i]*j << endl;
                    state_s.push(PI(P(state.first + dxs[i]*j, state.second + dys[i]*j), d+1));
                    broken_s.push(P(state.first+j+1, state.second));
                }
            }
        }
    }
    return min_d <= 10 ? min_d : -1;
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
        cout << solve() << endl;
    }
}
