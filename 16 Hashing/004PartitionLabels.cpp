#include<bits/stdc++.h>
using namespace std;

// LeetCode - 763

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> start,end;
        int i = 0;
        for(auto c: s){
            if(start.find(c)==start.end())
                start[c]=i;
            end[c]=i;
            i++;
        }
        int n = s.size();
        int prev = -1;
        int j = 0;
        for(int i = 0; i<n; i++){
            j = max(j,end[s[i]]);
            if(i==j){
                ans.push_back(i-prev);
                prev = i;
            }
        }
        
        return ans;
    }
};