#include<bits/stdc++.h>
using namespace std;

// LeetCode - 131
// GFG - Find all possible palindromic partitions of a String

class Solution {
    bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void find(int j, int n, string s, vector<string> temp, vector<vector<string>> &ans){
        if(j>=n){
            ans.push_back(temp);
            return;
        }
        for(int i = j; i<n; i++){
            if(isPalindrome(j,i,s)){
                temp.push_back(s.substr(j,i-j+1));
                find(i+1,n,s,temp,ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.size();
        find(0,n,s,temp,ans);
        return ans;
    }
};