#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 1000;
const int INF = 1e8;

int d[MAX_N][MAX_N]; // d[i][j]は船が地点jに存在する場合の，ルート上のi+1番目の地点までの最短距離
int dl[MAX_N][MAX_N]; // 陸上ルートのみを用いたときの最短距離
int ds[MAX_N][MAX_N]; // 海上ルートのみを用いたときの最短距離
int route[MAX_N]; // 通るルート
int n, m, r;

void init()
{
    for(int i = 0; i < MAX_N; i++){
        route[i] = 0;
        for(int j = 0; j < MAX_N; j++){
            d[i][j] = INF;
            dl[i][j] = i==j ? 0 :INF;
            ds[i][j] = i==j ? 0 :INF;
        }
    }
}

void solve()
{
    // ワーシャル・フロイド法で陸上・海上のみの最短距離を求める
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dl[i][j] = min(dl[i][j], dl[i][k] + dl[k][j]);
                ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
            }
        }
    }
    d[0][route[0]] = 0;
    for(int i = 0; i < r-1; i++){
        int cur = route[i];
        int nxt = route[i+1];
        for(int j = 0; j < n; j++){
            // 陸地のみを通る場合
            d[i+1][j] = min(d[i+1][j], d[i][j] + dl[cur][nxt]);
            for(int k = 0; k < n; k++){
                // 海上を経由する場合
                d[i+1][k] = min(d[i+1][k], d[i][j] + dl[cur][j] + ds[j][k] + dl[k][nxt]);
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < n; i++) ans = min(ans, d[r-1][i]);
    cout << ans << endl;
}

int main()
{
    while(true){
        int x, y, c;
        char t;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        init();
        for(int i = 0; i < m; i++){
            cin >> x >> y >> c >> t;
            x--; y--;
            if(t == 'L') dl[x][y] = dl[y][x] = min(dl[x][y], c);
            else ds[x][y] = ds[y][x] = min(ds[x][y], c);
        }
        cin >> r;
        for(int i = 0; i < r; i++){
            cin >> route[i];
            route[i]--;
        }
        solve();
    }
    return 0;
}
