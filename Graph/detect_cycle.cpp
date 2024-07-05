#include<bits/stdc++.h>
using namespace std;

//----------Cycle in Undirected Graph
// Using DFS 
bool cycleDfs(int node, vector<bool>vis, vector<int>adj[], int parent){
    vis[node] = true;
    for(int i: adj[node]){ 
        if(i == parent) continue;
        if(vis[i] == 1) return true; // detected a loop
        if(cycleDfs(i, vis, adj, node)) return true;        
    }
    return false;
}


// Using BFS
bool cycleBFS(int i, vector<bool>vis, vector<int>adj[], int parent){
    queue<int>q; q.push(i);
    vis[i] = true;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(int j: adj[curr]){
            if(j == parent) continue;
            if(vis[j]) return true;
            if(cycleBFS(j, vis, adj, curr)) return true;
        }
    }
    return false;
}

//----------Cycle in Directed Graph
// Using DFS

bool cycleDFS(int node, vector<bool> &vis, vector<bool> &pathVis, vector<int>adj[]){
    vis[node] = true;
    pathVis[node] = true;
    for(int i : adj[node]){
        if(vis[i] && pathVis[i]) return true;
        if(!vis[i] && cycleDFS(i, vis, pathVis, adj)) return true;
    }
    pathVis[node] = false;
    return false;
}


// Using BFS
bool cycleBFS(int i, vector<bool>vis, vector<int>adj[], int parent){
    queue<int>q; q.push(i);
    vis[i] = true;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(int j: adj[curr]){
            if(j == parent) continue;
            if(vis[j]) return true;
            if(cycleBFS(j, vis, adj, curr)) return true;
        }
    }
    return false;
}

