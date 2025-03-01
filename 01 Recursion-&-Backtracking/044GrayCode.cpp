#include<bits/stdc++.h>
using namespace std;

// LeetCode - 89

class Solution {
    vector<string> getAllCode(int n){
        if(n==1){
            return {"0","1"};
        }
        vector<string> ans  = getAllCode(n-1);
        vector<string> temp;
        for(int i = 0; i<ans.size(); i++){
            string t = ans[i]+"0";
            temp.push_back(t);
        }
        for(int i = ans.size()-1; i>=0; i--){
            string t = ans[i]+"1";
            temp.push_back(t);
        }
        return temp;
    }
    int btoi(string s){
        int p =0;
        int ans = 0;
        for(int i = s.size() -1; i>=0; i--){
            if(s[i]=='1'){
                ans += (int)pow(2,p);
            }
            p++;
        }
        return ans;
    }

public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        vector<string> temp = getAllCode(n);
        for(auto c: temp){
            int val = btoi(c);
            ans.push_back(val);
        }
        return ans;
    }
};