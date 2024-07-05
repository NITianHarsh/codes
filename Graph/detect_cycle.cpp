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
bool cycleBFS(int V, vector<int> adj[]){
	queue<int>q; int count = 0;
    vector<int>indegree(V, 0);
    // finding Indegree
	for(int i=0; i<V; i++){
	    for(int j=0; j<adj[i].size(); j++){
	        indegree[adj[i][j]]++;
	    }
    }
    // simple BFS with cond. indegree = 0 -> q.push();
    for(int i=0; i<V; i++){
        if(indegree[i]==0) q.push(i); count++;
    }
    
    while(!q.empty()){
        int front=q.front();  q.pop();
        
        for(int i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i); count++;
        }
    }
    if(count == V) return false; // means kanh algo complete, thus No cycle
    return true;
}

