#include<bits/stdc++.h>
using namespace std;

// LeetCode - 274

class Solution {
    bool pos(int mid, vector<int>& citations){
        int n = citations.size();
        int pos = lower_bound(citations.begin(), citations.end(),mid) - citations.begin();
        return mid <= (n-pos);
    }
    int hIndex2(vector<int>& citations) {
        int ans = -1;
        int left = 0, right = *max_element(citations.begin(),citations.end());
        while(left<=right){
            int mid = (left+right)>>1;
            if(pos(mid,citations)){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        return hIndex2(citations);
    }
};



// LeetCode - 275

class Solution {
    bool pos(int mid, vector<int>& citations){
        int n = citations.size();
        int pos = lower_bound(citations.begin(), citations.end(),mid) - citations.begin();
        return mid <= (n-pos);
    }
    public:
    int hIndex2(vector<int>& citations) {
        int ans = -1;
        int left = 0, right = *max_element(citations.begin(),citations.end());
        while(left<=right){
            int mid = (left+right)>>1;
            if(pos(mid,citations)){
                ans = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};