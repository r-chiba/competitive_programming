#include <iostream>
using namespace std;

typedef pair<int, int> P;

P treasure, current;
int max_d;

void init()
{
    max_d = 0;
    current = P(0, 0);
}

void solve()
{
}

int main()
{
    int n;
    cin >> n;
    while(n--){
        init();
        int dx, dy;
        while(true){
            cin >> dx >> dy;
            if(dx == 0 && dy == 0) break;
            current = P(current.first + dx, current.second + dy);
            //cout << current.first << " " << current.second << endl;
            int d = current.first*current.first + current.second*current.second;
            if(max_d == 0 || max_d < d || (max_d == d && treasure.first < current.first)){
                treasure = current;
                max_d = d;
            }
        }
        cout << treasure.first << " " << treasure.second << endl;
    }
    return 0;
}
