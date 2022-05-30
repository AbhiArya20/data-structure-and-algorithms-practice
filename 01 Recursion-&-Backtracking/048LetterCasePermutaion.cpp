#include<bits/stdc++.h>
using namespace std;

// LeetCode - 785


class Solution {
    void getAll(int i, string s,vector<string> &ans){
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
        if(s[i]>='0' && s[i]<='9')
            return getAll(i+1,s,ans);

        getAll(i+1, s,ans);
        if(s[i]>='a' && s[i]<='z'){
            char val = s[i];
            s[i] -= 32;
            getAll(i+1,s,ans);
            s[i]=val;
        }else{ 
            char val = s[i];
            s[i] += 32;
            getAll(i+1,s,ans);
            s[i]=val;
        }   
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        getAll(0,s,ans);
        return ans;
    }
};