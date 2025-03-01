#include<bits/stdc++.h>
using namespace std;

// GFG - The Knight's Tour Problem
// CodeStudio - Knight Tour, Practice link - https://www.codingninjas.com/codestudio/problems/knight-tour_1170518



bool isSafe(int i, int j, vector<vector<int>> &ans){
    if(i<0 || j<0 || i>=ans.size() || j>=ans[0].size() || ans[i][j]!=-1)
        return false;
     return true;
}
bool backtracking(int i , int j, int counter, vector<vector<int>> &ans){
    if(counter == ans.size()*ans[0].size())
        return true;
    vector<pair<int,int>> v ={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    for(auto c: v){
        int x = i+c.first;
        int y = j+c.second;
        if(isSafe(x,y,ans)){
            ans[x][y] = counter;
            if(backtracking(x,y,counter+1,ans)){
                return true;
            }
            ans[x][y] = -1;
        }
    }
    return 0;
}
vector<vector<int>> knightTour(int n, int m) {
    vector<vector<int>> ans(n,vector<int> (m,-1));
    ans[0][0] = 0;
    if(backtracking(0,0,1,ans))
        return ans;
    ans[0][0] = -1;
    return ans;
}