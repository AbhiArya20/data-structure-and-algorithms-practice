#include<bits/stdc++.h>
using namespace std;

// GFG - Find Whether Path Exist

class Solution
{
    public:
    bool is_Possible(vector<vector<int>>& grid){
        int n = grid.size();
        int sr = -1; 
        int sc = -1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1){
                    sr = i;
                    sc = j;
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        grid[sr][sc] = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                int sr = q.front().first;
                int sc = q.front().second;
                q.pop();
                vector<pair<int,int>> v = {{1,0},{-1,0},{0,1},{0,-1}};
                for(auto p: v){
                    int nr = sr+p.first;
                    int nc = sc+p.second;
                    if(nr<0 || nc<0 || nr>=n || nc>=n || grid[nr][nc]==0 || grid[nr][nc]==1)
                        continue;
                    if(grid[nr][nc]==2)
                        return true;
                    q.push({nr, nc});
                    grid[nr][nc]=0;
                }
            }
        }
	    return false;
    }
};