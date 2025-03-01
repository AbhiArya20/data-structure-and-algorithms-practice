#include<bits/stdc++.h>
using namespace std;

// GFG - Longest Possible Route in a Matrix with Hurdles

class Solution {
    void count(int i, int j, int x, int y,int curCount, int &ans,vector<vector<int>> matrix){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]!=1)
            return;
        if(i==x && j==y){
            ans = max(ans,curCount);
            return;
        }
        int val = matrix[i][j];
        matrix[i][j] = -1;
        vector<pair<int,int>> v = {{1,0},{0,1},{-1,0},{0,-1}};
        for(auto c: v){
            count(i+c.first,j+c.second,x,y,curCount+1,ans,matrix);
        }
        matrix[i][j] = val;
    }
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int ans = -1;
        count(xs,ys,xd,yd,0,ans,matrix);
        return ans;
    }
};