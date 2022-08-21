#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
// dfs
	void dfs(int v,vector<int>&vist,vector<int>adj[],vector<int>&ans)
	{
		ans.push_back(v);
		if(!vist[v])
		{
			vist[v]=1;
			for(auto x:adj[v])
			{
				if(!vist[x])
				{
					dfs(x,vist,adj,ans);
				}
			}
		}
	}
	vector<int>dfsgraph(int V,vector<int> adj[])
	{
		vector<int>ans;
		vector<int>vist(V,0);
		for(int i=0;i<V;i++){
			if(!vist[i]){
				dfs(i,vist,adj,ans);
			}
		}
		return ans;
	}
};
int main()
{
	int t;
	cin>>t;
	vector<int>adj;
	while(t--){
		int V,E;
		cin>>V>>E;
		vector<int>adj[V];
		for(int i =0;i<V;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int>ans = obj.dfsgraph(V,adj);
		for(auto x:ans){
			cout<<x<<" ";
		}
		cout<<endl;

	}

	return 0;	
}