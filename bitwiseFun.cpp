#include <bits/stdc++.h>
using namespace std;

void oddEven(int x)
{
    if(x & 1) cout << x << " is odd." << endl;
    else cout << x << " is even." << endl;
}

void oppositeSign(int x, int y)
{
    if((x ^ y) < 0) cout << x << " and " << y << " have opposite signs." << endl;
    else cout << x << " and " << y << " do not have opposite signs." << endl;
}


int main()
{
    int n = 5;
    int o = 6;
    
    oddEven(5);
    oddEven(6);
    
    cout << endl << endl;
    
    int a = 42;
    int b = -33;
    
    int c = 21;
    
    oppositeSign(a, b);
    oppositeSign(a, c);
    oppositeSign(b, c);
    
    
    return 0;
    
}
