#include<bits/stdc++.h>
using namespace std;

// GFG - Disjoint Set Union

class DisJointSet{ // Naive - not efficient
    vector<int> parent;
    public:
    DisJointSet(int n){
        parent.resize(n);
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
        parent[u]=v;
        return false;
    }
};

class DisJointSet{ // By Rank
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
};

class DisJointSet{ // By Size
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