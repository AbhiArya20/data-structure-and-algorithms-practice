#include<bits/stdc++.h>
using namespace std;

// LeetCode - 526

class Solution {
    unordered_set<int> um;
    void getCount(int i, int n, int &ans){
        if(i>n){
            ans++;
            return;
        }
        for(int j = 1; j<=n; j++){
            if(j%i == 0 || i%j==0){
                if(um.find(j) != um.end())
                    continue;
                um.insert(j);
                getCount(i+1,n, ans);
                um.erase(j);
            }
        }
    }
public:
    int countArrangement(int n) {
         int ans = 0;
        getCount(1,n,ans);
         return ans;
    }
};

