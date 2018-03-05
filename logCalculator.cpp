#include <bits/stdc++.h>
using namespace std;


double log8(unsigned n)
{
    return log(n) / log(8);
}

bool check2(unsigned n)
{
    double l = log2(n);
    cout << n << "'s log8 is " << l << endl;
    //cout << "Power of 2: " << l << endl;
    return l - trunc(l) < 0.00001;
    
}

bool check8(unsigned n)
{
    double l = log8(n);
    cout << n << "'s log8 is " << l << endl;
    return l - trunc(l) < 0.00001;
}


int main()
{    
    unsigned n = 512 * 64 * 8;
    
    if (check8(n) && !check2(n)) cout << n << " is a power of 8 but not 2." << endl;
    else if (check8(n) && check2(n)) cout << n << " is a power of 8 and 2." << endl;
    else if (check2(n) && !check8(n)) cout << n << " is a power of 2 but not 8." << endl;
    else cout << n << " is not a power of 8 or 2." << endl;
    
    
    
    return 0;
}
