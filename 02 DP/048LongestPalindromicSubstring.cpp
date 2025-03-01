#include<bits/stdc++.h>
using namespace std;

// LeetCode - 5

class Solution {
    void updateAns(int left, int right,int n,string &ans,string &s){
        int len = 0;
        while(left>=0 && right<n && s[left]==s[right]){
            if(left==right)
                len++;
            else
                len+=2;
            left--;
            right++;
        }
        left++;
        right--;
        int ansLen = ans.size();
        if(len>ansLen){
            ans = s.substr(left, right-left+1);
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i<n; i++){
            updateAns(i,i,n,ans,s);
            updateAns(i,i+1,n,ans,s);
        }
        return ans;
    }
};



// GFG - Count Palindrome Sub-Strings of a String
class Solution{
    void updateAns(int left, int right,int n,int &ans,string &s){
        while(left>=0 && right<n && s[left]==s[right]){
            if(left!=right)
                ans++;
            left--;
            right++;
        }
    }
    public:
    int CountPS(char S[], int N){
        string s = "";
        for(int i = 0; i<N;i++)
            s+=S[i];
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            updateAns(i,i,n,ans,s);
            updateAns(i,i+1,n,ans,s);
        }
        return ans;
    }
};



// GFG - Distinct palindromic substrings

class Solution{
    void updateAns(int left, int right,int n,string &s,unordered_set<string> &mp){
        string ans = "";
        while(left>=0 && right<n && s[left]==s[right]){
            if(left==right){
                ans+=s[left];
            }else{
                ans = s[left]+ans;
                ans += s[right];
            }
            mp.insert(ans);
            left--;
            right++;
        }
    }
  public:
    int palindromeSubStrs(string s) {
        unordered_set<string> mp;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            updateAns(i,i,n,s,mp);
            updateAns(i,i+1,n,s,mp);
        }
        return mp.size();
    }
};