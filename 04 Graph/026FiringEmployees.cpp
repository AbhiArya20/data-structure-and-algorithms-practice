#include<bits/stdc++.h>
using namespace std;

// GFG - Firing Employees

class Solution{   
    bool isPrime(int n){
        if(n==1)
            return false;
        for(int i = 2; i*i<=n; i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
public:
    int firingEmployees(vector<int> &arr, int n){
        vector<vector<int>> adj(n);
        int start = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]>0)
                adj[arr[i]-1].push_back(i);
            else start = i;
        }
        
        int ans = 0;
        vector<bool> vis(n);
        int level = 0;
        queue<int> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int size = q.size();
            for(int j = 0; j<size; j++){
                int src = q.front();
                if(src!=start && isPrime(src+level+1))
                    ans++;
                q.pop();
                for(int child: adj[src]){
                    if(!vis[child]){
                        vis[child]=true;
                        q.push(child);
                    }
                }
            }
            level++;
        }
        return ans;
    }
};