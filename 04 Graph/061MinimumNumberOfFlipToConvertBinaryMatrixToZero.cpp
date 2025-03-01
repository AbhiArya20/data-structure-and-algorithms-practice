#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1284

class Solution {
public:
    void flip(int i, int j, vector<vector<int> > &adj) {
        int m = adj.size(), n = adj[0].size(); 
        adj[i][j] ^= 1;
        if(i-1 >= 0)
            adj[i-1][j] ^= 1;
        if(i+1 < m)
            adj[i+1][j] ^= 1;
        if(j-1>= 0)
            adj[i][j-1] ^= 1;
        if(j+1<n)
            adj[i][j+1] ^= 1;
    }
    bool all_zero(vector<vector<int>>& mat){    
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] != 0){
                    return false;
                }
            }
        }
        return true;
    }
    int minFlips(vector<vector<int>>& mat) {
        if(all_zero(mat))
            return 0;
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,vector<vector<int>>>> q;
        set<vector<vector<int>>> visited;        
        q.push({0,mat});        
        visited.insert(mat);        
        while(!q.empty()){
            auto step = q.front().first;
            auto cur = q.front().second;
            q.pop();           
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    flip(i,j,cur);                    
                    if(all_zero(cur))
                        return 1+step;
                    if(visited.find(cur) == visited.end()){
                        visited.insert(cur);
                        q.push({step+1,cur});
                    }                    
                    flip(i,j,cur);
                }
            }
        }
        return -1;
    }
};
