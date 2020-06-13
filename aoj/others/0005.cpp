#include <iostream>
using namespace std;

typedef long long int ll;

int gcd(ll a, ll b)
{
    if(a > b) return gcd(b, a);
    else if (a == 0) return b;
    else return gcd(b%a, a);
}

int main()
{
    ll a, b, g;
    while(true){
        cin >> a >> b;
        if(cin.eof()) break;
        g = gcd(a, b);
        cout << g << " " << (a*b)/g << endl;
    }
}
