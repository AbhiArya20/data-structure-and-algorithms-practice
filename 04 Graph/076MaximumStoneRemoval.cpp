#include<bits/stdc++.h>
using namespace std;

// GFG - Maximum Stone Removal

class Solution {
    class Disjoint{
        vector<int> parent,size;
        public:
        Disjoint(int n){
            parent.resize(n);
            size.resize(n);
            for(int i = 0; i<n;i++){
                parent[i]=i;
            }
        }
        int find(int u){
            if(u==parent[u])
                return u;
            return parent[u]=find(parent[u]);
        }
        int uni(int u, int v){
            u = find(u);
            v = find(v);
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
  public:
    int maxRemove(vector<vector<int>>& stones,int n) {
        Disjoint d(20005);
        unordered_map<int,int> um;
        for(auto v: stones){
            d.uni(v[0],v[1]+10001);
            um[v[0]]++;
            um[v[1]+10001]++;
        }
        int ans = 0;
        for(auto v: um){
            if(d.find(v.first) == v.first)
                ans++;
        }
        return n-ans;
    }
};