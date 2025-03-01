#include<bits/stdc++.h>
using namespace std;

// GFG - Fill The Tank

class Solution {
    long long dfs(int src, vector<vector<int>> &adj, int *cap, int parent){
        long long count = 0;
        long long ans = 0;
        for(auto child: adj[src]){
            if(child!=parent){
                count++;
                long long  val = dfs(child,adj,cap,src);
                if(val==-1)
                    return -1;
                ans = max(ans,val);
            }
        }
        if((ans*count+cap[src]) > 1e18)
            return -1;
        return ans*count+cap[src];
    }
       
public:
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
      vector<vector<int>> adj(N);
      for(auto v: Edges){
          adj[v[0]-1].push_back(v[1]-1);
          adj[v[1]-1].push_back(v[0]-1);
      }
      return dfs(S-1, adj, Cap,-1);
     }
};
