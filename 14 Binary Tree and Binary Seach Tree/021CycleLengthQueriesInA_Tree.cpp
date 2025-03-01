#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2509

class Solution {
    int len(int v){
        int ans = 0;
        while(v){
            ans++;
            v/=2;
        }
        return ans;
    }
    int findLcs(int v1,int v2, int l1, int l2){
        if(l1>l2){
            swap(l1,l2);
            swap(v1,v2);
        }
        while(l2>l1){
            l2--;
            v2/=2;
        }
        while(v1!=v2){
            v1/=2;
            v2/=2;
        }
        return v1;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto v: queries){
            int len1 = len(v[0]);
            int len2 = len(v[1]);
            int lcs = findLcs(v[0],v[1],len1,len2);
            int val = len1+len2-2*len(lcs)+1;
            ans.push_back(val);
        }
        return ans;
    }
};