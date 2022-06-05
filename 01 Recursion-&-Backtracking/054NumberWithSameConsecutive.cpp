#include<bits/stdc++.h>
using namespace std;

// LeetCode - Number With Same Consecutive Difference

class Solution {
    void getAll(int i, int size,int n,int k,vector<int>& ans){
        if(size == n){
            ans.push_back(i);
            return;
        }
        if(k==0){
            getAll(i*10+((i%10)+k),size+1,n,k,ans);
        }else{
            if((i%10)+k<=9){
                getAll(i*10+((i%10)+k),size+1,n,k,ans);
            }
            if((i%10)-k>=0){
                getAll(i*10+((i%10)-k),size+1,n,k,ans);
            }
        }
        
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i = 1; i<=9; i++){
            getAll(i,1,n,k,ans);
        }
        return ans;
    }
};