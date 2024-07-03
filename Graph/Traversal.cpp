#include<bits/stdc++.h>
using namespace std;

// Depth First Search
void dfs(int node, vector<bool>vis, vector<int>adj[], vector<int>ans){
    ans.push_back(node);
    vis[node] = true;
    for(int i: adj[node]){
        if(!vis[i]) ans.push_back(i); vis[i] = true;
    }
}


// Breadth first search
void bfs(int node, vector<bool>vis, vector<int>adj[], vector<int>ans){
    queue<int>q;
    q.push(node); vis[node] = true;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        ans.push_back(curr);
        for(int i: adj[curr]){
            if(!vis[i]) q.push(i); vis[i] = true;
        }
    }
}