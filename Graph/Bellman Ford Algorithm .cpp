// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int>dist(n,INT_MAX);
	    dist[0]=1;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<edges.size();j++){
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int wt = edges[j][2];
	            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
	            {
	                dist[v]=dist[u]+wt;
	            }
	        }
	    }
	    // checking for the negative cycle
	    bool flag = false;
	 
	        for(int j=0;j<edges.size();j++){
	            int u = edges[j][0];
	            int v = edges[j][1];
	            int wt = edges[j][2];
	            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
	            {
	                flag =true;
	            }
	        }
	   if(flag)return 1;
	   else return 0;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends