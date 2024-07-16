#include<bits/stdc++.h>
using namespace std;

// Shortest Distance in a Directed Acyclic Graph,  now the graph may or maynot be weighted, assuming weighted
// using topo sort

// DFS

// get the stack from topo sort and then use distance method
void topo(int node, stack<int> &st, vector<int> &vis, vector<vector<pair<int, int>>> &adj) {
    vis[node] = true;
    for (auto i : adj[node]) {
        if (!vis[i.first]) {
            topo(i.first, st, vis, adj);
        }
    }
    st.push(node);
}

vector<int> shorDis(vector<vector<pair<int, int>>> &adj, int V) {
    stack<int> st;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            topo(i, st, vis, adj);
        }
    }

    vector<int> dis(V, INT_MAX);
    dis[0] = 0;  // Assuming we need to find shortest distance from node 0

    while (!st.empty()) {
        int curr = st.top();
        st.pop();

        if (dis[curr] != INT_MAX) {
            for (auto it : adj[curr]) {
                int node = it.first;
                int w = it.second;

                dis[node] = min(dis[curr] + w, dis[node]);           
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dis[i] == INT_MAX) dis[i] = -1;
    }
    return dis;
}


// shortest path in a Undirected Graph with unit wt nodes
// BFS

vector<int> shortestPathBFS(int V, vector<vector<int>> &adj, int src) {
    queue<pair<int,int>> q;
    vector<int> dis(V, 1e9);
    dis[src] = 0;
        
    q.push({src, 0});
    while(!q.empty()){
        int cr = q.front().first;
        int cw = q.front().second;
        q.pop();

        for(int i: adj[cr]){
            if(1 + cw < dis[i]){
                dis[i] = 1 + cw;
                q.push({i, dis[i]});
            }
        }
    }
        
    for(int i=0; i<V; i++){
        if(dis[i] == 1e9) dis[i] = -1;
    }
    return dis;
}