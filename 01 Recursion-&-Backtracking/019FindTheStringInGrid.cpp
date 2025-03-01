#include<bits/stdc++.h>
using namespace std;

// GFG - Find the string in grid

class Solution {
    bool search(int i, int j, vector<vector<char>> &grid,string t,string &word, string way){
        if(t.size()==word.size()){
            return t == word;
        }
        if(i<0 || j<0|| i==grid.size() || j == grid[0].size()){
            return false;
        }
        vector<pair<int,pair<int,string>>> v = {{1,{0,"VD"}},{-1,{0,"VU"}},{0,{1,"HR"}},{0,{-1,"HL"}},{1,{1,"DRD"}},{-1,{1,"DRU"}},{-1,{-1,"DLU"}},{1,{-1,"DLD"}}};
        for(auto c: v){
            if(way == "" && search(i+c.first, j+c.second.first, grid, t+grid[i][j], word, c.second.second)){
                return true;
            }
            else if(c.second.second == way && search(i+c.first, j+c.second.first, grid, t+grid[i][j], word, c.second.second)){
                return true;
            }
        }
        return false;
    }
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    int n = grid.size();
	    int m = grid[0].size();
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            if(word[0]!=grid[i][j])
	                continue;
	            if(search(i, j, grid,"", word,"")){
	                ans.push_back({i,j});
	            }
	        }
	    }
	    return ans;
	}
};