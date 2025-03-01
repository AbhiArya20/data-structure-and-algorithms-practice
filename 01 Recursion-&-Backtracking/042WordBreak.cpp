#include<bits/stdc++.h>
using namespace std;

// LeetCode - 140

class Solution {
    void wordBreak(int i, string s,string str, unordered_set<string> &st,vector<string> &ans){
        if(i==s.size()){
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for(int j = i; j<s.size(); j++){
            string temp = s.substr(i,j-i+1);
            if(st.find(temp)!=st.end()){
                wordBreak(j+1,s,str+temp+" ",st,ans);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> st;
        for(auto word: wordDict)
            st.insert(word);
        wordBreak(0,s,"",st,ans);
        return ans;
    }
};


// LeetCode - 139
class Solution {
    bool wordBreak(int i, string s, unordered_set<string> &st,vector<int> &dp){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1)
            return dp[i];
        for(int j = i; j<s.size(); j++){
            string temp = s.substr(i,j-i+1);
            if(st.find(temp)!=st.end()){
                if(wordBreak(j+1,s,st,dp))
                    return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        unordered_set<string> st;
        st.insert(wordDict.begin(), wordDict.end());
        return wordBreak(0,s,st,dp);
    }
};