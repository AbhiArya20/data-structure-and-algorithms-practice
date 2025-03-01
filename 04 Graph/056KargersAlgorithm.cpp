#include<bits/stdc++.h>
using namespace std;

// GFG - Karger's Algorithm
 
class DisJointSet{
    vector<int> parent;
    vector<int> rank;
    public:
    DisJointSet(int n){
        parent.resize(n);
        rank.resize(n);
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
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }else{
             parent[u]=v;
             rank[v]++;
        }
        return false;
    }
    bool findParent(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u==v)
            return true;
        return false;
    }
};
class Solution{
    int minimumCut(int n,vector<vector<int>> edges){
        DisJointSet d(n);
        int vetrices = n;
        for(auto v: edges){
            if(vetrices<=2)
                break;
            if(!d.unionTwoVertices(v[0],v[1])){
                cout<<v[0]<<" "<<v[1]<<endl; // to remove;
                vetrices--;
            }
        }
        int ans = 0;
        for(auto v: edges){
      

            if(!d.findParent(v[0],v[1]))
                ans++;
        }
        return ans;
    }
};
