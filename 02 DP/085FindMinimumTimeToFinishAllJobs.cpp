#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1723

class Solution { // Backtracking - not accepted
    int f(int mask, int i, int k,int n, vector<int> &val, vector<int> &jobs){
        if(mask == 0){
            int maxi = 0;
            for(auto v: val)
                maxi = max(maxi, v);
            return maxi;
        }
        if(i==k)
            return 1e9;
        int untake = f(mask, i+1, k,n,val, jobs);
        int take = 1e9;
        for(int j = 0; j<n; j++){
            if(mask & (1<<j)){
                val[i] += jobs[j];
                take = min(take, f(mask^(1<<j),i,k,n,val,jobs));
                val[i] -= jobs[j];
            }
        }
        return min(take, untake);
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int mask = (1<<n)-1;
        vector<int> val(k);
        return f(mask,0,k,n,val,jobs);
    }
};


class Solution { // Binary Search and Backtracking - Accepted
    bool backtracking(int i,int target,int n,int k,vector<int> &jobs, vector<int> &val){
        if(i==n)
            return true;
        for(int j = 0; j<k; j++){
            if(val[j]+jobs[i]<=target &&(j==0 || val[j]!=val[j-1])){
                val[j]+=jobs[i];
                if(backtracking(i+1,target,n,k,jobs,val))
                    return true;
                val[j]-=jobs[i];
            }
        }
        return false;
    }
    bool isPos(vector<int> &jobs,int k, int target){
        int n = jobs.size();
        vector<int> val(k);
        return backtracking(0,target,n,k,jobs,val);
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int left = *max_element(jobs.begin(), jobs.end());
        int right = accumulate(jobs.begin(), jobs.end(), 0);
        while(left<right){
            int mid = (left+right)>>1;
            if(isPos(jobs,k,mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};