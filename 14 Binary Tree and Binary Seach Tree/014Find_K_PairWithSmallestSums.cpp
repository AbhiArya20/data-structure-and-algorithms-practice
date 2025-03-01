#include<bits/stdc++.h>
using namespace std;

// LeetCode - 373


class Solution { // Order of the answer is matter for this problem
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i = 0; i<n; i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        vector<vector<int>> ans;
        while(!pq.empty() && k--){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[x],nums2[y]});
            if(y+1<m)
                pq.push({nums1[x]+nums2[y+1],{x,y+1}});
        }
        return ans;
    }
};


class Solution { // Another Solution - Not Accepted - wrong answer because to it doesn't maintain order of answer.
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> arr;
        int n = nums1.size();
        int m = nums2.size();
        for(auto v: nums1)
            arr.push_back({v,2});
        for(auto v:nums2)
            arr.push_back({v,1});
        sort(arr.begin(),arr.end());
        vector<int> first;
        vector<int> second;
        vector<vector<int>> ans;
        for(auto v: arr){
            if(v[1]==2){
                first.push_back(v[0]);
                for(auto c: second){
                    ans.push_back({c,v[0]});
                    if(ans.size() == k)
                        break;
                }
            }
            else {
                second.push_back(v[0]);
                for(auto c: first){
                    ans.push_back({c,v[0]});
                    if(ans.size() == k)
                        break;
                }
            }
            if(ans.size() == k)
                break;
        }
        return ans;
    }
};