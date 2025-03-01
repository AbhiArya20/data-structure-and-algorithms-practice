#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1593

class Solution {
    void getAns(int s,int n,string st,unordered_set<string> &um, int &ans){
        if(s==n){
            int size = um.size();
            ans = max(ans, size);
            return;
        }
        string temp = "";
        for(int i = s; i<n; i++){
            temp+=st[i];
            if(um.find(temp) != um.end())
                continue;
            um.insert(temp);
            getAns(i+1, n,st,um,ans);
            um.erase(temp);
        }
    }
public:
    int maxUniqueSplit(string s) {
        int n = s.size();
        unordered_set<string> um;
        int ans = 0;
        getAns(0, n, s, um, ans);
        return ans;
    }
};