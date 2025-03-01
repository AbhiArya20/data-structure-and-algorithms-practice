#include<bits/stdc++.h>
using namespace std;

// LeetCode - 74 , 240
// GFG - Search in a matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]<target)
                row++;
            else
                col--;
        }
        return false;
    }
};