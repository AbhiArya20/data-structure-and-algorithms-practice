#include<bits/stdc++.h>
using namespace std;

// GFG - Shortest Source to Destination Path
// GFG - Shortest Distance in a Binary Maze
class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> vis, int X, int Y) {
        queue<pair<int,int>> q;
        int ans = 0;
        if(vis[0][0]==0)
            return -1;
        if(X == 0 && Y==0)
            return ans;
        q.push({0,0});
        vis[0][0] = 0;
        while(!q.empty()){
            ans++;
            int size = q.size();
            for(int i = 0; i<size; i++){
                int sr = q.front().first;
                int sc = q.front().second;
                q.pop();
                vector<pair<int,int>> v = {{1,0},{-1,0},{0,1},{0,-1}};
                for(auto p: v){
                    int nr = sr+p.first;
                    int nc = sc+p.second;
                    if(nr<0 || nc<0 || nr>=N || nc>=M || vis[nr][nc]==0)
                        continue;
                    if(nr == X && nc == Y)
                        return ans;
                    q.push({nr, nc});
                    vis[nr][nc]=0;
                }
            }
        }
	    return -1;
    }