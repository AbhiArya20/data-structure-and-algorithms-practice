#include<bits/stdc++.h>
using namespace std;

// LeetCode - 234

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int sum = 0;
        int sign = 1;
        stack<int> stk;
        for(int i = 0; i<n; i++){
            if(isdigit(s[i])){
                int val = 0;
                while(i<n && isdigit(s[i])){
                    val = val*10+(s[i++]-'0');
                }
                i--;
                val = val*sign;
                sum+=val;
                sign = 1;
            }
            if(s[i] == '('){
                stk.push(sum);
                stk.push(sign);
                sum = 0;
                sign = 1;
            }
            if(s[i] == ')'){
                sum*=stk.top();
                stk.pop();
                sum+=stk.top();
                stk.pop();
            }
            if(s[i] == '-'){
                sign*=-1;
            }
        }
        return sum;
    }
};