#include<bits/stdc++.h>
using namespace std;

// BellmenFord Algo is also used for Shortest Distance from source to nodes
// It is applicable for negative weights and to detect negiative cycles
// Applicable for Directed Graph only, but can be used to undirected by converting into directed graph

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S){
    vector<int> dis(V, 1e8);
    dis[S] = 0; V--;
    while(V--){
        for(auto k: edges){ 
            int u = k[0];
            int v = k[1];
            int d = k[2];
               
            if(dis[u] == 1e8) continue;
            if(dis[u] + d < dis[v]) dis[v] = dis[u] + d;
        }
    }
    for(auto k: edges){
        int u = k[0];
        int v = k[1];
        int d = k[2];
          
        if(dis[u] == 1e8) continue;
        if(dis[u] + d < dis[v]) return {-1};
    } 
       
    return dis;
}