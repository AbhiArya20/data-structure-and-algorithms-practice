#include<bits/stdc++.h>
using namespace std;

// LeetCode - 93
// GFG - Generate IP Address

class Solution {
    bool isValid(string st){
        cout<<st<<endl;
        if(st.size()==1){
            int val = stoi(st);
            if(val>=0 && val<=9){
                return true;
            }
        }else{
            if(st[0]=='0')
                return false;
            for(int i = 0; i<st.size(); i++){
                if(!(st[i]>='0' && st[i]<='9'))
                    return false;
            }
            int val = stoi(st);
            if(val>=1 && val<=255)
                return true;
        }
        return false;
    }
    void ipaddress(int idx, int count , string s, string str,vector<string> &ans){
        if(idx == s.size()){\
            if(count==4){
                str.pop_back();
                ans.push_back(str);
            }
            return;
        }
        for(int j = 1; j<=3 && (idx+j)<=s.size(); j++){
            string st = s.substr(idx,j);
            if(isValid(st)){
                ipaddress(idx+j,count+1,s,str+st+".",ans);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();
        if(n<4 || n>12){
            return ans;
        }
        ipaddress(0,0,s,"",ans);
        return ans;
    }
};