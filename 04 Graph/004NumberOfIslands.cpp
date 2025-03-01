#include<bits/stdc++.h>
using namespace std;

// LeetCode - 200
// GFG - X Total Shape - no diagonal
class Solution {
    void dfs(int i,int j, vector<vector<char>> &isConnected, vector<vector<bool>> &vis){
        if(i<0 || j<0 || i>=isConnected.size() || j>=isConnected[0].size() || isConnected[i][j]=='0' || vis[i][j])
            return;
        vis[i][j] = true;
        vector<pair<int,int>> v = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto p: v){
            dfs(i+p.first, j+p.second, isConnected, vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& isConnected) {
            int n = isConnected.size();
            int m = isConnected[0].size();
            int ans = 0;
            vector<vector<bool>> vis(n, vector<bool>(m));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(isConnected[i][j] == '1' && !vis[i][j]){
                        ans++;
                        dfs(i,j, isConnected, vis);
                    }
                }
            }
            return ans;
    }
};


// GFG - Number of distinct Island
class Solution {
    set<vector<pair<int,int>>> st;
    void dfs(int i,int j,int a, int b,vector<pair<int,int>> &temp, vector<vector<int>> &isConnected, vector<vector<bool>> &vis){
        if(i<0 || j<0 || i>=isConnected.size() || j>=isConnected[0].size() || !isConnected[i][j] || vis[i][j])
            return;
        vis[i][j] = true;
        temp.push_back({a,b});
        vector<pair<int,int>> v = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto p: v){
            dfs(i+p.first, j+p.second, a+p.first, b+p.second, temp, isConnected, vis);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(isConnected[i][j] && !vis[i][j]){
                    vector<pair<int,int>> temp;
                    dfs(i,j,0,0,temp,isConnected, vis);
                    if(st.find(temp)==st.end()){
                        ans++;
                        st.insert(temp);
                    }
                }
            }
        }
        return ans;
    }
};