#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 10000;
const int INF = 1e8;

typedef pair<int, int> P;
struct edge{
    int to;
    int dis;
    int cost;
};
int d[MAX_N]; // 首都からの距離
int c[MAX_N]; // 首都からのコスト
vector<edge> v[MAX_N]; // 隣接リスト

void init()
{
    for(int i = 0; i < MAX_N; i++){
        v[i].clear();
        d[i] = INF;
        c[i] = INF;
    }
    d[0] = 0;
    c[0] = 0;
}

int main()
{
    while(true){
        int n, m;
        int u, vv, dis, cost, p;
        int mincost = 0;
        // first: 首都からの距離, second: 都市
        // priority_queueを使って距離が小さいものから出す
        // 最小距離が決まった都市をqueueに入れる
        priority_queue<P, vector<P>, greater<P> > q;
        init();
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i = 0; i < m; i++){
            cin >> u >> vv >> dis >> cost;
            u--;
            vv--;
            v[u].push_back((edge){vv, dis, cost});
            v[vv].push_back((edge){u, dis, cost});
        }
        q.push(P(0, 0));
        while(q.size() != 0){
            dis = q.top().first;
            p = q.top().second;
            q.pop();
            if(d[p] < dis) continue;
            mincost += c[p];
            for(int i = 0; i < v[p].size(); i++){
                edge &e = v[p][i];
                if(d[e.to] > d[p] + e.dis){
                    // 首都からの距離が最小のものを使う
                    d[e.to] = d[p] + e.dis;
                    c[e.to] = e.cost;
                    q.push(P(d[e.to], e.to));
                }else if(d[e.to] == d[p] + e.dis){
                    // 距離が同じ場合はコストが小さいものを使う
                    c[e.to] = min(c[e.to], e.cost);
                }
            }
        }
        cout << mincost << endl;
    }
    return 0;
}
