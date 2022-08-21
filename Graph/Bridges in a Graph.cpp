#include<bits/stdc++.h>
using namespace std;



void dfs(int node,int parent,vector<int>&adj,vector<int>&dis,int &timer,vector<int>&low,vector<int>&vist)
{
	vist[node]=1;
	low[node]=dis[node]=timer++;

	for(auto nbr:adj[node]){
		if(nbr==parent) continue;
		if(!vist[nbr]){
			  low[node] = min(low[node], low[nbr]); 
			  // this for check the bridge in node
            if(low[nbr] > tin[node]) {
                cout << node << " " << it << endl;
		}
		else
		{
			// check back
			 low[node] = min(low[node], tin[nbr]); 
		}
	}
}

int main()
{

	int n,m;
	cin>>n>>m;
	vector<int>adj(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int timer =0;
	vector<int> dis(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0); 

	int parent = -1;
	for(int i=0;i<n;i++){
		if(!vis[i])
			dfs(i,parent,adj,dis,timer,low,vist);
	}



	return 0;
}