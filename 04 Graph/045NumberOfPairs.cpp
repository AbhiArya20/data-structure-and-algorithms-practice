#include<bits/stdc++.h>
using namespace std;

// GFG - Number of Pairs

class Solution {
    vector<int> parent,size;
    int find(int u){
        if(u==parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void uni(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v)
            return;
        if(size[u]>size[v]){
            parent[v]=u;
            size[u]++;
        }else{
            parent[u]=v;
            size[v]++;
        }
    }
    public:
        long long int numberOfPairs(vector<vector<int>> &pairs,int p,int n){
            parent.resize(n);
            size.resize(n);
            for(int i = 0; i<n; i++){
                parent[i]=i;
            }
            for(auto v: pairs){
                uni(v[0],v[1]);
            }
            unordered_map<int,int> um;
            vector<int> dp(n);
            for(int i = 0; i<n; i++){
                um[find(i)]++; 
            }
            long long int ans = 0;
            int sum = 0;
            for(auto v: um){
                ans += v.second*sum;
                sum+=v.second;
            }
            return ans;
        }
};