#include<bits/stdc++.h>
using namespace std;

// GFG - Matrix Exponentiation

class Solution {
    int mod = 1e9+7;
    vector<vector<int>> identity(int n){
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i = 0; i<n; i++)
            ans[i][i]=1;
        return ans;
    }
    vector<vector<int>> matrixMulti(vector<vector<int>> &mat1,vector<vector<int>> &mat2){
        int n = mat1.size();
        int m = mat2[0].size();
        int o = mat1[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                for(int k = 0; k<o; k++){
                    ans[i][j] += (mat1[i][k] * (long long)mat2[k][j])%mod;
                    ans[i][j]%=mod;
                }
            }
        }
        return ans;
    }
    vector<vector<int>> matrixExp(int n, vector<vector<int>> mat){
        if(n==0)
            return identity(2);
        auto matExp = matrixExp(n/2,mat);
        matExp = matrixMulti(matExp,matExp);
        if(n&1)
            matExp = matrixMulti(matExp,mat);
        return matExp;
    }
public:
    int FindNthTerm(long long int n) {
        vector<vector<int>> mat = {{1,1},{1,0}};
        vector<vector<int>> base = {{0},{1}};
        auto matExp = matrixExp(n,mat);
        auto ansMat = matrixMulti(base, matExp);
        return ansMat[1][0];
    }
};

