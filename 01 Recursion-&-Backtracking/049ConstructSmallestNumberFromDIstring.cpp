#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2375

class Solution { // May or not accepted
    bool isValid(string &ans, string & pattern){
        int n = pattern.size();
        for(int i = 0; i<n; i++){
            if(pattern[i]=='I' && ans[i+1]<=ans[i])
                return false;
            if(pattern[i]=='D' && ans[i+1]>=ans[i])
                return false;
        }
        return true;
    }
    bool getStr(int i, int n , string &ans, string & pattern, unordered_set<char> &um){
        if(i==n){
            return isValid(ans,pattern);
        }
        for(char c = '1'; c<='9'; c++){
            if(um.find(c)!=um.end())
                continue;
            ans+=c;
            um.insert(c);
            if(getStr(i+1,n,ans,pattern,um))
                return true;
            um.erase(c);
            ans.pop_back();
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        unordered_set<char> um;
        int n = pattern.size();
        string ans = "";
        getStr(0,n+1, ans, pattern, um);
        return ans;
    }
};



class Solution { // Optimized and accepted
    bool isValid(string &ans, string &pattern){
        int n = pattern.size();
        for(int i = 0; i<n; i++){
            if(pattern[i]=='I' && ans[i+1]<=ans[i])
                return false;
            if(pattern[i]=='D' && ans[i+1]>=ans[i])
                return false;
        }
        return true;
    }
    bool getStr(int i, int n , string &ans, string &pattern, unordered_set<char> &um, char prev, char prevAnsChar){
        if(i==n){
            return isValid(ans,pattern);
        }
        if(prev == '*'){
            for(char c = '1'; c<='9'; c++){
                if(um.find(c)!=um.end())
                    continue;
                ans+=c;
                um.insert(c);
                if(getStr(i+1,n,ans,pattern,um,pattern[i], c))
                    return true;
                um.erase(c);
                ans.pop_back();
            }
            return false;
        }
        else if(prev == 'I'){
            for(char c = prevAnsChar; c<='9'; c++){
                if(um.find(c)!=um.end())
                    continue;
                ans+=c;
                um.insert(c);
                if(getStr(i+1,n,ans,pattern,um, pattern[i],c))
                    return true;
                um.erase(c);
                ans.pop_back();
            }
            return false;
        }
        else{
             for(char c = prevAnsChar; c>='1'; c--){
                if(um.find(c)!=um.end())
                    continue;
                ans+=c;
                um.insert(c);
                if(getStr(i+1,n,ans,pattern,um,pattern[i],c))
                    return true;
                um.erase(c);
                ans.pop_back();
            }
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        unordered_set<char> um;
        int n = pattern.size();
        string ans = "";
        getStr(0,n+1, ans, pattern, um, '*', '*');
        return ans;
    }
};