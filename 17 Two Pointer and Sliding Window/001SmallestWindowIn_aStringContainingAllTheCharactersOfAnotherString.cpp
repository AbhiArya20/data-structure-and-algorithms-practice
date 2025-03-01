#include<bits/stdc++.h>
using namespace std;

// GFG - Smallest window in a string containing all the characters of another string

class Solution{
    public:
    string smallestWindow (string s, string p){
        int n = s.size();
        int len = n+10;
        int start = 0;
        int end = 0;
        unordered_map<char,int> um;
        for(auto c: p)
            um[c]++;
        int val = um.size();
        unordered_map<char,int> mp;
        int count = 0;
        for(int i = 0, j = 0; j<n; j++){
            if(um[s[j]]){
                mp[s[j]]++;
                if(um[s[j]]==mp[s[j]])
                    count++;
            }
            while(count==val){
                if(len>j-i+1){
                    start = i;
                    end = j;
                    len = j-i+1;
                }
                if(um[s[i]]){ 
                    if(um[s[i]]==mp[s[i]])
                        count--;
                    mp[s[i]]--;
                }
                i++;
            }
        }
        if(len == n+10)
            return "-1";
        return s.substr(start, end-start+1);
    }
};