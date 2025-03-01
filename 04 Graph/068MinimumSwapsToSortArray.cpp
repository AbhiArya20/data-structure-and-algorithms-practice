#include<bits/stdc++.h>
using namespace std;

// GFG - Minimum Swap to Sort Array


class Solution {
    public:
    int minSwaps(vector<int>&nums)
	{
	    int ans = 0;
	    int n = nums.size();
	    vector<pair<int,int>> v;
	    for(int i =0; i<n; i++){
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    vector<int> vis(n);
        for(int i = 0; i<n; i++){
            if(vis[i] || v[i].second == i)
                continue;
            int count = 0;
            int j = i;
            while(!vis[j]){
                count++;
                vis[j]=true;
                j=v[j].second;
            }
            ans+=count-1;
        }
        return ans;
	}
};
