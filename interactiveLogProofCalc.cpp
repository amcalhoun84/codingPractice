#include <bits/stdc++.h>
using namespace std;
// calculator of logs

double calculateLog(int n, int l)
{
    return log(n) / log(l);
}

bool verifyLog(int n, int l)
{
    double r = calculateLog(n, l);
    return r - trunc(r) < 0.00001;
}

int main()
{
    int n, l;
    
    cout << "Put in your number >> ";
    cin >> n;
    cout << endl << "What would you like to know it is a power of? >> ";
    cin >> l;
    
    if(verifyLog(n, l)) cout << n << " is a power of " << l << endl;
    else cout << n << " is not a power of " << l << endl;
    
    
    return 0;
}
