#include<bits/stdc++.h>
using namespace std;

// GFG - Kadane's Algorithms
// LeetCode - 53
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long ans = INT_MIN;
        long long sum = 0;
        for(int i = 0; i<n; i++){
            if(sum<0)
                sum = 0;
            sum+=arr[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};



// GFG - Save Your Life

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
        unordered_map<char,int> values;
        for(char i = 'a'; i<='z'; i++)
            values[i] = i;
        for(char i = 'A'; i<='Z'; i++)
            values[i] = i;
        for(int i = 0; i<n; i++){
            values[x[i]] = b[i];
        }
        int maxi = INT_MIN;
        int sum = 0;
        int start = 0;
        int end = 0;
        int s = 0;
        for(int i = 0; i<w.size(); i++){
            sum+=values[w[i]];
            if(sum>maxi){
                maxi = sum;
                end = i;
                start = s;
            }
            if(sum < 0){
                sum = 0;
                s = i+1;
            }
        }
        return w.substr(start,end-start+1);
      }
};

// GFG - Maximum difference of zeros and ones in binary string

class Solution{
public:	
	int maxSubstring(string S){
	    int n = S.size();
	    int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(S[i]=='1')
                sum-=1;
            else 
                sum+=1;
            ans = max(ans, sum);
            if(sum<0)
                sum = 0;
        }
        return ans;
	}
};


// Maximum subarray sum in an array created after repeated concatenation

class Solution{
    int kadans(vector<int> &arr){
        int n = arr.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(sum<0)
                sum = 0;
            sum+=arr[i];
            ans = max(ans, sum);
        }
        return ans;
    }
    int kadansInCycle(vector<int> &arr){
        int n = arr.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i<2*n; i++){
            if(sum<0)
                sum = 0;
            sum+=arr[i%n];
            ans = max(ans, sum);
        }
        return ans;
    }
    int MaximumSum(vector<int> &arr,int k){
        int n = arr.size();
        int maxSum = kadans(arr);
        if(k == 1)
            return maxSum;
        int maxSumInCycle = kadansInCycle(arr);
        return max(maxSum, maxSumInCycle);
    }
};


// LeetCode - 1191
class Solution {
    int mod = 1e9+7;
    long long kadans(vector<int> &arr){
        long long sum = 0;
        long long maxSum = 0;
        for(auto v: arr){
            sum+=v;
            if(sum<0)
                sum = 0;
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
    long long kadans2(vector<int> &arr){
        int n = arr.size();
        long long sum = 0;
        long long maxSum = 0;
        for(int i = 0; i<2*n; i++){
            int v = arr[i%n];
            sum+=v;
            if(sum<0)
                sum = 0;
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long maxSum = kadans(arr);
        if(k==1)
            return maxSum&mod;
        long long maxSum2 = kadans2(arr);
        long long sum = accumulate(arr.begin(), arr.end(),0);
        if(sum<0)
            return maxSum2%mod; 
        return (maxSum2+(k-2)*sum)%mod;
    }
};



// GFG - Max sum subarray by removing at most one element

class Solution{
    public:
    int maxSumSubarray(int A[], int n){
       vector<int> left(n), right(n);
       int sum = 0;
       int maxi = INT_MIN;
       for(int i = 0; i<n; i++){
           sum += A[i];
           left[i] = sum;
           maxi = max(sum, maxi);
           if(sum < 0){
               sum = 0;
           }
       }
       sum = 0;
       for(int i = n-1; i>=0; i--){
           sum += A[i];
           right[i] = sum;
           if(sum < 0){
               sum = 0;
           }
       }
       int ans = maxi;
       for(int i = 1; i<n-1; i++){
           int val = left[i-1] + right[i+1];
           ans = max(ans, val);
       }
       return ans;
    }
};