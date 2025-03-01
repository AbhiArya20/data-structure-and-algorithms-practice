#include<bits/stdc++.h>
using namespace std;

// GFG - Number of Island

class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i<n; i++)
            parent[i]=i;
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> ans;
        DisjointSet d(n*m);
        int count = 0;
        vector<vector<int>> grid(n,vector<int>(m));
        for(auto v: operators){
            int r = v[0];
            int c = v[1];
            if(grid[r][c]){
                ans.push_back(count);
                continue;
            }
            grid[r][c]=1;
            count++;
            vector<pair<int,int>> V = {{0,-1},{0,1},{1,0},{-1,0}};
            for(auto p : V){
                int nr = r+p.first;
                int nc = c+p.second;
                if(isValid(nr,nc,n,m) && grid[nr][nc]){
                    if(d.findPar(r*m+c) != d.findPar(nr*m+nc)){
                        count--;
                        d.unionBySize(r*m+c,nr*m+nc);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
