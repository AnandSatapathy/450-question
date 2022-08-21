#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, source;
    cin >> n >> m >> source;
    vector<pair<int, int>> g[n + 1]; // 1-index adjacency list for of graph;
    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        g[a].push_back({b, wt});
        g[b].push_back({a, wt});
    }
    
    // dijkstra algorithm begins from here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap; In pair=>(dist)
    vector<int> distTo(n + 1, INT_MAX);
    distTo[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for (auto it : g[prev])
        {
            int next = it.first;
            int nextDist = it.second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push({distTo[next], next});
            }
        }
    }
    cout<<"The distance from Source"<<source<<",are:\n";
    for(int i=1;i<=n;i++) cout<<distTo[i]<<"";
    cout<<"\n";

    return 0;
}