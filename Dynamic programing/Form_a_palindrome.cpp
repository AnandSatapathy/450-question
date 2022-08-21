   #include<bits/stdc++.h> 
using namespace std; 
//  using the concept of LCS and also reverse the string 
class Solution{   
public:
    int findMinInsertions(string s){
        int n = s.length();
        string p = s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = 0;i<=n;i++)dp[i][0]=0;
            for(int j =0;j<=n;j++)dp[0][j]=0;
            
            // this line for the string matching
        
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(s[i-1]==p[j-1])
                    {
                        dp[i][j]=1+dp[i-1][j-1];
                        
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        return n-dp[n][n];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
