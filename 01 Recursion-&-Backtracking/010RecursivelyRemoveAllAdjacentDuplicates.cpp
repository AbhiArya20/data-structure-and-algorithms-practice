#include<bits/stdc++.h>
using namespace std;

// GFG - Recursively remove all adjacent duplicates

class Solution{
    string st = "";
    void removes(string s){
        int n = s.size();
        string t = "";
        bool isRemoved = false;
        for(int i = 0;i<n; i++){
            bool isRem = false;
            while(t!="" && t[t.size()-1]==s[i] && i<n){
                isRem = true;
                i++;
            }
            if(isRem){
                isRemoved = true;
                t.pop_back();
            }
            if(i<n)
                t+=s[i];
        }
        st = t;
        if(isRemoved){
            removes(st);
        }
    }
public:
    string rremove(string s){
        removes(s);
        return st;
    }
};