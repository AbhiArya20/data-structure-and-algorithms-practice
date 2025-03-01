#include<bits/stdc++.h>
using namespace std;

// GFG - Shortest Path in Weighted undirected graph

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n+1);
        for(auto v: edges){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        vector<int> dist(n+1, 1e9);
        dist[1]=0;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>> , greater<pair<int,vector<int>>>> pq;
        pq.push({0,{1}});
        while(!pq.empty()){
            int srcWt = pq.top().first;
            auto tillNow = pq.top().second;
            int src = tillNow[tillNow.size()-1];
            if(src==n)  
                return tillNow;
            pq.pop();
            for(auto childPair: adj[src]){
                int child = childPair[0];
                int childWt = childPair[1];
                if(dist[child]>dist[src]+childWt){
                    tillNow.push_back(child);
                    dist[child] = dist[src]+childWt;
                    pq.push({dist[child],{tillNow}});
                    tillNow.pop_back();
                }
            }
        }
        return {-1};
    }
};


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n+1);
        for(auto v: edges){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        vector<int> parent(n+1);
        for(int i = 0; i<=n; i++){
            parent[i]=i;
        }
        vector<int> ans;
        vector<int> dist(n+1, 1e9);
        dist[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            int srcWt = pq.top().first;
            int src = pq.top().second;
            pq.pop();
            for(auto childPair: adj[src]){
                int child = childPair[0];
                int childWt = childPair[1];
                if(dist[child]>srcWt+childWt){
                    parent[child]=src;
                    dist[child] = srcWt+childWt;
                    pq.push({dist[child],child});
                }
            }
        }
        if(dist[n]==1e9)
            return {-1};
        int j = n;
        while(parent[j]!=j){
            ans.push_back(j);
            j = parent[j];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};