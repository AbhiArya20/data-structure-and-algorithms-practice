#include<bits/stdc++.h>
using namespace std;

// GFG - Level of Node

class Solution{
	public:
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    if(X>=V)
	        return -1;
	    if(X==0)
	        return 0;
        vector<bool> vis(V);
        int ans = 0;
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            ans++;
            int size = q.size();
            for(int i = 0; i<size; i++){
                int parent = q.front();
                q.pop();
                for(auto child: adj[parent]){
                    if(!vis[child]){
                        if(child==X)
                            return ans;
                        q.push(child);
                        vis[child] = true;
                    }
                }   
            }
        }
        return -1;
	}
};
