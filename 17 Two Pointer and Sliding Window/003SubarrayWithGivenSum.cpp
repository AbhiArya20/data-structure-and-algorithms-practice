#include<bits/stdc++.h>
using namespace std;

// GFG - Subarray With Given Sum 

class Solution{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s){
        long long sum = 0;
        int j = 0;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            if(sum==s)
                return {j+1,i+1};
            while(j<i && sum>s){
                sum -= arr[j];
                j++;
                if(sum==s)
                    return {j+1,i+1};
            }
        }
        return {-1};
    }
};