#include<bits/stdc++.h>
using namespace std;

// GFG - M-Coloring Problem

class Solution{ // Not accepted but right O(m^n)
    bool isSafe(int m,int n,bool graph[101][101],vector<int> &  color){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(graph[i][j] == true && color[i] == color[j])
                    return false;
            }
        }
        return true;
    }
    bool backtracking(int i, int m, int n, bool graph[101][101], vector<int> & color){
        if(i==n){
            return isSafe(m,n,graph,color);
        }
        for(int j = 1; j<=m; j++){
            color[i] = j;
            if(backtracking(i+1,m,n,graph,color)){
                return true;
            }
            color[i]=0;
        }
        return false;
    }
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        return backtracking(0,m,n,graph,color);
    }
};






class Solution{ // Accepted
    bool isSafe(int c,int p,int n,bool graph[101][101],vector<int> &color){
        for (int i = 0; i < n; i++)
            if (graph[p][i] && c == color[i])
                return false;
        return true;
    }
    bool backtracking(int i, int m, int n, bool graph[101][101], vector<int> & color){
        if(i==n){
            return true;
        }
        for(int j = 1; j<=m; j++){
            if(isSafe(j,i,n,graph,color)){
                color[i] = j;
                if(backtracking(i+1,m,n,graph,color)){
                    return true;
                }
                color[i]=0;
            }
        }
        return false;
    }
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        return backtracking(0,m,n,graph,color);
    }
};
