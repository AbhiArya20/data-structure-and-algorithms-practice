#include<bits/stdc++.h>
using namespace std;


// GFG - Alien Dictionary

class Solution{
    public:
    string findOrder(string dict[], int N, int V) {
        vector<vector<int>> adj(V);
        for(int i = 0; i<N-1; i++){
            for(int j = 0; j<min(dict[i].size(),dict[i+1].size()); j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[(dict[i][j]-'a')].push_back((dict[i+1][j]-'a'));
                    break;
                }
            }
        }
        vector<int> topo;
	    vector<int> indegre(V);
	    for(int i = 0; i<V; i++){
	        for(auto c: adj[i]){
	            indegre[c]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i<V;i++){
	        if(!indegre[i])
	            q.push(i);
	    }
	    while(!q.empty()){
	        int src = q.front();
	        topo.push_back(src);
	        q.pop();
	        for(auto child: adj[src]){
	            indegre[child]--;
	            if(!indegre[child])
	                q.push(child);
	        }
	    }
	    string ans = "";
	    for(auto c: topo){
	        ans+=(c+'a');
	    }
	    return ans;
    }
};