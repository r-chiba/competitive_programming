#include <iostream>
#include <algorithm>
using namespace std;

static const int MAX_N = 10;
static const int INF = 1e8;
int d[MAX_N][MAX_N];

void init()
{
    for(int i = 0; i < MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            d[i][j] = i==j ? 0 : INF;
        }
    }
}

void calc_min_dis(const int max_town)
{
    for(int k = 0; k <= max_town; k++){
        for(int i = 0; i <= max_town; i++){
            for(int j = 0; j <= max_town; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void check_conv_town(const int max_town, int &ret_town, int &ret_cost){
    ret_cost = INF;
    for(int i = 0; i <= max_town; i++){
        int s = 0;
        for(int j = 0; j <= max_town; j++){
            s += d[i][j];
        }
        if(ret_cost > s){
            ret_town = i;
            ret_cost = s;
        }
    }
}

int main()
{
    while(true){
        int n;
        int a, b, c;
        int max_town = -1;
        int min_town, min_cost;
        init();
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            cin >> a >> b >> c;
            d[a][b] = d[b][a] = c;
            max_town = max({max_town, a, b});
        }
        calc_min_dis(max_town);
        check_conv_town(max_town, min_town, min_cost);
        cout << min_town <<  " " << min_cost << endl;
    }
    return 0;
}
