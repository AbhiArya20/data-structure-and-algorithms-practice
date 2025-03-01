#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum S-T Cut In Flow Network


class Solution{
    void dfs(int src, vector<vector<int>> &radj,vector<int> &vis){
        int n = radj.size();
        vis[src]=true;
        for(int child = 0; child<n; child++){
            if(radj[src][child] && !vis[child]){
                dfs(child, radj,vis);
            }
        }
    }
    bool bfs(int src,int dest, vector<int> &parent, vector<vector<int>> &radj){
        int n = radj.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(src);
        vis[src]=true;
        parent[src]=-1;
        while(!q.empty()){
            int src = q.front();
            q.pop();
            for(int child = 0; child<n; child++){
                if(!vis[child] && radj[src][child]>0){
                    parent[child]=src;
                    q.push(child);
                    vis[child]=true;
                    if(child==dest){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    vector<int> fordFulkerson(int src, int dest, vector<vector<int>> &adj){
        int n = adj.size();
        vector<vector<int>> radj(n,vector<int>(n));
        for(int i = 0; i<n;i++){
            for(int j = 0;j<n; j++){
                radj[i][j]=adj[i][j];
            }
        }
        vector<int> parent(n,-1);
        while(bfs(src,dest,parent,radj)){
            int curAns = INT_MAX;
            int cchild  = dest;
            while(cchild != src){
                int csrc =parent[cchild];
                curAns = min(curAns,radj[csrc][cchild]);
                cchild = csrc;
            }
            cchild  = dest;
            while(cchild != src){
                int csrc=parent[cchild];
                radj[csrc][cchild] -= curAns;
                radj[cchild][csrc] += curAns;
                cchild = csrc;
            }
        }
        vector<int> ans;
        vector<int> vis(n);
        dfs(src,radj,vis);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n;j++){
                if(vis[i] && !vis[j] && adj[i][j]){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
    vector<int> minimumCut(vector<vector<int>> &A, int S, int T, int N){
        auto ans = fordFulkerson(S,T,A);
        if(ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};
