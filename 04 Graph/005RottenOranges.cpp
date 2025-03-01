#include<bits/stdc++.h>
using namespace std;

// LeetCode - 994
// GFG - Covid Spread
// GFG - Rotten Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    count++;
            }
        }
        int count2 = 0;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            bool rot = false;
            for(int i = 0; i<size; i++){
                auto p = q.front();
                q.pop();
                vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
                for(auto c: v){
                    int ni = p.first+c.first;
                    int nj = p.second+c.second;
                    if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid[0].size() || grid[ni][nj] != 1)
                        continue;
                    count2++;
                    rot = true;
                    grid[ni][nj]=2;
                    q.push({ni,nj});
                }
            }
            if(rot)
                ans++;
        }
        if(count2 == count)
            return ans;
        return -1;
    }
};