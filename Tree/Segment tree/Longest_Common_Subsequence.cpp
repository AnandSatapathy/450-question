
#include <bits/stdc++.h>
using namespace std;


int dp[1001][1001];
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{

	if (m == 0 || n == 0)
		return 0;
		if(dp[m][n]!=-1)return dp[i][j];
	if (X[m-1] == Y[n-1])
		return dp[n][m]=1 + lcs(X, Y, m-1, n-1);
	else
		return dp[n][m]=max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}




int main()
{
    memset(dp,-1,sizeof(dp));
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
	
	return 0;
}

// This code is contributed by rathbhupendra
