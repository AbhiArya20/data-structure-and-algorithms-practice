#include<bits/stdc++.h>
using namespace std;

// GFG - Ford-Fulkerson Algorithm for maximum Flow Problem

class Solution
{
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
    int fordFulkerson(int src, int dest, vector<vector<int>> &adj){
        int n = adj.size();
        vector<vector<int>> radj(n,vector<int>(n));
        for(int i = 0; i<n;i++){
            for(int j = 0;j<n; j++){
                radj[i][j]=adj[i][j];
            }
        }
        vector<int> parent(n,-1);
        int ans = 0;
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
            ans+=curAns;
        }
        return ans;
    }
public:
    int findMaxFlow(int n,int m,vector<vector<int>> Edges){
        vector<vector<int>> adj(n,vector<int>(n));
        for(auto v: Edges){
            adj[v[0]-1][v[1]-1]+=v[2];
            adj[v[1]-1][v[0]-1]+=v[2];
        }
        return fordFulkerson(0,n-1,adj);
    }
};
