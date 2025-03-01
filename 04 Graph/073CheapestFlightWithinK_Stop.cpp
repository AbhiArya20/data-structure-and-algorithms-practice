#include<bits/stdc++.h>
using namespace std;


// GFG - Cheapest Flights Within K Stops

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<vector<pair<int,int>>> adj(n);
        for(auto v: flights){
            adj[v[0]].push_back({v[1],v[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            int src = pq.front().second.first;
            int wt = pq.front().first;
            int level = pq.front().second.second;
            pq.pop();
            if(level>k)
                continue;
            for(auto childPair: adj[src]){
                int child = childPair.first;
                int cwt = childPair.second;
                if(dist[child]>wt+cwt){
                    dist[child]=wt+cwt;
                    pq.push({dist[child],{child,level+1}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};