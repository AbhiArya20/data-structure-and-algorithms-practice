#include<bits/stdc++.h>
using namespace std;

// LeetCode - 30

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int size = words.size();
        int m = words[0].size();
        int k = size*m;
        unordered_map<string,vector<int>> um;
        for(int i = 0; i<size; i++){
            um[words[i]].push_back(i);
        }
        vector<int> ans;
        for(int i = 0; i+k-1<n; i++){
            auto newUm = um;
            int isOk = true;
            for(int j = i; j<i+k; j+=m){
                string st = s.substr(j,m);
                if(newUm.find(st)==newUm.end() || newUm[st].size()==0){
                    isOk = false;
                    break;
                }else{
                    newUm[st].pop_back();
                }
            }
            if(isOk)
                ans.push_back(i);
        }
        return ans;
    }
};