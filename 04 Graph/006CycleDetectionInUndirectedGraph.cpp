#include<bits/stdc++.h>
using namespace std;

// GFG - Cycle Detection in Undirected graph
// DFS
class Solution {
    bool isCycle(int node, int parent, vector<int> adj[], vector<bool> &vis){
        vis[node]=true;
        for(auto child: adj[node]){
            if(!vis[child]){
                if(isCycle(child,node,adj,vis))
                    return true;
                }
            else if(child!=parent)
                return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i,-1,adj,vis))
                    return true;
            }
        }
        return false;
    }
};


// BFS
class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                queue<pair<int,int>> q;
                q.push({i,-1});
                vis[i]=true;
                while(!q.empty()){
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(int child: adj[node]){
                        if(!vis[child]){
                            q.push({child,node});
                            vis[child] = true;
                        }else if(child!=parent){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};




// GFG - Detect Cycle using DSU

class DisJointSet{ // Using Disjoint Union
    vector<int> parent;
    vector<int> size;
    public:
    DisJointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i<n; i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(parent[u]==u)
            return u;
        return parent[u] = findParent(parent[u]);
    }
    bool unionTwoVertices(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u==v)
            return true;
        if(size[u]>size[v]){
            parent[v]=u;
            size[u]++;
        }else{
             parent[u]=v;
             size[v]++;
        }
        return false;
    }
};

class Solution
{
    public:
	int detectCycle(int V, vector<int>adj[]){
	    set<pair<int,int>> st; // Set to store edges from given graph
	    for(int i = 0;i<V; i++){
	        for(auto v: adj[i]){
	            if(st.find({i,v})!=st.end() || st.find({v,i})!=st.end())
	                continue;
	            st.insert({i,v});
	        }
	    }
	    DisJointSet ds(V);
	    for(auto v: st){
	        if(ds.unionTwoVertices(v.first,v.second)){
	            return true;
	        }
	    }
	    return false;
	}
};