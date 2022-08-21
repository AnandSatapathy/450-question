// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool cyclevisted(int i,int V,vector<int>&vist,vector<int> adj[])
    {
        queue<pair<int,int>> q;
        if(!vist[i]){
            q.push({i,-1});
            vist[i]=true;
            while(!q.empty())
            {
                int node = q.front().first;
                int prev = q.front().second;
                q.pop();
                for(auto it:adj[node])
                {
                    if(!vist[it]){
                    vist[it]=true;
                    q.push({it,node});
                    }
                    else if(prev!=it)
                            return true;
                    
                    
                }
            }
            
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vist(V,0);
        for(int i =0;i<V;i++){
            if(!vist[i])
                if(cyclevisted(i,V,vist,adj)) return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends