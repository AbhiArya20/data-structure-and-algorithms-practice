#include<bits/stdc++.h>
using namespace std;

// GFG - Spider Sense

class Solution{
    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int m, int n) 
    { 
        vector<vector<int>> ans(m,vector<int>(n));
        vector<vector<bool>> vis(m,vector<bool>(n));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]=='B'){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            if(matrix[r][c]=='B')
                ans[r][c]=0;
            else 
                ans[r][c]=d;
            q.pop();
            vector<pair<int,int>> v = {{1,0},{-1,0},{0,-1},{0,1}};
            for(auto p: v){
                int nr = r+p.first;
                int nc = c+p.second;
                if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc] || matrix[nr][nc]=='W')
                    continue;
                vis[nr][nc]=true;
                q.push({{nr,nc},d+1});
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]=='O' && ans[i][j]==0)
                    ans[i][j]=-1;
                else if(matrix[i][j]=='W'){
                    ans[i][j]=-1;
                }
                
            }
        }
        return ans;
    } 
};