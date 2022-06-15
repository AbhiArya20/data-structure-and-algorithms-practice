#include<bits/stdc++.h>
using namespace std;

// LeetCode - 980

class Solution {
    int countAns(int i, int j,int count, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == -1)
            return 0;
        if(grid[i][j] == 2){
            return count==-1;
        }
        int ans = 0;
        vector<pair<int,int>> v = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<char> ch = {'R','D','L','U'};
        int k = 0;
        int val = grid[i][j];
        grid[i][j] = -1;
        for(auto c: v){
            ans += countAns(i+c.first, j+c.second,count-1,grid);
        }
        grid[i][j]=val;
        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==0)
                    count++;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1)
                    return countAns(i,j,count,grid);
            }
        }
        return 0;
    }
};
