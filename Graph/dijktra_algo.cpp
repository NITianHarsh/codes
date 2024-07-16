#include<bits/stdc++.h>
using namespace std;

// Dijktra's Algo is used for Shortest Distance from source to nodes
// It fails for negative weights and get stuck in negiative loops

// it is solved using Priority Queue and Set both

// 1. Priority Queue
vector<int> dijkstra(int V, vector<vector<int>>& edges, int S){
    vector<int> dis(V, 1e9);
    priority_queue(pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>) pq;
    dis[S] = 0;
    pq.push({0, S});
    while(!pq.empty()){
        int cw = pq.top().first;
        int cr = pq.top().second;
        pq.pop();

        for(auto k: edges[cr]){ 
            int v = k[0];
            int w = k[1];

            if(cw + w < dis[v]){
                dis[v] = cw + w;
                pq.push({dis[v], v});
            } 
        }
    }
    return dis;
}

// 2. Using Set
vector<int> dijkstra(int V, vector<vector<int>>& edges, int S){
    vector<int> dis(V, 1e9);
    set<pair<int,int>> st;
    dis[S] = 0;
    st.insert({0, S});
    while(!st.empty()){
        auto it = *st.begin();
        int cw = it.first;
        int cr = it.second;
        st.remove(it);

        for(auto k: edges[cr]){ 
            int v = k[0];
            int w = k[1];

            if(cw + w < dis[v]){
                if(dis[v] != 1e9) st.erase({dis[v], v});
                dis[v] = cw + w;
                st.insert({dis[v], v});
            } 
        }
    }
    return dis;
}
