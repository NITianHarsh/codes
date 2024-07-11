#include<bits/stdc++.h>
using namespace std;

// Bipartite graph : a graph which can be divided into parts, or if we color it with two diff color 
// then no adjacent node is of same color
// All graphs are Bipartie except odd cyclic graphs

// checking a graph is Bipartite or not 

// BFS
bool bipartiteBFS(int V, vector<int> adj[]){
    vector<int>col(V, -1); // not colorerd
    for(int i=0; i<V; i++){  // loop, in case different components
        queue<int>q;
        q.push(i);
        col[i] = 0; // initialise color of first node        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j : adj[node]){
                if(col[j] == col[node]) return false;
                if(col[j] == -1){
                    q.push(j);
                    col[j] = 1 - col[i];
                }
            }
        }
    }
    return true;
}


// DFS 
bool bipartiteDFS(int node = 0, int currCol = 0, vector<int>&col, vector<int>adj[]){
    col[node] = currCol;

    for(int i: adj[node]){
        if(col[i] == col[node]) return false;
        if(col[i] == -1){
            if(!bipartiteDFS(i, 1-col[node], col, adj)) return false;
        }
    }
    return true;
}