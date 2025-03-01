#include<bits/stdc++.h>
using namespace std;

// GFG - Snack and Ladder

class Solution{
public:
    int minThrow(int N, int arr[]){
        unordered_map<int,int> ladder,snack;
        for(int i = 0; i<N; i+=2){
            ladder[arr[i]]=arr[i+1];
            if(i+N+1<2*N)
                snack[arr[i+N]]=arr[N+i+1];
        }
        int ans = 0;
        vector<bool> vis(31);
        queue<int> q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            int size = q.size();
            for(int k = 0; k<size; k++){
                int i = q.front();
                if(i==30)
                    return ans;
                q.pop();
                for(int j = 1; j<=6; j++){
                    if(ladder.find(i+j)!=ladder.end() && !vis[ladder[i+j]]){
                        q.push(ladder[i+j]);
                        vis[ladder[i+j]]=true;
                    }
                    if(snack.find(i+j)!=snack.end() && !vis[snack[i+j]]){
                        q.push(snack[i+j]);
                        vis[snack[i+j]]=true;
                    }
                    if(i+j<31 && !vis[i+j]){
                        q.push(i+j);
                        vis[i+j]=true;
                    }
                }
            }
            ans++;
        }
       return -1;
    }  
};