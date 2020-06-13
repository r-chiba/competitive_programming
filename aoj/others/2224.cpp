#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 10000;
const double INF = 1e8;

typedef pair<int, int> P;
typedef pair<double, int> PF;

int n, m;
vector<P> piles; // 頂点の座標
vector<PF> fences[MAX_N]; // 隣接リスト first: 距離, second: 終点

double dist(P p1, P p2)
{
   int dx = p1.first-p2.first;
   int dy = p1.second-p2.second;
   return sqrt(dx*dx + dy*dy);
}

// 最小全域木ではなく最大全域木を求める
double prim()
{
    bool used[MAX_N];
    priority_queue<PF> q;
    for(int i = 0; i < piles.size(); i++){
        used[i] = false;
    }
    double res = 0.;
    // 元のグラフが連結でない場合があるので全頂点をキューに入れる
    for(int i = 0; i < piles.size(); i++) q.push(PF(0., i));
    while(q.size() != 0){
        double cost = q.top().first;
        int v = q.top().second;
        q.pop();
        if(used[v] == true) continue;
        used[v] = true;
        res += cost;
        for(int i = 0; i < fences[v].size(); i++){
            double c = fences[v][i].first;
            int u = fences[v][i].second;
            q.push(PF(c, u));
        }
    }
    return res;
}

void solve(double s)
{
    double res = prim();
    cout << fixed << s-res << endl;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        piles.push_back(P(x, y));
    }
    double s = 0.;
    for(int i = 0; i < m; i++){
        int p, q;
        cin >> p >> q;
        double d = dist(piles[p-1], piles[q-1]);
        fences[p-1].push_back(PF(d, q-1));
        fences[q-1].push_back(PF(d, p-1));
        s += d;
    }
    solve(s);
    return 0;
}
