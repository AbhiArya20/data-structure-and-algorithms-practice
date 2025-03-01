#include<bits/stdc++.h>
using namespace std;

// GFG- Minimum Spanning Tree


// Kruskal Algorithm
class Solution{
    vector<int> parent;
    vector<int> size;
    int find(int u){
        if(u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    bool uni(int u, int v){
        u=find(u);
        v=find(v);
        if(u==v)
            return false;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]++;
        }else{
            parent[v]=u;
            size[u]++;
        }
        return true;
    }
	public:
	int spanningTree(int V, vector<vector<int>> adj[]){
	    parent.resize(V);
	    size.resize(V);
	    for(int i = 0;i<V; i++){
	        parent[i]=i;
	    }
        vector<vector<int>> edges;
        for(int i = 0;i<V; i++){
            for(auto v: adj[i]){
                edges.push_back({v[1],i,v[0]});
            }
        }
        int ans = 0;
        sort(edges.begin(),edges.end());
        for(auto v: edges){
            if(uni(v[1],v[2])){
                ans+=v[0];
            }
        }
        return ans;
    }
};



// Prim's Algorithm

class Solution{
	public:
    int spanningTree(int n, vector<vector<int>> adj[]){
        vector<int> dist(n,INT_MAX);
        vector<bool> vis(n);
        vector<int> parent(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        parent[0]=-1;
        while(!pq.empty()){
            int wt = pq.top().first;
            int src = pq.top().second;
            vis[src]=true;
            pq.pop();
            for(auto v: adj[src]){
                int child = v[0];
                int cwt = v[1];
                if(!vis[child] && dist[child]>cwt){
                    dist[child]=cwt;
                    pq.push({dist[child], child});
                }
            }
        }
        int ans = 0;
        for(auto v: dist){
            ans+=v;
        }
        return ans;
    }
};



// GFG - Reverse Delete Algorithm for Minimum Spanning Tree

class Solution {
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node]=true;
        for(auto child: adj[node]){
            if(!vis[child]){
                dfs(child, adj, vis);
            }
        }
    }
    bool isConnected(vector<vector<int>> &adj){
        int n = adj.size();
        vector<bool> vis(n);
        
        dfs(0,adj,vis);
        
        for(auto v: vis){
            if(v==false)
                return false;
        }
        return true;
    }
  public:
    int RevDelMST(int Arr[], int n, int e) {
        vector<vector<int>> edge;
        vector<vector<int>> adj(n);
        for(int i = 0; i<3*e; i+=3){
            adj[Arr[i]].push_back(Arr[i+1]);
            adj[Arr[i+1]].push_back(Arr[i]);
            edge.push_back({Arr[i],Arr[i+1],Arr[i+2]});
        }
        sort(edge.begin(),edge.end(),[&](vector<int> a,vector<int> b){
           return a[2]>b[2]; 
        });
        int ans = 0;
        for(auto v: edge){
            adj[v[0]].erase(remove(adj[v[0]].begin(), adj[v[0]].end(), v[1]), adj[v[0]].end());
            adj[v[1]].erase(remove(adj[v[1]].begin(), adj[v[1]].end(), v[0]), adj[v[1]].end());
            if(!isConnected(adj)){
                adj[v[0]].push_back(v[1]);
                adj[v[1]].push_back(v[0]);
                ans+=v[2];
            }
        }
        return ans;
    }
};
