// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int dp[501][501];
   //  ispalindrome or not
   bool ispalindrome(string &s, int i , int j){
       while(i<=j){
           if(s[i]==s[j]){
               i++;
               j--;
           }
           else{
               return false;
           }
       }
       return true;
   }
   int solve(string &s, int i, int j)
   {
       if (i >= j)
       {
           return dp[i][j] = 0;
       }
       if(ispalindrome(s,i,j)){
           return dp[i][j] = 0;
       }
       if (dp[i][j] != -1)
       {
           return dp[i][j];
       }
       dp[i][j] = INT_MAX;
       for (int k = i; k <= j-1; k++)
       {
           dp[i][j] = min(dp[i][j], solve(s, i, k) + solve(s, k + 1, j) + 1 );
       }
       return dp[i][j];
   }
   int palindromicPartition(string str)
   {
       memset(dp,-1,sizeof(dp));
       return solve(str,0,str.size()-1);
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends