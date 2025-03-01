#include<bits/stdc++.h>
using namespace std;

// LeetCode - 205
// GFG - Isomorphic String

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int n = t.size();
        unordered_map<char,char> um;
        unordered_map<char,bool> done;
        for(int i = 0; i<n; i++){
            if(um.find(s[i])==um.end()){
                if(done.find(t[i])!=done.end())
                    return false;
                um[s[i]] = t[i];
                done[t[i]] = true;
            }else{
                if(um[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};