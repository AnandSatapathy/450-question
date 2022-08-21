#include<bits/stdc++.h>
#define INF INT_MAX 
using namespace std;
// using the concept of topsort
void findTopoSort(int node,vector<int>&vist,stack<int>&st,vector<pair<int,int>>adj[])
{
	vist[node]=1;
	for( auto i:adj[node] )
	{
		if(!vist[i.first]){
				findTopoSort(i.first, vist, st, adj); 
		}
	}
	st.push(node);
}

void shortestPath(int src,int node ,vector<pair<int,int>>adj[])
{
	vector<int>vist(node,0);
	stack<int> st;
	for(int i=0;i<node;i++){
		if(!vist[i]){
			findTopoSort(i, vist, st, adj); 
		}
	}
	// after store the value in the distance array
	int dist[node];
	for(int i=0;i<node;i++){
		dist[i]=INF;
	}
	dist[src]=0;
	while(!st.empty()){
		int n = st.top();
		st.pop();
		if(dist[n]!=INF){
			for( auto it:adj[n]){
				if(dist[n]+it.second<dist[it.first]){
					dist[it.first] = dist[node] + it.second; 
				}
			}
		}
	}
	for (int i = 0; i <node; i++) 
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
}
int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>>adj[n];
	for(int i=0;i<n;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
		
	}
	shortestPath(0, n, adj); 

	return 0; 
}