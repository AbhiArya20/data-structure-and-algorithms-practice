#include<bits/stdc++.h>
using namespace std;

// LeetCode - 22

class Solution {
    void generate(int n, string s,set<string> &st){
        if(n==0){
            st.insert(s);
            return;
        }
        for(int i = 0; i<s.size(); i++){
            string s1 = s.substr(0,i);
            string s2 = s.substr(i);
            generate(n-1,s1+"()"+s2,st);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        set<string> st;
        generate(n-1,"()",st);
        ans.insert(ans.begin(),st.begin(),st.end());
        return ans;
    }
};