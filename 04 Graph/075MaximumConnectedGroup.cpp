#include<bits/stdc++.h>
using namespace std;

// GFG - Maximum Connected Group

class Solution { // not efficient - not accepted
    int bfs(int i, int j, vector<vector<int>> grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=0;
        int ans = 0;
        while(!q.empty()){
            ans++;
            auto p = q.front();
            q.pop();
            vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
                for(auto c: v){
                    int ni = p.first+c.first;
                    int nj = p.second+c.second;
                    if(ni<0 || nj<0 || ni>=grid.size() || nj>=grid[0].size() || grid[ni][nj] != 1)
                        continue;
                    grid[ni][nj]=0;
                    q.push({ni,nj});
                }
            }
        return ans;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    ans = max(ans,bfs(i,j,grid));
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    grid[i][j]=1;
                    ans = max(ans,bfs(i,j,grid));
                    grid[i][j]=0;
                }
            }
        }
        return ans;
    }
};


// Efficient and accepted
class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;
        if (size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
        

    }
};
class Solution {
    private:
    bool isValid(int row,int col,int n,int m){
        return  row>=0&&row<n&&col>=0&&col<m;
    }
  public:
  
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int idx=0;idx<4;idx++){
                    int nrow=row+dr[idx];
                    int ncol=col+dc[idx];
                    if(isValid(nrow,ncol,n,n)&&grid[nrow][ncol]==1){
                        int nodeNo=n*row+col;
                        int adjNodeNO=n*nrow+ncol;
                        ds.unionBySize(nodeNo,adjNodeNO);
                    }
                }
            }
        }
        int ans=0;
         for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int>components;
                for(int idx=0;idx<4;idx++){
                    int nrow=row+dr[idx];
                    int ncol=col+dc[idx];
                    if(isValid(nrow,ncol,n,n)&&grid[nrow][ncol]==1){
                        int nodeNo=n*row+col;
                        int adjNodeNO=n*nrow+ncol;
                        components.insert(ds.findPar(nrow*n+ncol));
                    }
                }
                int totalSize=0;
                for(auto it:components){
                    totalSize+=ds.size[it];
                }
                ans=max(ans,totalSize+1);
                
            }
        }
        
        for(int cell=0;cell<n*n;cell++){
            ans=max(ans,ds.size[ds.findPar(cell)]);
        }
        return ans;
    }
};