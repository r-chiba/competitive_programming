#include <iostream>
using namespace std;

int n, q, max_date;
int dates[100];

void init()
{
    for(int i = 0; i < 100; i++){
        dates[i] = 0;
    }
    max_date = 0;
}

void solve()
{
}

int main()
{
    while(true){
        cin >> n >> q;
        if(n== 0 && q == 0) break;
        init();
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            for(int j = 0; j < m; j++){
                int date;
                cin >> date;
                dates[date]++;
                if(max_date < date) max_date = date;
            }
        }
        int ans = 0;
        for(int i = 1; i <= max_date; i++){
            if(dates[ans] < dates[i]) ans = i;
        }
        cout << ((dates[ans] >= q) ? ans : 0) << endl;
    }
    return 0;
}
