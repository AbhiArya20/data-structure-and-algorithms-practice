#include<bits/stdc++.h>
using namespace std;

// LeetCode - 282


class Solution { // UnAccepted 
    int precedence(char op){
        if(op == '+'||op == '-')
        return 1;
        if(op == '*'||op == '/')
        return 2;
        return 0;
    }
    long long applyOp(long long a, long long b, char op){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return -1;
    }
    long long evaluate(string tokens, int target){
        int i;
        stack <long long> values;
        stack <char> ops;
        for(i = 0; i < tokens.length(); i++){
            if(isdigit(tokens[i])){
                string st = "";
                while(i < tokens.length() && isdigit(tokens[i])){
                    st+=tokens[i];
                    i++;
                }
                if(st.size()>1 && st[0]=='0')
                    return target/2;
                long long  val = 0;
                int j = 0;
                while(j < st.length())
                {
                    val = (val*10)+st[j]-'0';
                    j++;
                }
                values.push(val);
                i--;
            }else{
                while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
                    long long val2 = values.top();
                    values.pop();
                     
                    long long val1 = values.top();
                    values.pop();
                     
                    char op = ops.top();
                    ops.pop();
                     
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(tokens[i]);
            }
        }
        while(!ops.empty()){
            long long val2 = values.top();
            values.pop();
                     
            long long val1 = values.top();
            values.pop();
                     
            char op = ops.top();
            ops.pop();
                     
            values.push(applyOp(val1, val2, op));
        }
        return values.top();
    }
    long long getVal(string st,int target){
        return evaluate(st,target);
    }
    void getAll(int i,string str,int target,vector<string> &ans){
        if(i>=str.size()-1){
            int val = getVal(str, target);
            if(val == target)
                ans.push_back(str);
            return;
        }
        getAll(i+1,str,target,ans);
        string f = str.substr(0,i+1);
        string g = str.substr(i+1);
        getAll(i+2,f+"+"+g,target,ans);
        getAll(i+2,f+"*"+g,target,ans);
        getAll(i+2,f+"-"+g,target,ans);
    }
  public:
    vector<string> addOperators(string S, int target) {
        vector<string> ans;
        getAll(0,S,target,ans);
        return ans;
    }
};



class Solution { // Effeciend and Accepted
    void dfs(std::vector<string>& res, const string& num, const int target, string cur, int pos, const long cv, const long pv, const char op) {
        if (pos == num.size() && cv == target) {
            res.push_back(cur);
        } else {
            for (int i=pos+1; i<=num.size(); i++) {
                string t = num.substr(pos, i-pos);
                long now = stol(t);
                if (to_string(now).size() != t.size()) continue;
                dfs(res, num, target, cur+'+'+t, i, cv+now, now, '+');
                dfs(res, num, target, cur+'-'+t, i, cv-now, now, '-');
                dfs(res, num, target, cur+'*'+t, i, (op == '-') ? cv+pv - pv*now : ((op == '+') ? cv-pv + pv*now : pv*now), pv*now, op);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        for (int i=1; i<=num.size(); i++) {
            string s = num.substr(0, i);
            long cur = stol(s);
            if (to_string(cur).size() != s.size()) continue;
            dfs(res, num, target, s, i, cur, cur, '#');         // no operator defined.
        }

        return res;
    }
};