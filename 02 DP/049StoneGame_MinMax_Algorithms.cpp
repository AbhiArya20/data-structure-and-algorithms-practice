#include<bits/stdc++.h>
using namespace std;

// LeetCode - 877

class Solution {
    int f(int s, int e, bool alice,vector<int>& piles,vector<vector<vector<int>>> &dp){
        if(s>e)
            return 0;
        if(dp[s][e][alice]!=-1)
            return dp[s][e][alice];
        if(alice){
            int start = piles[s] + f(s+1,e,false,piles,dp);
            int end = piles[e] + f(s,e-1,false,piles,dp);
            return dp[s][e][alice] = max(start,end);
        }else{
            int start = f(s+1,e,true,piles,dp);
            int end = f(s,e-1,true,piles,dp);
            return dp[s][e][alice] = min(start,end);
        }
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int ans = f(0,n-1,true,piles,dp);
        return ans > 0;

    }
};


// LeetCode - 1140

class Solution {
    vector<vector<vector<int>>> dp;
    int f(int i, int m,int alice, int n, vector<int> &piles){
        if(i==n){
            return 0;
        }
        if(dp[i][m][alice]!=-1)
            return dp[i][m][alice];
        if(alice){
            int ans = INT_MIN;
            int sum = 0;
            for(int j = i; j<= min(i+2*m-1,n-1); j++){
                sum+=piles[j];
                int val = sum + f(j+1,max(m,j-i+1),1-alice,n,piles);
                ans = max(ans,val);
            }
            return dp[i][m][alice] = ans;
        }else{
            int ans = INT_MAX;
            for(int j = i; j<= min(i+2*m-1,n-1); j++){
                int val = f(j+1,max(m,j-i+1),1-alice,n,piles);
                ans = min(ans,val);
            }
            return dp[i][m][alice] = ans;
        }
        return 0;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n,vector<vector<int>> (n*2, vector<int>(2,-1)));
        return f(0,1,true,n,piles);
    }
};


// LeetCode - 1406
class Solution {
    vector<vector<int>> dp;
    int f(int i, int n,int alice, vector<int> &s){
        if(i==n)
            return 0;
        if(dp[i][alice]!=-1)
            return dp[i][alice];
        if(alice){
            int sum = 0,ans = INT_MIN;
            for(int j = i; j<=min(n-1,i+2); j++){
                sum+=s[j];
                ans = max(ans, sum+f(j+1,n,1-alice,s));
            }
            return dp[i][alice] = ans;
        }else{
            int sum = 0,ans = INT_MAX;
            for(int j = i; j<=min(n-1,i+2); j++){ 
                sum += s[j];
                ans = min(ans, -sum + f(j+1,n,1-alice,s));
            }
            return dp[i][alice] = ans;
        }
    }
public:
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        dp.resize(n+1,vector<int>(2 ,-1));
        int ans = f(0,n,true,s);
        cout<<ans;
        if(ans>0)
            return "Alice";
        if(ans<0)
            return "Bob";
        return "Tie";
    }
};



// LeetCode 1510
class Solution {
    vector<vector<int>> dp;
    bool f(int n, bool alice){
        if(n==0)
            return (!alice);
        if(dp[n][alice]!=-1)
            return dp[n][alice];
        if(alice){
            bool ans = false;
            for(int i = 1; i*i<=n; i++){
                if(i*i<=n)
                    ans = ans || f(n-(i*i), 1-alice);
            }
            return dp[n][alice] = ans;
        }else{
            int count = 0;
            int ans = 0;
            for(int i = 1; i*i<=n; i++){
                if(i*i<=n){
                    count++;
                    ans += f(n-(i*i), 1-alice);
                }
            }
            return dp[n][alice] = ans==count;
        }
    }
public:
    bool winnerSquareGame(int n) {
        dp.resize(n+1, vector<int>(2,-1));
        return f(n,1);
    }
};



// LeetCode - 1563

class Solution {
    vector<vector<int>> dp;
    int f(int s, int e, vector<int>& stoneValue){
        if(s == e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int right = 0;
        for(int i = s; i<=e; i++)
            right += stoneValue[i];
        int left = 0;
        int ans = 0;
        for(int i = s; i<e; i++){
            left += stoneValue[i];
            right -= stoneValue[i];
            if(left>right)
                ans = max(ans,right+f(i+1,e,stoneValue));
            else if(left<right)
                ans = max(ans,left+f(s,i,stoneValue));
            else 
                ans = max(ans, left+max(f(i+1,e,stoneValue),f(s,i,stoneValue)));
        }
        return dp[s][e] = ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n, vector<int>(n, -1));
        return f(0, n-1, stoneValue);
    }
};


// LeetCode - 1690

class Solution {
    vector<int> sums;
    vector<vector<int>> dp;
    int f(int s, int e,int alice, vector<int> &stones){
        if(s>=e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int sum = sums[e+1]-sums[s];
        if(alice){
            int start = sum + f(s+1, e, false, stones) - stones[s];
            int end = sum + f(s, e-1, false, stones) - stones[e];
            return dp[s][e] = max(start, end);
        }else{
            int start = f(s+1, e, true, stones) - sum + stones[s];
            int end = f(s, e-1, true, stones) - sum + stones[e];
            return dp[s][e] =  min(start, end);
        }
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        dp.resize(n, vector<int>(n, -1));
        sums.push_back(0); 
        for(int i = 0; i<n; i++){
            sums.push_back(sums[i]+stones[i]);
        }
        return f(0, n-1,true, stones);
    }
};


// LeetCode - 1686

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int,int>> pq1,pq2;
        for(int i = 0; i<n; i++){
            pq1.push({aliceValues[i],i});
            pq2.push({bobValues[i],i});
        }
        unordered_set<int> st;
        int alice = 0;
        int bob = 0;
        bool aliceChance = true;
        while(!pq1.empty()){
            if(aliceChance){
                if(pq1.top().first >= pq2.top().first){
                    alice+=pq1.top().first;
                    st.insert(pq1.top().second);
                }else{
                    alice+=aliceValues[pq2.top().second];
                    st.insert(pq2.top().second);
                }
            }else{
                if(pq2.top().first >= pq1.top().first){
                    bob+=pq2.top().first;
                    st.insert(pq2.top().second);
                }else{
                    bob+=bobValues[pq1.top().second];
                    st.insert(pq2.top().second);
                }
            }  
            aliceChance = !aliceChance;
            while(!pq1.empty() && st.find(pq1.top().second)!=st.end()){
                pq1.pop();
            }
            while(!pq2.empty() && st.find(pq2.top().second)!=st.end()){
                pq2.pop();
            }
        }
        if(alice==bob) return 0;
        return (alice>bob)? 1: -1;
    }
};