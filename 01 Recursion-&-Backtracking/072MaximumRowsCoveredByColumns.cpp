#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2397

class Solution {
    void backtrackin(int col, int numSelect,int &ans,unordered_set<int> &selectedCol,unordered_set<int> &selectedRow,vector<vector<int>> &matrix){
        if(numSelect==0){
            int tillNow = selectedRow.size();
            ans = max(ans, tillNow);
            return;
        }    
        if(col>=matrix[0].size())
            return;
        backtrackin(col+1, numSelect,ans,selectedCol,selectedRow,matrix);
        selectedCol.insert(col);
        unordered_set<int> rowThatToBeSelect;
        for(int i = 0; i<matrix.size(); i++){
            if(selectedRow.find(i)!=selectedRow.end())
                continue;
            bool shouldget = true;
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] && selectedCol.find(j)==selectedCol.end()){
                    shouldget = false;
                    break;
                }
            }
            if(shouldget){
                rowThatToBeSelect.insert(i);
            }
        }
        for(auto v: rowThatToBeSelect){
            selectedRow.insert(v);
        }        
        backtrackin(col+1, numSelect-1,ans,selectedCol,selectedRow,matrix);
        for(auto v: rowThatToBeSelect){
            selectedRow.erase(v);
        }
        selectedCol.erase(col);
    }
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        unordered_set<int> selectedCol, selectedRow;
        backtrackin(0,numSelect,ans,selectedCol,selectedRow,matrix);
        return ans;
    }
}; 
