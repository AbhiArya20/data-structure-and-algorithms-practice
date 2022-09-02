#include<bits/stdc++.h>
using namespace std;

// GFG - Step by Knight
// GFG - Knight Walk

class Solution{
    public:
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int n){
	    vector<vector<bool>> vis(n,vector<bool>(n));
        queue<pair<int,int>> q;
        int ans = 0;
        if(kp[0]==tp[0] && kp[1]==tp[1])
            return ans;
        q.push({kp[0]-1, kp[1]-1});
        vis[kp[0]-1][kp[1]-1] = true;
        while(!q.empty()){
            ans++;
            int size = q.size();
            for(int i = 0; i<size; i++){
                int sr = q.front().first;
                int sc = q.front().second;
                q.pop();
                vector<pair<int,int>> v = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
                for(auto p: v){
                    int nr = sr+p.first;
                    int nc = sc+p.second;
                    if(nr<0 || nc<0 || nr>=n || nc>=n || vis[nr][nc])
                        continue;
                    if(nr == tp[0]-1 && nc == tp[1]-1)
                        return ans;
                    q.push({nr, nc});
                    vis[nr][nc]=true;
                }
            }
        }
	    return -1;
	}
};