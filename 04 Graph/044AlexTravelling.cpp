#include<bits/stdc++.h>
using namespace std;

// GFG - Alex Travelling

class Solution {
  public:
    int minimumCost(vector<vector<int>>& flight, int N, int K) {
        vector<vector<vector<int>>> adj(N);
        for(auto v: flight){
            adj[v[0]-1].push_back({v[1]-1,v[2]});
        }
        vector<int> dist(N, 1e9);
        dist[K-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,K-1});
        while(!pq.empty()){
            int srcWt = pq.top().first;
            int src = pq.top().second;
            pq.pop();
            for(auto childPair: adj[src]){
                int child = childPair[0];
                int childWt = childPair[1];
                if(dist[child]>dist[src]+childWt){
                    dist[child] = dist[src]+childWt;
                    pq.push({dist[child],child});
                }
            }
        }
        int ans = 0;
        for(auto v: dist){
            if(v==1e9)
                return -1;
            ans = max(ans, v);
        }
        return ans;
    }
};