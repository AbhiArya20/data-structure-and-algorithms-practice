#include<bits/stdc++.h>
using namespace std;

// GFG - Connection Graph

class DisJointSet{
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
    int numberOfComponnent(){
        unordered_map<int,int> um;
        for(auto v: parent){
            um[v]++;
        }
        return um.size();
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisJointSet d(n);
        int count = 0;
        for(auto v: edge){
            if(d.unionTwoVertices(v[0],v[1]))
                count++;
        }
        for(auto v: edge){
            d.findParent(v[0]);
            d.findParent(v[1]);
        }
        int com = d.numberOfComponnent();
        if(com-1>count)
            return -1;
        return com-1;
    }
};