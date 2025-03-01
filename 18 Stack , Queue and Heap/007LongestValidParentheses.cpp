#include<bits/stdc++.h>
using namespace std;

// LeetCode - 32

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            char v = s[i];
            if(v=='('){
                stk.push(i);
            }
            else{
                if(stk.top() !=-1 && s[stk.top()]=='('){
                    stk.pop();
                    ans = max(ans,i-stk.top());
                }else{
                    stk.push(i);
                }
            }
        }
        return ans;
    }
};