#include<bits/stdc++.h>
using namespace std;

// GFG - Decode the String
// LeetCode - 394
class Solution{
public:
    string decodedString(string s){
        string ans = "";
        stack<char> st;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i]==']'){
                string stringInBracket = "";
                while(st.top()!='['){
                    stringInBracket=st.top()+stringInBracket;
                    st.pop();
                }
                st.pop();
                string countInString = "";
                while(!st.empty() && (st.top()>='0' && st.top()<='9')){
                    countInString=st.top()+countInString;
                    st.pop();
                }
                int count = stoi(countInString);
                string stringAfterExpansion = "";
                while(count){
                    stringAfterExpansion+=stringInBracket;
                    count--;
                }
                for(int i = 0; i<stringAfterExpansion.size(); i++){
                    st.push(stringAfterExpansion[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};