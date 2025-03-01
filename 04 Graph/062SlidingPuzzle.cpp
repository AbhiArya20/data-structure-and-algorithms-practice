#include<bits/stdc++.h>
using namespace std;

// LeetCode - 773

class Solution {
    bool isFound(vector<vector<int>>& mat){    
        return mat[0][0]==1 && mat[0][1]==2 && mat[0][2]==3 && mat[1][0]==4 && mat[1][1]==5 && mat[1][2]==0;
    }
public:
    int slidingPuzzle(vector<vector<int>>& mat) {
       if(isFound(mat))
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
            int r = -1;
            int c = -1;        
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(cur[i][j]==0){
                        r = i;
                        c = j;
                        goto label;
                    }   
                }
            }
            label:;
            vector<pair<int,int>> v = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto p : v){
                int nr = r + p.first;
                int nc = c + p.second;
                if(nr<0 || nc<0|| nr==n || nc == m)
                    continue;
                swap(cur[r][c],cur[nr][nc]);            
                if(isFound(cur))
                    return 1+step;
                if(visited.find(cur) == visited.end()){
                    visited.insert(cur);
                    q.push({step+1,cur});
                }   
                swap(cur[r][c],cur[nr][nc]);
            }
        }
        return -1; 
    }
};
