#include<bits/stdc++.h>
using namespace std;

// GFG - KMP Algorithm

class Solution{
    vector<int> longestProperPrefix(string pat){
        int m = pat.size();
        vector<int> longestPrefixSufix(m);
        int len = 0;
        for(int i = 1; i<m; i++){
            if(pat[i]==pat[len]){
                len++;
                longestPrefixSufix[i]=len;
            }else{
                if(len!=0){
                    len = longestPrefixSufix[len-1];
                    i--;
                }
            }
        }
        return longestPrefixSufix;
    }
    public:
    vector<int> KMP(string txt, string pat){
        vector<int> ans;
        int n = txt.size();
        int m = pat.size();
        vector<int> longestPrefixSufix = longestProperPrefix(pat);
        int j = 0;
        for(int i= 0; (n - i) >= (m - j); ){
            if(pat[j]==txt[i]){
                j++;
                i++;
            }
            if(j == m){
                ans.push_back(i-j);
                j = longestPrefixSufix[j-1];
            }
            else if(i<n && pat[j]!=txt[i]){
                if(j!=0){
                    j = longestPrefixSufix[j-1];
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
};