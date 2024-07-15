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


// shortest path in a Undirected Graph
// BFS

vector<int> shortestPathBFS(int V, vector<vector<int>> &adj, int src) {
    vector<int> distance(V, -1);
    queue<int> q;
    distance[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (distance[neighbor] == -1) {  // if the neighbor has not been visited
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance;
}