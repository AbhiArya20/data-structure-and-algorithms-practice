#include<bits/stdc++.h>
using namespace std;

// LeetCode - 301

class Solution {
    unordered_set<string> um;
    int noOfInvalid(string &s){
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    }
    void getAns(int n, string s, vector<string> &ans){
        if(n==0){
            if(noOfInvalid(s)==0)
                ans.push_back(s);
            return;
        }
        for(int i = 0; i<s.size(); i++){
            if(s[i]!=')' and s[i] != '(')
                continue;
            string s1 = s.substr(0,i);
            string s2 = s.substr(i+1);
            string s3 = s1+s2;
            if(um.find(s3) == um.end()){
                um.insert(s3);
                getAns(n-1,s3,ans);
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = noOfInvalid(s);
        vector<string> ans;
        getAns(n,s,ans);
        return ans;
    }
};