#include<bits/stdc++.h>
using namespace std;

// LeetCode - 37


class Solution { // Less Efficient
    bool isSafe(int i, int j,char k, vector<vector<char>> & board){
        for(int l = 0; l<9; l++){
            if(board[i][l]==k || board[l][j]==k)
                return false;
            if(board[3*(i/3)+l/3][3*(j/3)+l%3]==k){
                return false;
            }
        }  
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char k = '1'; k<='9'; k++){
                        if(isSafe(i,j,k,board)){
                            board[i][j] = k;
                            if(solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};




class Solution { // Nore Efficient
    bool isSafe(int i, int j,char k, vector<vector<char>> & board){
        for(int l = 0; l<9; l++){
            if(board[i][l]==k || board[l][j]==k)
                return false;
            if(board[3*(i/3)+l/3][3*(j/3)+l%3]==k){
                return false;
            }
        }  
        return true;
    }
    bool solve(int i, int j,vector<vector<char>>& board){
        if(i==board.size()-1 && j==board.size())
            return true;
        if(j==board.size()){
            i++;
            j=0;
        }
        if(board[i][j]!='.')
            return solve(i,j+1,board);
        for(char k = '1'; k<='9'; k++){
            if(isSafe(i,j,k,board)){
                board[i][j] = k;
                if(solve(i,j+1,board))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};