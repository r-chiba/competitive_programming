#include <iostream>
#include <string>
using namespace std;

string str;

char symbols[] = ".,!? ";
char first[] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};

string solve()
{
    string ret;
    int i = 0;
    while(i < str.size()){
        int c, n = 0,count = 0;
        while((c = str[i++]) != '0'){
            if(count == 0) n = c;
            count++;
        }
        if(n==0) continue;
        count--;
        //cout << (char)n << " " << count << endl;
        //cout << (char)n << "*" << count << "+";
        n -= '0';
        //cout << n << "*" << count << "+";
        if(n == 1) ret += symbols[count%5];
        else{
            int len = (n == 7 || n == 9) ? 4 : 3;
            ret += static_cast<char>(first[n-2] + count % len);
        }
    }
    //cout << endl;
    return ret;
}

int main()
{
    int m;
    cin >> m;
    while(m--){
        cin >> str;
        //cout << str << endl;
        cout << solve() << endl;
    }
    return 0;
}
