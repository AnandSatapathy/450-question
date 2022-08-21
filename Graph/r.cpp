#include<bits/stdc++.h>
using namespace std;
// Step1:Kosaraaju algorithm
// Step 2:Top sort
// step 3: recerse the dfs
void dfs(int node,vector<int>adj[],vector<int>&vist)
{
	vist[node] =1;
	for(auto nbr:adj[node]){
		if(!vist[nbr]){
			dfs(nbr,adj,st,vist);
		}
	}


	st.push(node);


}
void revdfs(int node,vector<int>Trans[],vector<int>&vist)
{
	vist[node] =1;
	for(auto nbr:Trans[node]){
		if(!vist[nbr]){
			dfs(nbr,Trans,vist);
		}
	}
}



int main(){
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i=0;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	stack<int> st;
	vector<int> vist(n,0);
	for(int i=0;i<n;i++){
		if(!vist[i])
			dfs(i,adj,st,vist);
	}

	vector<int>Trans[n+1];
	for(int i=0;i<n;i++){
		vist[i]=0;
		for(auto it:adj[i]){
			Trans[it].push_back(i);
		}
	}

	while(!st.empty()){
		auto node= st.top();;
		st.pop();
		for(auto nbr:Trans[node]){
			if(!vist[nbr]){
				revdfs(nbr,Trans,vist);
			}
		}
	}
}