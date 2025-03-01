#include<bits/stdc++.h>
using namespace std;

// GFG - Merging Details

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint d(n);
        unordered_map<string,int> um;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(um.find(email)==um.end()){
                    um[email] = i;
                }else{
                    d.uni(um[email], i);
                    um[email]=i;
                }
            }
        }
        vector<vector<string>> temp(n);
        for(auto v: um){
            temp[d.find(v.second)].push_back(v.first);
        }
        vector<vector<string>> ans;
        int idx = 0;
        for(int i = 0; i<n; i++){
            if(temp[i].size() == 0)
                continue;
            sort(temp[i].begin(),temp[i].end());
            temp[i].insert(temp[i].begin(), accounts[i][0]);
            ans.push_back(temp[i]);
            idx++;
        }
        return ans; 
    }
};