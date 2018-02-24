#include <bits/stdc++.h>
using namespace std;

// let's try something with dynamic programming.

int DPLCS(string X, string Y)
{
    int m = X.length(), n = Y.length();
    
    int lookup[m+1][n+1];
    for(int i=0; i <=m; i++) lookup[i][0] = 0;
    for(int j=0; j <=n; j++) lookup[0][j] = 0;
    
    for(int i = 1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(X[i-1] == Y[j-1]) lookup[i][j] = lookup[i-1][j-1] + 1;
            else lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
            
    
        }
    }
    
    return lookup[m][n];
}


// less effective...

int LCS(string X, string Y, int m, int n)
{
	if(m == 0 || n == 0) return 0;
	if(X[m - 1] == Y[n - 1])
		return LCS(X, Y, m - 1, n - 1) + 1;

	return max(LCS(X, Y, m, n - 1), LCS(X, Y, m - 1, n));
}

int main()
{
	string X = "ABCBDAB", Y = "BDCABA";

	cout << "The length of LCS is " << LCS(X, Y, X.length(), Y.length()) << endl;
	cout << "The length of Dynamic Programming LCS is " << DPLCS(X, Y) << endl;
	return 0;
}
