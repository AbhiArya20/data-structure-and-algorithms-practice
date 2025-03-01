#include<bits/stdc++.h>
using namespace std;

// GFG - Path With Minimum Effort

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int dif = pq.top().first;
            pq.pop();
            vector<pair<int,int>> v = {{0,-1},{0,1},{-1,0},{1,0}};
            for(auto p : v){
                int nr = r+p.first;
                int nc = c+p.second;
                if(nr<0 || nr>=n || nc<0 || nc>=m)
                    continue;
                if(dist[nr][nc]>max(abs(grid[r][c]-grid[nr][nc]),dif)){
                    dist[nr][nc] = max(abs(grid[r][c]-grid[nr][nc]),dif);
                    pq.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};