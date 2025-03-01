#include<bits/stdc++.h>
using namespace std;

// LeetCode - 54
// GFG - Spirally traversing a Matrix


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        int totalCount = r*c;
        int rs = 0,re = r-1, cs = 0, ce = c-1;
        while(rs<=re && cs<=ce){
            for(int i = cs; i<=ce && totalCount; i++){
                ans.push_back(matrix[rs][i]);
                totalCount--;
            }
            rs++;
            for(int i = rs; i<=re && totalCount; i++){
                ans.push_back(matrix[i][ce]);
                totalCount--;
            }
            ce--;
            for(int i = ce; i>=cs && totalCount; i--){
                ans.push_back(matrix[re][i]);
                totalCount--;
            }
            re--;
            for(int i = re; i>=rs && totalCount; i--){
                ans.push_back(matrix[i][cs]);
                totalCount--;
            }
            cs++;
        }
        return ans;
    }
};


// LeetCode - 59

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int> (n));
        int totalCount = n*n;
        int rs = 0,re = n-1, cs = 0, ce = n-1;
        int count = 1;
        while(rs<=re && cs<=ce){
            for(int i = cs; i<=ce && totalCount; i++){
                ans[rs][i] = count;
                count++;
                totalCount--;
            }
            rs++;
            for(int i = rs; i<=re && totalCount; i++){
                ans[i][ce] = count;
                count++;
                totalCount--;
            }
            ce--;
            for(int i = ce; i>=cs && totalCount; i--){
                ans[re][i]=count;
                count++;
                totalCount--;
            }
            re--;
            for(int i = re; i>=rs && totalCount; i--){
                ans[i][cs] = count;
                count++;
                totalCount--;
            }
            cs++;
        }
        return ans;
    }
};


// LeetCode - 885

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int dir = 0;
        int size = 1;
        int curSize = 0;
        while(ans.size()<rows*cols){
            if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                ans.push_back({rStart,cStart});
            if(dir%4==0){
                cStart++;
            }
            if(dir%4==1){
                rStart++;
            }
            if(dir%4==2){
                cStart--;
            }
            if(dir%4==3){
                rStart--;
            }
            curSize++;
            if(curSize==size){
                dir++;
                curSize = 0;
                if(dir%2==0)
                    size++;
            }
        }
        return ans;
    }
};





// Leetcode - 2326

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int> (n));
        int totalCount = n*m;
        int rs = 0,re = m-1, cs = 0, ce = n-1;
        while(rs<=re && cs<=ce){
            for(int i = cs; i<=ce && totalCount; i++){
                if(head){
                    ans[rs][i] = head->val;
                    head = head->next;
                }else{
                    ans[rs][i] = -1;
                }
                totalCount--;
            }
            rs++;
            for(int i = rs; i<=re && totalCount; i++){
                if(head){
                    ans[i][ce] = head->val;
                    head = head->next;
                }else{
                    ans[i][ce] = -1;
                }
                totalCount--;
            }
            ce--;
            for(int i = ce; i>=cs && totalCount; i--){
                if(head){
                    ans[re][i] = head->val;
                    head = head->next;
                }else{
                    ans[re][i] = -1;
                }
                totalCount--;
            }
            re--;
            for(int i = re; i>=rs && totalCount; i--){
                if(head){
                    ans[i][cs] = head->val;
                    head = head->next;
                }else{
                    ans[i][cs] = -1;
                }
                totalCount--;
            }
            cs++;
        }
        return ans;
    }
};
