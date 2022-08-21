#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int A[],int N,int mid,int s){
        int cnt = 0;
        int sumAllocated = 0;
        for(int i = 0;i<N;i++){
            if(sumAllocated+A[i]>mid){
                cnt++;
                sumAllocated = A[i];
                if(sumAllocated>mid)return false;
            }
            else{
                sumAllocated+=A[i];
            }
        }
        if(cnt<s)return true;
        return false;
    }
    int findPages(int A[], int N, int M) 
    {
        if(M>N)return -1;
        int low = INT_MAX;
        int high = 0;
        for(int i =0;i<N;i++){
            high+=A[i];
            low = min(low,A[i]);
        }
        
        // binary search codition
        int res = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(ispossible(A, N,mid,M)){
                res = mid;
                high = mid-1;
            }else
            {
                low = mid+1;
            }
        }
        return low;
        
    }
};



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends