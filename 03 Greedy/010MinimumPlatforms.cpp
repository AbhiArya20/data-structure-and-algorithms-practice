#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Platform
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n){
        vector<vector<int>> pairs;
        for(int i = 0; i<n; i++){
            pairs.push_back({dep[i],arr[i]});
        }
        sort(pairs.begin(), pairs.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int ans = 0;
        for(int i = 0; i<n; i++){
            while(!pq.empty() && pq.top()[0]<pairs[i][1]){
                pq.pop();
            }
            pq.push(pairs[i]);
            int size = pq.size();
            ans = max(ans,size);
        }
        return ans;
    }
};
