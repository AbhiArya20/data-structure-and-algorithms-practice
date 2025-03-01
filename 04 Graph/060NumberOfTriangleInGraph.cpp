#include<bits/stdc++.h>
using namespace std;

// GFG - Number of Triangle in graph

class Solution{
    int countTriangel(vector<vector<int>> adj, bool isDirected){
        int n = adj.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if(adj[i][j] && adj[j][k] && adj[k][i])
                        ans++;
                }
            }
        }
        if(isDirected)
            return ans/3;
        return ans/6;
    }
};