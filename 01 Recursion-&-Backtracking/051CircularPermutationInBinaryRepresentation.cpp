#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1238

class Solution {
    vector<string> getAllCode(int n){ // Gray Code - 89
        if(n==1){
            return {"0","1"};
        }
        vector<string> ans  = getAllCode(n-1);
        vector<string> temp;
        for(int i = 0; i<ans.size(); i++){
            temp.push_back(ans[i]+"0");
        }
        for(int i = ans.size()-1; i>=0; i--)
            temp.push_back(ans[i]+'1');
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
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        vector<string> temp = getAllCode(n);
        int i = 0;
        int count = 0;
        for(auto c: temp){
            int val = btoi(c);
            if(val == start)
                count = i;
            ans.push_back(val);
            i++;
        }
        if(count==0)
            return ans;
        reverse(ans.begin(), ans.begin()+count);
        reverse(ans.begin()+count, ans.end());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};