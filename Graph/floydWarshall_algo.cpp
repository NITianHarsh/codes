#include<bits/stdc++.h>
using namespace std;

// floydWarsall is just a brutefroce approach to find the shortest distance from every node to every node
// checking all paths and returning the min one

// consider a adj matrix given, say the unreachable path are -1 currently
void floyd(vector<vector<int>> &mat){
    int n = mat.size();
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == -1) mat[i][j] = 1e9;
            if(i==j) mat[i][j] = 0;
        }
    }

    for(int k =0; k<n; k++){
        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1e9) mat[i][j] = -1;
        }
    }

}