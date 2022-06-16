#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1601

class Solution {
    int ans = 0;
    void getAns(int i, int n, int l, vector<int> &temp, vector<vector<int>> & requests){
        if(i==requests.size()){
            for(int i : temp)
                if(i!=0)
                    return;
            ans = max(ans, l);
            return;
        }
        getAns(i+1, n, l, temp, requests);
        temp[requests[i][0]]--;
        temp[requests[i][1]]++;
        getAns(i+1,n,l+1,temp,requests);
        temp[requests[i][0]]++;
        temp[requests[i][1]]--;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> temp(n);
        getAns(0,n,0,temp,requests);
        return ans;
    }
};