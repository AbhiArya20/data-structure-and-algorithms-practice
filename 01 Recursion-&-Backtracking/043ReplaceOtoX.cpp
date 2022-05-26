#include<bits/stdc++.h>
using namespace std;

// GFG - Replace O's with X's

class Solution{
    void dfs(int i, int j, int n, int m, vector<vector<char>> &mat){
        if(i<0 || j<0 || i==n || j==m || mat[i][j]=='-' || mat[i][j]=='X'){
            return;
        }
        mat[i][j]='-';
        dfs(i,j-1,n,m,mat);
        dfs(i,j+1,n,m,mat);
        dfs(i-1,j,n,m,mat);
        dfs(i+1,j,n,m,mat);
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1 ){
                    if(mat[i][j] == 'O'){
                        dfs(i,j,n,m,mat);
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]=='-'){
                    mat[i][j] = 'O';
                }else{
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};