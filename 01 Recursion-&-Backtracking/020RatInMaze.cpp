#include<bits/stdc++.h>
using namespace std;

// GFG - Rat in Maze Problem

class Solution{
    void backtracking(int i, int j,string st, vector<vector<int>> &m,int n,vector<string> &ans){
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0)
            return;
        if(i==n-1 && j == n-1){
            ans.push_back(st);
            return;
        }
        int val = m[i][j];
        m[i][j] = 0;
        backtracking(i+1,j,st+"D",m,n,ans);
        backtracking(i-1,j,st+"U",m,n,ans);
        backtracking(i,j-1,st+"L",m,n,ans);
        backtracking(i,j+1,st+"R",m,n,ans);
        m[i][j] = val;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        backtracking(0,0,"",m,n,ans);
        return ans;
    }
};




// GFG - Rat in Maze with multiple jump Problem
class Solution {
    bool isSafe(int i, int j,int n, vector<vector<int>> &matrix){
        if(i<0 || j<0 || i>=n || j>=n || matrix[i][j]==0)
            return false;
        return true;
    }
    bool backtracking(int i, int j, vector<vector<int>> &matrix,int n,vector<vector<int>> &ans){
        
        if(i==n-1 && j == n-1){
            ans[i][j] = 1;
            return true;
        }
        if(isSafe(i,j,n,matrix)){
            int value = matrix[i][j];
            ans[i][j]=1;
            for(int k = 1; k<=value; k++){
                if(backtracking(i,j+k,matrix,n,ans))
                    return true;
                if(backtracking(i+k,j,matrix,n,ans))
                    return true;
            }
            ans[i][j]=0;
        }
        return false;
    }
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   
	   int n = matrix.size();
	   vector<vector<int>> ans(n,vector<int>(n,0));
       if(backtracking(0,0,matrix,n,ans))
            return ans;
       ans.clear();
       ans.push_back({-1});
       return ans;
	}

};