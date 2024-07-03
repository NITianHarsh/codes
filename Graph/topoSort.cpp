#include<bits/stdc++.h>
using namespace std;

// TopoLogical Sorting

// Using DFS

void topoDFS(int node, vector<bool> &vis, vector<int>adj[], stack<int> &s){
    vis[node] = true;
    for(int i: adj[node]){
        if(!vis[i]){
            topoDFS(i, vis, adj, s);
        }
    }
    s.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]){
    vector<bool>vis(V, false);
    stack<int>s; vector<int>ans;
    ans.reserve(V);
    for(int i=0; i<V; i++){
        if(!vis[i]) topoDFS(i, vis, adj, s);
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// Using BFS  i.e., KAHN'S ALGORITHM
vector<int> kahnAlgo(int V, vector<int> adj[]){
	    queue<int>q;
	    vector<int>indegree(V, 0);
	    vector<int>ans;
	    // finding Indegree
	    for(int i=0; i<V; i++){
	        for(int j=0; j<adj[i].size(); j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    // simple BFS with cond. indegree = 0 -> q.push();
	    for(int i=0; i<V; i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int front=q.front();  q.pop();
	        ans.push_back(front);
	        
	        for(int i:adj[front]){
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	    }
	    return ans;
	}