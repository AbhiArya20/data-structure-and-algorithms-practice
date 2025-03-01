#include<bits/stdc++.h>
using namespace std;

// LeetCode - 300

class Solution{ // Memoization
    int f(int i,int prevIdx, int n,int a[], vector<vector<int>> &dp){
        if(i==n)
            return 0;
        if(dp[i][prevIdx+1] != -1)
            return dp[i][prevIdx+1];
        int untake = f(i+1, prevIdx, n, a,dp);
        int take = 0;
        if(prevIdx==-1 || a[prevIdx]<a[i])
            take = 1+f(i+1,i,n,a,dp);
        return dp[i][prevIdx+1] = max(take,untake);
    }
    public:
    int longestSubsequence(int n, int a[]){
       vector<vector<int>> dp(n,vector<int>(n+1, -1));
       return f(0,-1,n,a, dp);
    }
};



class Solution{ // Tabulation
    public:
    int longestSubsequence(int n, int a[]){
       int ans = 1;
       vector<int> dp(n,1);
       for(int i = 1; i<n; i++){
           for(int j = 0; j<i; j++){
               if(a[i]>a[j] && dp[i]<dp[j]+1)
                    dp[i] = dp[j]+1;
           }
           ans = max(ans, dp[i]);
       }
       return ans;
    }
};



class Solution{ // Using Binary Search
    public:
    int longestSubsequence(int n, int a[]){
       vector<int> list;
       list.push_back(a[0]);
       for(int i = 1; i<n; i++){
           auto it = lower_bound(list.begin(), list.end(), a[i]);
           if(it == list.end())
                list.push_back(a[i]);
            else
                *it = a[i];
       }
       return list.size();
    }
};





// GFG - Maximum sum increasing subsequence
class Solution{
	public:
	int maxSumIS(int arr[], int n)  {  
	    vector<int> dp(n);
	    int ans = 0;
	    for(int i = 0; i<n; i++){
    	    int sum = 0;
	        for(int j = 0; j<i; j++){
	            if(arr[i]>arr[j])
	                sum = max(sum, dp[j]);
	        }
	        dp[i] = arr[i]+sum;
	        ans = max(ans, dp[i]);
	    }
	    return ans;
	}  
};



// GFG - Printing Maximum Sum Increasing Subsequence
class Solution{
public:
    vector<int> maxSumSequence(int N, int A[]){
        vector<int>dp(N), parent(N);
        int ans = 0;
        int start=0;
        for(int i = 0; i<N; i++){
            int maxi = 0;
            int p = i;
            for(int j=0; j<i; j++){
                if(A[i]>A[j]){
                    if(maxi<dp[j]){
                        maxi = dp[j];
                        p = j;
                    }
                }
            }
            parent[i]=p;
            dp[i] = maxi + A[i];
            if(ans<dp[i]){
                ans = dp[i];
                start = i;
            }
        }
        vector<int> res;
        while(parent[start]!=start){
            res.push_back(A[start]);
            start = parent[start];
        }
        res.push_back(A[start]);
        reverse(res.begin(), res.end());
        return res;
    }
};


// LeetCode - 2407

class Segment{
    int n;
    vector<int> arr;
    vector<int> segmentTree;
    void buildSegment(int index, int start, int end){
        if(start == end){
            segmentTree[index] = arr[start];
            return;
        }

        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        buildSegment(leftIndex, start, mid);
        buildSegment(rightIndex, mid+1, end);

        segmentTree[index] = max(segmentTree[leftIndex], segmentTree[rightIndex]);
    }
    int getMaxFromSegment(int index, int start, int end, int left,int right){
        if(end<left || start>right)
            return INT_MIN;
        if(start >= left && end<=right){    
            return segmentTree[index];
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        int leftAns = getMaxFromSegment(leftIndex, start, mid, left, right);
        int rightAns = getMaxFromSegment(rightIndex, mid+1, end, left, right);

        return max(leftAns, rightAns);
    }
    void updateSegment(int index, int start, int end, int indexWhereUpdate, int val){
        if(start == end){
            arr[indexWhereUpdate] = val;
            segmentTree[index] = val;
            return;
        }
        
        int mid = (start+end)>>1;
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;

        if(indexWhereUpdate <= mid)
            updateSegment(leftIndex,start,mid,indexWhereUpdate,val);
        else
            updateSegment(rightIndex,mid+1,end,indexWhereUpdate,val);

        segmentTree[index] = max(segmentTree[leftIndex], segmentTree[rightIndex]);

    }
    public:    
    Segment(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        segmentTree.resize(4*n);
        buildSegment(1,0,n-1);
    }
    int getMax(int left, int right){
        return getMaxFromSegment(1,0,n-1,left,right);
    }
    void update(int index, int val){
        updateSegment(1,0,n-1,index,val);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int maxiEle = *max_element(nums.begin(),nums.end());
        vector<int> arr(maxiEle+k+4);
        Segment obj(arr);
        int ans = 0;
        for(int i = n-1; i>=0; i--){
            int val = obj.getMax(nums[i]+1,nums[i]+k);
            obj.update(nums[i],val+1);
            ans = max(ans,val+1);
        }
        return ans;
    }
};