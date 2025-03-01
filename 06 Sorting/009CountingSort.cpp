#include<bits/stdc++.h>
using namespace std;

// GFG - Counting Sort

class Solution{
    public: 
    vector<int> countingSort(vector<int> &arr){
        int n = arr.size();
        int maxi = *max_element(arr.begin(),arr.end());
        int mini = *min_element(arr.begin(),arr.end());
        int range = maxi-mini+1;
        vector<int> count(range);

        for(int i = 0; i<n; i++){
            count[arr[i]-mini]++;
        }

        for(int i = 1; i<range; i++){
            count[i]+=count[i-1];
        }

        vector<int> ans(n);
        for(int i = n-1; i>=0; i--){
            ans[count[arr[i]-mini]-1] = arr[i];
            count[arr[i]-mini]--;
        }

        return ans;
    }
};