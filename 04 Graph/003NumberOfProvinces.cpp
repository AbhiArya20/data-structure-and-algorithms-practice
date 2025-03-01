#include<bits/stdc++.h>
using namespace std;

// LeetCode - 547
// using DFS
class Solution {
    void dfs(int node, vector<vector<int>> &isConnected, vector<bool>&vis){
        vis[node] = true;
        int n = isConnected.size();
        for(int child = 0; child<n; child++){
            if(isConnected[node][child] && !vis[child]){
                dfs(child, isConnected, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> vis(n);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(i, isConnected, vis);
            }
        }
        return ans;
    }
};


// using BFS
class Solution {
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> vis(n);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                ans++;
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int parent = q.front();
                    q.pop();
                    for(int child = 0; child<n; child++){
                        if(isConnected[parent][child] && !vis[child]){
                            vis[child]=true;
                            q.push(child);
                        }
                    }
                }
            }
        }
        return ans;
    }
};