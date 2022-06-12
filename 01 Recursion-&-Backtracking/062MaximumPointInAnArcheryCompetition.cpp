#include<bits/stdc++.h>
using namespace std;

// LeetCode - 2212

class Solution {
    void getAns(int i, int curSum, int &maxSum,int numArrows,vector<int> &temp,vector<int>& aliceArrows,vector<int> &ans){
        if(i<0 || numArrows==0){
            if(curSum>=maxSum){
                temp[0]+=numArrows;
                ans = temp;
                maxSum = max(maxSum,curSum);
                temp[0]-=numArrows;
            }
            return;
        }
        getAns(i-1,curSum, maxSum, numArrows, temp, aliceArrows, ans);
        if(numArrows>aliceArrows[i]){
            temp[i] = aliceArrows[i]+1;
            getAns(i-1,curSum+i, maxSum, numArrows-aliceArrows[i]-1, temp, aliceArrows, ans);
            temp[i] = 0;
        }
    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans;
        vector<int> temp(12);
        int maxSum = -1;
        getAns(11,0,maxSum,numArrows,temp,aliceArrows,ans);
        return ans;
    }
};