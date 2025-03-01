#include<bits/stdc++.h>
using namespace std;

// Practice Link - https://www.spoj.com/problems/LCA/

class Solution{
    int n;
    int idx;
    vector<int> size,heavy,parent,depth,head,lt,pos,value;
    vector<vector<int>> adj;
    void dfs(int node){
        for(auto child: adj[node]){
            parent[child] = node;
            depth[child] = depth[node]+1;
            dfs(child);
            size[node] += size[child];
            if(size[child] > size[heavy[node]]){
                heavy[node] = child;
            }
        }
        size[node]++;
    }
    void dfsHLD(int node, int chain){
        head[node] = chain;
        lt[idx] = value[node];
        pos[node] = idx;
        idx++;
        if(heavy[node] != 0){
            dfsHLD(heavy[node],chain);
        }
        for(auto child: adj[node]){
            if(heavy[node]!=child){
                dfsHLD(child,child);
            }
        }
    }
    public:
    Solution(vector<vector<int>> &adj,vector<int> value){
        this->adj = adj;
        this->value = value;
        n = adj.size();
        idx = 1;
        size.resize(n+1);
        heavy.resize(n+1);
        parent.resize(n+1);
        depth.resize(n+1);
        head.resize(n+1);
        lt.resize(n+1);
        value.resize(n+1);
        pos.resize(n+1);
        dfs(1);
        dfsHLD(1,1);
    }
    int getLca(int a, int b){
        while(head[a]!=head[b]){
            if(depth[head[a]]<depth[head[b]]){
                swap(a,b);
            }
            a = parent[head[a]];
        }
        return depth[a]<depth[b]? a:b;
    }
};
int main(){
    int t;
    cin>>t;
    int i = 1;
    while(t--){
        cout<<"Case "<<i<<":"<<endl;
        int n; 
        cin>>n;
        vector<vector<int>> adj(n+1);
        for(int i = 1; i<=n; i++){
            int m;
            cin>>m;
            for(int j= 0; j<m; j++){
                int x;
                cin>>x;
                adj[i].push_back(x);
            }
        }
        vector<int> value(n+1);
        // for(int i = 1; i<=n; i++){ // if value is given
        //     cin>>value[i];
        // }

        Solution obj(adj,value);
        int q;
        cin>>q;
        while(q--){
            int a, b;
            cin>>a>>b;
            cout<<obj.getLca(a,b)<<endl;
        }
        i++;
    }
}