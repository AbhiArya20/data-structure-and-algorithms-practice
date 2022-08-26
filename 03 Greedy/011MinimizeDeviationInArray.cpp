#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1675

class Solution { // My Approach
    int maxOddFun(int n){
        while(n%2==0){
            n/=2;
        }
        return n;
    }
public:
    int minimumDeviation(vector<int>& nums) {
        int maxOdd = 0;
        int mini = 1e9;
        int count = 0;
        priority_queue<int> pq;
        for(auto v: nums){
            if(v&1){
                v*=2;
                count++;
            }
            pq.push(v);
            mini = min(mini, v);
            int val = maxOddFun(v);
            maxOdd = max(maxOdd, val);
        }
        int ans = 1e9;
        while(pq.top()>maxOdd){
            int top = pq.top();
            pq.pop();
            ans = min(ans,top-mini);
            top/=2;
            mini = min(mini, top);
            pq.push(top);
        }
        while(pq.size()>1){
            pq.pop();
        }        
        ans = min(ans, maxOdd-pq.top());
        return ans;
    }
};

class Solution { // Anothers Approach
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto &v: nums){
            if(v&1){
                v*=2;
            }
            pq.push(v);
        }
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int ans = maxi - mini;
        while(pq.top()%2==0){
            int top = pq.top();
            pq.pop();
            ans = min(ans,top-mini);
            top/=2;
            mini = min(mini, top);
            pq.push(top);
        }     
        ans = min(ans,pq.top()-mini);
        return ans;
    }
};