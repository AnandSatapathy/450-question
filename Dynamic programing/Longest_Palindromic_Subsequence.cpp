#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
   int lcs(string s,string t)
    {
        int n = s.length();
        int m = t.length();
        
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
            
            //  making the diagonal the of the zero ;
            for(int i = 0;i<=n;i++)dp[i][0]=0;
            for(int j =0;j<=m;j++)dp[0][j]=0;
            
            // this line for the string matching
        
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=m;j++){
                    if(s[i-1]==t[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                        
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        return dp[n][m];
    }
    int longestPalinSubseq(string A) {
        string t = A;
        reverse(t.begin(),t.end());
        return lcs(A,t);
    }
};
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
