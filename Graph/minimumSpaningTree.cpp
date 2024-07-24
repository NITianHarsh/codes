// Spaning Tree is a tree or graph in which all nodes reachable from every other node
// A minimum spaning tree (MST) is a spaning tree with minumum edge weight

#include<bits/stdc++.h>
using namespace std;

// 1. Prim's Algorithm

int primMST(int V, vector<vector<pair<int, int>>> &adj) {
    vector<pair<int, int>> ans; // to store the configuration of MST
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // { weight, {node, parent} }
    vector<int> vis(V, 0);
    pq.push({0, {0, -1}});
    int sum = 0;
    
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        int wt = x.first, nod = x.second.first, par = x.second.second;
    
        if (vis[nod]) continue;
        if (par != -1) {
            ans.push_back({nod, par});
            sum += wt;
        }
        vis[nod] = 1;
        
        for (auto y : adj[nod]) {
            int node = y.first;
            int weight = y.second;
            if (!vis[node]) {
                pq.push({weight, {node, nod}});
            }
        }
    }
    return sum;
}
