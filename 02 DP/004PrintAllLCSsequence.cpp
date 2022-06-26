#include<bits/stdc++.h>
using namespace std;

// GFG - Print All LCS sequences

#define N 55
class Solution
{
    vector<vector<int>> dp;
    void getAllLCS(int ss,int ts, int curlen, int len,string curStr, string s, string t, vector<string> &ans){
        if(curlen == len){
            ans.push_back(curStr);
            return;
        }
        if(ss==s.size() || ts==t.size())
            return;
        for(char c = 'a'; c<='z'; c++){
            bool isGet = false;
            for(int i = ss; i<s.size(); i++){
               if(c==s[i]){
                   for(int j = ts; j<t.size(); j++){
                       if(c==t[j] && dp[i][j] == len-curlen){
                           curStr += c;
                           getAllLCS(i+1,j+1,curlen+1,len,curStr,s,t,ans);
                           isGet = true;
                           curStr.pop_back();
                           break;
                       }
                   }
               }
             if(isGet)
               break;  
            }
        }
    }
    int LCS(int i, int j, string st, string s, string t, vector<string> &ans){
        if(i>=s.size() || j>=t.size()){
           return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]= 1+LCS(i+1,j+1,st+s[i],s,t,ans);
        return dp[i][j]= max(LCS(i+1,j,st,s,t,ans),LCS(i,j+1,st,s,t,ans));
    }
	public:
		vector<string> all_longest_common_subsequences(string s, string t){
		    dp.resize(N,vector<int>(N,-1));
		    vector<string> ans;
		    int len = LCS(0,0,"",s,t,ans);
		    getAllLCS(0,0,0,len,"",s,t,ans);
		    return ans;
		}
};