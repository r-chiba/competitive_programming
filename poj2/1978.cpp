#include <iostream>
using namespace std;

const int MAX = 50;
int n, r;
int ps[MAX];
int cs[MAX];
int cards[2][MAX];

void init()
{
    for(int i = 0; i < MAX; i++){
        ps[i] = 0;
        cs[i] = 0;
        cards[0][i] = cards[1][i] = i+1;
    }
}

void print(int i)
{
    for(int j = 0; j < n; j++){
        cout << cards[i%2][j] << " ";
    }
    cout << endl;
}

int solve()
{
    for(int i = 1; i <= r; i++){
        int p = ps[i-1];
        int c = cs[i-1];
        for(int j = 0; j < n; j++) cards[i%2][j] = cards[(i-1)%2][j];
        int p_idx = n - p;
        int upper = p - 1;
        for(int j = 0; j < upper; j++){
            cards[i%2][p_idx-c+1 + j] = cards[(i-1)%2][p_idx+1 + j];
        }
        for(int j = 0; j < c; j++){
            cards[i%2][p_idx-c+1+upper + j] = cards[(i-1)%2][p_idx-c+1 + j];
        }
    }
    return cards[r%2][n-1];
}

int main()
{
    while(true){
        init();
        cin >> n >> r;
        if(n == 0 && r == 0) break;
        for(int i = 0; i < r; i++){
            cin >> ps[i] >> cs[i];
        }
        cout << solve() << endl;
    }
    return 0;
}
