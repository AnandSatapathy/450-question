//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
        // Method 1
// TC is O(2^n) so this is naive recursion (to understand logic) -> will give TLE
    int knapsackRes(int wt[], int val[], int ind, int W)
    {

        if(ind == 0){
            if(wt[0] <=W) return val[0];lse return 0;
        }
        
        
        int notTaken = 0 + knapsackRes(wt,val,ind-1,W);
        
        int taken = INT_MIN;
        if(wt[ind] <= W)
            taken = val[ind] + knapsackRes(wt,val,ind-1,W-wt[ind]);
            
        return max(notTaken,taken);
}

int knapsackMem(int wt[], int val[], int ind, int W,vector<vector<int>>&dp)
    {

        if(ind == 0){
            if(wt[0] <=W) return val[0];
            else return 0;
        }
        
        if(dp[ind][W]!=-1)
        return dp[ind][W];
        int notTaken = 0 + knapsackMem(wt,val,ind-1,W,dp);
        
        int taken = INT_MIN;
        if(wt[ind] <= W)
            taken = val[ind] + knapsackMem(wt,val,ind-1,W-wt[ind],dp);
            
        return dp[ind][W]=max(notTaken,taken);
}

int knapsackTab(int wt[], int val[], int n, int W){
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int w = wt[0];w<=W;w++){
        dp[0][w] = val[0];
    }
    for(int ind = 1;ind<=n-1;ind++){
        for(int cap=0; cap<=W; cap++){
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    return dp[n-1][W];
}
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   return knapsackRes(wt, val, n-1, W);
    //   vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    //   return knapsackMem(wt,val,n-1,W,dp);
       return knapsackTab(wt, val, n, W);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
    return 0;
}
// } Driver Code Ends