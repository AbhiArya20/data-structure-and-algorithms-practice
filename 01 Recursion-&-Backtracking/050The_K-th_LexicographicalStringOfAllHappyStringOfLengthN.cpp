#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1415

class Solution {
    string ans = "";
    void getHappy(int i, int n, int &k, char prev, string st){
        if(i==n){
            if(k == 0 && ans == "")
                ans = st;
            k--;
            return;
        }
        for(char c = 'a'; c<='c'; c++){
            if(c==prev)
                continue;
            st+=c;
            getHappy(i+1,n, k, c, st);
            st.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        k--;
        getHappy(0,n,k,'0',"");
        return ans;
    }
};