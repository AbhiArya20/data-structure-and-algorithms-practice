#include<bits/stdc++.h>
using namespace std;

// LeetCode - 51

class Solution {
    bool isSafe(int i, int j, vector<string> &temp){
        int row = i;
        while(row>=0){
            if(temp[row][j]=='Q')
                return false;
            row--;
        }
        row = i;
        int col = j;
        while(row>=0 && col>=0){
            if(temp[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row = i;
        col = j;
        while(row>=0 && col<temp.size()){
            if(temp[row][col]=='Q')
                return false;
            row--;
            col++;
        }
        return true;
    }
    void backtracking(int row, int n, vector<string> &temp,vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j<n; j++){
            if(isSafe(row,j,temp)){
                temp[row][j] = 'Q';
                backtracking(row+1,n,temp,ans);
                temp[row][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        for(int i = 0;i<n; i++){
            string st = "";
            for(int j = 0; j<n; j++){
                st+=".";
            }
            temp.push_back(st);
        }
        backtracking(0,n,temp,ans);
        return ans;
    }
};