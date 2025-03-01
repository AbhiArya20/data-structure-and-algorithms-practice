#include<bits/stdc++.h>
using namespace std;

// GFG - LCS
// LeetCode - 1143

class Solution{ // Memoization
    int f(int i, int j, int x, int y, string s1, string s2, vector<vector<int>> &dp){
        if(i==x || j==y)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = 1+f(i+1, j+1, x, y, s1, s2, dp);
        return dp[i][j] = max(f(i+1, j, x, y, s1, s2, dp), f(i, j+1, x, y, s1, s2, dp));
    }
    public:
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x,vector<int>(y,-1));
        return f(0,0,x,y,s1,s2,dp);
    }
};


class Solution{ // Tabulation
    public:
    int lcs(int x, int y, string s1, string s2){
        vector<vector<int>> dp(x+1,vector<int>(y+1));
        for(int i = x-1; i>=0; i--){
            for(int j = y-1; j>=0; j--){
                if(s1[i]==s2[j])
                    dp[i][j] = 1+dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};

// GFG - Printing LCS
class Solution{   
public:
    string longestPalindrome(string s){
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for (int i=0; i<=n; i++){
            for (int j=0; j<=n; j++){
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string ans = "";
        int i = n, j = n;
        while (i > 0 && j > 0){
            if (s[i-1] == t[j-1]){
                ans+=s[i-1];
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        return ans;
    }
};



// GFG - LCS of Three String
class Solution{
    int f(int i, int j,int k, int x, int y, int z, string s1, string s2,string s3, vector<vector<vector<int>>> &dp){
            if(i==x || j==y || k==z)
                return 0;
            if(dp[i][j][k]!=-1)
                return dp[i][j][k];
            if(s1[i]==s2[j] && s2[j]==s3[k])
                return dp[i][j][k] = 1+f(i+1,j+1,k+1, x, y,z, s1, s2,s3, dp);
            return dp[i][j][k] = max(f(i+1, j,k, x, y,z, s1, s2,s3, dp), max(f(i,j+1,k, x, y,z, s1, s2,s3, dp),f(i, j,k+1, x, y,z, s1, s2,s3 ,dp)));
    }
    public:
    int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3){
        
        vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
        return f(0,0,0,n1,n2,n3,s1,s2,s3,dp);
    }
};
