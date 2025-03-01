#include<bits/stdc++.h>
using namespace std;

// GFG - Floor Fill Algorithms
// LeetCode - 433

class Solution {
    void dfs(int r,int c,int oldColor, int newColor, vector<vector<int>>& image){
        if(r<0 || c<0 || r>=image.size() || c >= image[0].size() || image[r][c]!=oldColor || image[r][c]==newColor){
            return;
        }
        image[r][c]=newColor;
        dfs(r-1,c,oldColor,newColor,image);
        dfs(r,c-1,oldColor,newColor,image);
        dfs(r+1,c,oldColor,newColor,image);
        dfs(r,c+1,oldColor,newColor,image);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr,sc,image[sr][sc],color,image);
        return image;
    }
};