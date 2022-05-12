#include<bits/stdc++.h>
using namespace std;

// GFG - Permutation with Spaces

class Solution{
    void perm(int i, string &s, vector<string> & ans){
        if(i>=s.size()){
            ans.push_back(s);
            return;
        }
        s.insert(s.begin()+i, ' ');
        perm(i+2, s, ans);
        s.erase(s.begin()+i);
        perm(i+1, s, ans);
    }
public:
    vector<string> permutation(string S){
        vector<string> ans;
        perm(1,S, ans);
        return ans;
    }
};