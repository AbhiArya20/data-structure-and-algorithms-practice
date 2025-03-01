#include<bits/stdc++.h>
using namespace std;


// GFG - Number of Ways to Arrive at Destination

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto v: roads){
            adj[v[1]].push_back({v[0],v[2]});
            adj[v[0]].push_back({v[1],v[2]});
        }
        vector<int> dp(n,0),dist(n,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        dp[0]=1;
        while(!pq.empty()){
            int src = pq.top().second;
            pq.pop();
            for(auto childPair: adj[src]){
                int child = childPair.first;
                int wt = childPair.second;
                if(dist[child]>dist[src]+wt){
                    dist[child]=dist[src]+wt;
                    dp[child]=dp[src];
                    pq.push({dist[child], child});
                }else if(dist[child]==dist[src]+wt){
                    dp[child]+=dp[src];
                }
            }
        }
        return dp[n-1];
    }
};
