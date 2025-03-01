#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Cost Path

class Solution{
    public:
    int minimumCostPath(vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            vector<pair<int,int>> v = {{0,-1},{0,1},{-1,0},{1,0}};
            for(auto p : v){
                int nr = r+p.first;
                int nc = c+p.second;
                if(nr<0 || nr>=n || nc<0 || nc>=n)
                    continue;
                if(dist[nr][nc]>dist[r][c]+grid[nr][nc]){
                    dist[nr][nc] = dist[r][c]+grid[nr][nc];
                    pq.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return dist[n-1][n-1];
    }
};