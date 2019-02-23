#include <iostream>
#include <cmath>
using namespace std;

typedef struct operation{
    bool simple;
    double rate;
    int charge;
} operation;

int initial;
int year;
int n;
operation ops[100];
int max_amount;

int solve()
{
    max_amount = 0;
    for(int i = 0; i < n; i++){
        int base = initial;
        int profit = 0;
        for(int j = 0; j < year; j++){
            if(ops[i].simple){
                profit += static_cast<int>(floor(base * ops[i].rate));
            }else{
                base += base * ops[i].rate;
            }
            base -= ops[i].charge;
        }
        int amount = base + profit;
        max_amount = max(max_amount, amount);
    }
    return max_amount;
}

int main()
{
    int m;
    cin >> m;
    while(m--){
        cin >> initial;
        cin >> year;
        cin >> n;
        for(int i = 0; i < n; i++){
            int simple;
            cin >> simple;
            ops[i].simple = simple == 0;
            cin >> ops[i].rate;
            cin >> ops[i].charge;
        }
        cout << solve() << endl;
    }
    return 0;
}
