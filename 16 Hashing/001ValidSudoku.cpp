#include<bits/stdc++.h>
using namespace std;

// LeetCode - 36

class Solution {
    bool isSafe(int i, int j, vector<vector<char>> & board){
        unordered_map<char,int> row,col,grid;
        for(int l = 0; l<9; l++){
            if(board[i][l]!='.')
                row[board[i][l]]++;
            if(board[l][j]!='.')
                col[board[l][j]]++;
            if(board[3*(i/3)+l/3][3*(j/3)+l%3]!='.')
                 grid[board[3*(i/3)+l/3][3*(j/3)+l%3]]++;
             if(row[board[i][l]]>1 ||col[board[l][j]]>1 || grid[board[3*(i/3)+l/3][3*(j/3)+l%3]]>1)
                return false;
        }  
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(!isSafe(i,j,board))
                    return false;
            }
        }
        return true;
    }
};