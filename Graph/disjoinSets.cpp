/*
    DisJoint Sets
    Union krte h and find krte h kisi bhi node ka parent at any time also we can tell any two nodes are in same component or not by this

    this is applied in two ways. */ 

#include<bits/stdc++.h>
using namespace std;

// 1. Union - find

/* initially a parent set is defined with all nodes and their value is node itself
 ex. say n nodes then -->   {0,1,2,3,4,5.....n};
 now just apply algo and find and union */

int find(vector<int> &arr, int x){  // returns the ultimate parent of x
    int p = x;
    while(x != arr[x]){
        p = arr[x];
        x = p;
    }
    return p;
}
void doUnion(vector<int>& arr, int a, int b){ // this join two node a, b
    int a_parent = find(arr, a);
    int b_parent = find(arr, b);
    arr[a_parent] = arr[b_parent];
}

// 2nd way is a better and a nice way  its complete optimised solution

class disjointSetUnion {
    // what will be in it
    vector<int> rank;
    vector<int> parent;
public:  // constructor defining
    disjointSetUnion(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
    }
// what will it do 
    int findPar(int n) {
        if(n == parent[n]) return n;
        return parent[n] = findPar(parent[n]);
    }

    void unionOperation(int x, int y) {
        int xP = findPar(x);
        int yP = findPar(y);

        if(xP == yP) return ; // means belongs to same component
        
        if(rank[xP] < rank[yP]) {
            parent[x] = y;
        } else if(rank[xP] < rank[yP]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[yP]++;
        }
    }
};
